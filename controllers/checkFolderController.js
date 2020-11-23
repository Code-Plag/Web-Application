var mysql = require('mysql');
var Config = require('../config');
const fs = require('fs');
var Promise = require("bluebird");

Promise.promisifyAll(require("mysql/lib/Connection").prototype);
Promise.promisifyAll(require("mysql/lib/Pool").prototype);
module.exports.checkfolder=  function (req,res) {
    const Connection = mysql.createConnection(config);
    var email = req.session.user;
    var folderName = req.body.foldername;
   // console.log(folderName,email)
    var data = [email,folderName];
    Connection.connect();
    Connection.query(
		'select * from ComparisonHistory where email = ? and folderName =?',
		data,
		(err, results) => {
           
			if (err) {
				console.log(err);
				reject(err);
			}
			else if(results[0]==undefined||results[0]==null){
           //     console.log('no folder found',results);
                res.json({value: true});
            }
            else{
             //   console.log(' folder found');
                res.json({value: false});
            }
		},
	);
        Connection.end();
}
module.exports.check_status=  function (req,res) {
    //console.log('inside  check status')
    const Connection = mysql.createConnection(config);
    var email = req.session.user;
    var folderName = req.body.foldername;
   // console.log(folderName,email)
    var data = [email,'pending'];
    Connection.connect();
    Connection.query(
		'select count(*) as count from ComparisonHistory where email = ? and status =  ?',
		data,
		(err, results) => {
           
			if (err) {
				console.log(err);
				reject(err);
			}
			
            else{
                //console.log(results);
                res.json(results);
            }
            Connection.end();
		});
    

}