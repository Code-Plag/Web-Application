const fs = require('fs');
const mysql = require('mysql');
const Config = require('../config');
const replacetemplate = (temp, result) => {
	let output = temp.replace(/{%comp_name%}/g, result.folderName);
	output = output.replace(/{%no_of_files%}/g, result.fileCount);
	output = output.replace(/{%Check_date%}/g, result.ComparisonDate);

	return output;
};
var Promise = require("bluebird");
// Note that the library's classes are not properties of the main export
// so we require and promisifyAll them manually
Promise.promisifyAll(require("mysql/lib/Connection").prototype);
Promise.promisifyAll(require("mysql/lib/Pool").prototype);

const template = fs.readFileSync(
	`${__dirname}/../public/showHistory.html`,
	'utf-8',
);
const index = fs.readFileSync(
	`${__dirname}/../public/loadHistory.html`,
	'utf-8',
);

module.exports.loader =  async function (req, res) {
	console.log('1st');
	var obj=[];
	const email = req.session.email;
	try {
		let Connection = mysql.createConnection(Config);
	Connection.connect();
	var results = await Connection.queryAsync('SELECT * FROM ComparisonHistory WHERE email = ?',[email]);
	} catch (error) {
		console.log('error here');
		console.log(error);
	}
	
	// Connection.query(
	// 	'SELECT * FROM ComparisonHistory WHERE email = ?',
	// 	[email],
	// 	function (error, results, fields) {
	// 		if (error) {
	// 			console.log(error);
	// 			res.json({
	// 				status: false,
	// 				message: 'there are some error with query',
	// 			});
	// 		} else {
	// 			console.log(results);

	// 			const cardstml = results.map((el) => replacetemplate(template, el));
	// 			output = index.replace('{%FOLDER_CARDS%}', cardstml);
	// 			console.log(output);
	// 			obj = results;
				
	// 		//console.log('from loader',results);
				
	// 		}
	// 	},
	// );

	//console.log('from outside loader',results);
	return results;
};
