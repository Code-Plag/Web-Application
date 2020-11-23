var mysql = require('mysql');
var config = require('../config');
var Send_Mail = require('./sendmail.js');
const bcrypt = require('bcrypt');
const path = require('path');

module.exports.setResetPassword = function (req, res) {
   

    var userid = req.session.tempUserid;
    var token = req.session.tempToken;
   // console.log(userid);
    //console.log(token);
    let Connection = mysql.createConnection(config);
    let sql = `select * from users WHERE userid = "${userid}"  `;
//    console.log(sql);
    Connection.connect();
    Connection.query(sql, (err, results, fields) => {
        // var secret = user.password + ‘-' + user.created.getTime();
  //      console.log(results[0], 'result is here');
        //  var secret = results[0].password + '-' + results[0].updated_at;
        var emailAddress = results[0].email;

     
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
                 //   console.log(result);

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
                        Connection.end();
                    return res.render('reset_password_success.ejs');
                });
               
            });
        } else {
            Connection.end();
            return res.status(422).send({
                message: 'Passwords do not match',
            });
        }
    });
};
