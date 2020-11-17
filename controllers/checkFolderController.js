var mysql = require('mysql');
var Config = require('../config');
const fs = require('fs');
var Promise = require("bluebird");
// Note that the library's classes are not properties of the main export
// so we require and promisifyAll them manually
Promise.promisifyAll(require("mysql/lib/Connection").prototype);
Promise.promisifyAll(require("mysql/lib/Pool").prototype);
module.exports.checkfolder=  function (req,res) {
    const Connection = mysql.createConnection(config);
    var email = req.session.email;
    var folderName = req.body.foldername;
    var data = [email,folderName]
    Connection.query(
		'select * from ComparisonHistory where email = ? and folderName =?',
		data,
		(err, results) => {
           
			if (err) {
				console.log(err);
				reject(err);
			}
			else if(!results){

                res.json({value: false});
            }
            else{
                res.json({value: true});
            }
		},
	);

}