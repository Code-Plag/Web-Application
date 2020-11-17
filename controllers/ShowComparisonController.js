var mysql = require('mysql');
var Config = require('../config');
const fs = require('fs');
var Promise = require("bluebird");
var session_check_controller = require('./session_check_controller');
// Note that the library's classes are not properties of the main export
// so we require and promisifyAll them manually
Promise.promisifyAll(require("mysql/lib/Connection").prototype);
Promise.promisifyAll(require("mysql/lib/Pool").prototype);
module.exports.loadJson= async function (req,res) {
    try {
        const Connection = mysql.createConnection(config);
    var compid =  req.query.compid;
    var results = await Connection.queryAsync('select * from ComparisonHistory where compid = ?',compid);     
    if(session_check_controller.check_session(req,res)){
        console.log("inside checker")
        res.render('result.ejs',{session:session_check_controller.check_session(req,res),username:req.session.user,
                                results:results
                                });
    }
    else{
        console.log("outiside checker")
        res.render('login.ejs',{session:session_check_controller.check_session(req,res)});
    }

    } catch (error) {
        console.log(error);
    }
    
}