var mysql = require('mysql');
var Config = require('../config');
var jwt = require('jsonwebtoken');
const path = require('path');

module.exports.resetpasswordemailverify = function (req, res) {
    // TODO: Fetch user from database using
    try {
        userid = req.params.id;
        req.session.tempUserid = userid;
        token = req.params.token;
        req.session.tempToken = token;
        console.log(userid);
        console.log(token);
        let Connection = mysql.createConnection(Config);
        let sql = `select * from users WHERE userid= ?`;

        Connection.connect();
        Connection.query(sql, userid, function (err, results) {
            // var secret = user.password + ‘-' + user.created.getTime();

            console.log(results);
            var secret = results[0].password + '-' + results[0].updated_at;

            var decoded = jwt.verify(token, secret);
            res.render('update_password.ejs');
            Connection.end();
            return;

            // TODO: Gracefully handle decoding issues.
            // Create form to reset password.
        });
    } catch (err) {
        console.log('token is not valid some error in data');
    }
};
