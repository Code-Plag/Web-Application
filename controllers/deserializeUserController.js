const { deserializeUser } = require('passport');
var mysql = require('mysql');
const Config = require('../config');

module.exports.deserializeUserCallback = (user, done) => {
   // console.log('Inside deserializeUser callback');
    console.log(`The user id passport saved in the session file store is: ${user.userid}`);
    if(user.userid){
        let table = user.registerCode ? 'googleuser' : 'users';
       // console.log(table);
    
         const Connection = mysql.createConnection(Config);
        Connection.connect();
        Connection.query('SELECT * FROM ?? WHERE userid = ?', [table, user.userid], (err, results, fields) => {
        if (err) {
            console.log(err.message);
        }
       // console.log(results[0].userid);
        const User = results[0].userid == user.userid ? results[0] : false;
        Connection.end();
       return done(null, User);
    });
   
    }
    
    return done(null,false);
};
