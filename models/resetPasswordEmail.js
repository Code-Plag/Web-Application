var mysql = require('mysql');
var Config = require('../config');
var jwt = require('jsonwebtoken');
var Send_Mail = require('./sendmail.js');
const path = require('path');

module.exports.passwordreset = async function (req, res) {
    if (req.body.email !== undefined) {
        console.log(req.body.email);
        var emailAddress = req.body.email;

        let Connection = mysql.createConnection(Config);
        let sql = `select * from users WHERE email= ?`;
        let data = [emailAddress];
        Connection.connect();
        Connection.query(sql, data, async function (err, results) {
            if (err) throw err;
            // console.log(results);

            var payload = {
                id: results[0].userid, // User ID from database
                email: emailAddress,
            };

            // var secret = user.password + ‘-' + user.created.getTime();
            var secret = results[0].password + '-' + results[0].updated_at;

            var token = jwt.sign(payload, secret);
            // console.log(token);
            let link = 'http://' + req.get('host') + '/api/v1/resetpassword/' + payload.id + '/' + token;
            let mailOption = {
                from: process.env.EMAIL, // sender address
                to: emailAddress, // list of receivers
                subject: 'password reset link', // Subject line
                html:
                    'Hello, <br> Please Click on link below to reset password.<br> click <a href="' +
                    link +
                    '"> here </a> to verify.',
            };

            async function resetpasswordmail(mailOption) {
                const result = await Send_Mail.wrapedSendmail(mailOption);
            }
<<<<<<< HEAD
            resetpasswordmail()
                .then((result) => {
                   // console.log(result);
                    Connection.end();
                    res.render('resetpassword.ejs');
                })
                .catch((err) => {
                    console.log(error);
                });
               
=======

            try {
                let result = await resetpasswordmail(mailOption);

                res.redirect('/api/v1/getConfirmationPage');
                console.log(result);
            } catch (err) {
                console.log(err);
            }
            Connection.end();
>>>>>>> d027a4c9ac3eae11ce199861fe239c2d7e9e8d0a
        });
    } else {
        res.send('Email address is missing.');
    }
};
