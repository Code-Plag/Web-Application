var mysql = require('mysql');
var config = require('../config');
var Send_Mail = require('./sendmail.js');
const bcrypt = require('bcrypt');
const path = require('path');

module.exports.setResetPassword = function (req, res) {
    // TODO: Fetch user from database using
    // req.body.id

    var userid = req.session.tempUserid;
    var token = req.session.tempToken;
    console.log(userid);
    console.log(token);
    let Connection = mysql.createConnection(config);
    let sql = `select * from users WHERE userid = "${userid}"  `;
    console.log(sql);

    Connection.query(sql, (err, results, fields) => {
        // var secret = user.password + ‘-' + user.created.getTime();
        console.log(results[0], 'result is here');
        //  var secret = results[0].password + '-' + results[0].updated_at;
        var emailAddress = results[0].email;

        /*  try {
      console.log('hii');
      var decoded = jwt.verify(token, secret);
      console.log('hii');
      console.log(decoded);
      console.log('hey');
    } catch(err) {
      console.log('token is not valid some error in data')
        res.send('your link time has expired ');
  
    } */

        if (req.body.newpassword === req.body.verifypassword) {
            const saltRounds = 10;

            bcrypt.hash(req.body.newpassword, saltRounds, function (err, hash) {
                if (err) {
                    throw err;
                }
                let today = new Date();
                var sql = 'UPDATE users set password = ? ,updated_at = ?  WHERE userid = ?';
                let data = [hash, today, userid];
                Connection.query(sql, data, function (err, result) {
                    console.log(result);

                    let mailOption = {
                        from: process.env.EMAIL, // sender address
                        to: emailAddress, // list of receivers
                        subject: 'Password Reset Confirmation', // Subject line
                        html: 'Hello, <br> your password is sucessfully updated.',
                    };

                    async function resetpasswordmail() {
                        const result = await Send_Mail.wrapedSendmail(mailOption);
                    }

                    resetpasswordmail()
                        .then((result) => {
                            console.log(result);
                        })
                        .catch((err) => {
                            console.log('some error has occured');
                            throw err;
                        });

                    return res.render('reset_password_success.ejs');
                });
            });
        } else {
            return res.status(422).send({
                message: 'Passwords do not match',
            });
        }
    });
};
