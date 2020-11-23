const fs = require('fs');
const mysql = require('mysql');
const Config = require('../config');


var Promise = require("bluebird");

Promise.promisifyAll(require("mysql/lib/Connection").prototype);
Promise.promisifyAll(require("mysql/lib/Pool").prototype);



module.exports.loader =  async function (req, res) {
//	console.log('1st');
	var obj=[];
	const email = req.session.user;
//	console.log(email);
	try {
		let Connection = mysql.createConnection(Config);
	Connection.connectAsync();

	var results = await Connection.queryAsync(
		'SELECT compid,email,folderName,fileCount,ComparisonDate,language,status FROM ComparisonHistory WHERE email = ? order by comparisonTime ',[email]);
		Connection.endAsync();
	} catch (error) {
		console.log('error here');
		console.log(error);
	}
	//console.log('from outside loader',results);
	return results;
};
