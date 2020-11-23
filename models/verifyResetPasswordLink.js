var mysql = require('mysql');
var Config = require('../config');
var jwt = require('jsonwebtoken');
const path = require('path');

module.exports.resetpasswordemailverify = function (req, res) {
    // TODO: Fetch user from database using
    userid = req.params.id;
    req.session.tempUserid = userid;
    token = req.params.token;
    req.session.tempToken = token;
    console.log(userid);
    console.log(token);
    let Connection = mysql.createConnection(Config);
    let sql = `select * from users WHERE userid= ?`;
    let data = [userid];
    Connection.connect();
    Connection.query(sql, data, function (err, results) {
        // var secret = user.password + ‘-' + user.created.getTime();
        var secret = results[0].password + '-' + results[0].updated_at;

        try {
            var decoded = jwt.verify(token, secret);
        //    console.log('hiii');
        //    console.log(decoded);
        } catch (err) {
            console.log('token is not valid some error in data');
            res.send('your link time has expired ');
        }
        // TODO: Gracefully handle decoding issues.
        // Create form to reset password.

        res.render('update_password.ejs');
        Connection.end();
    });
};
