var mysql = require('mysql');
var Config = require('../config');
var jwt = require('jsonwebtoken');
var Send_Mail = require('./sendmail.js');
const path = require('path');

module.exports.passwordreset = function (req, res) {
    if (req.body.email !== undefined) {
        var emailAddress = req.body.email;

        let Connection = mysql.createConnection(Config);
        let sql = `select * from users WHERE email= ?`;
        let data = [emailAddress];

        Connection.query(sql, data, function (err, results) {
            if (err) throw err;
            console.log(results);

            var payload = {
                id: results[0].userid, // User ID from database
                email: emailAddress,
            };

            // var secret = user.password + ‘-' + user.created.getTime();
            var secret = results[0].password + '-' + results[0].updated_at;

            var token = jwt.sign(payload, secret);
            console.log(token);
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
            async function resetpasswordmail() {
                const result = await Send_Mail.wrapedSendmail(mailOption);
            }
            resetpasswordmail()
                .then((result) => {
                    console.log(result);
                    res.render('resetpassword.ejs');
                })
                .catch((err) => {
                    console.log(error);
                });
        });
    } else {
        res.send('Email address is missing.');
    }
};
