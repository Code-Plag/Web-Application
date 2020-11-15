const fs = require('fs');
const mysql = require('mysql');
const Config = require('../config');
const replacetemplate = (temp, result) => {
	let output = temp.replace(/{%comp_name%}/g, result.folderName);
	output = output.replace(/{%no_of_files%}/g, result.fileCount);
	output = output.replace(/{%Check_date%}/g, result.ComparisonDate);

	return output;
};
const template = fs.readFileSync(
	`${__dirname}/../public/showHistory.html`,
	'utf-8',
);
const index = fs.readFileSync(
	`${__dirname}/../public/loadHistory.html`,
	'utf-8',
);

module.exports.loader = function (req, res) {
	console.log('1st');
	const email = req.session.email;
	let Connection = mysql.createConnection(Config);
	Connection.query(
		'SELECT * FROM ComparisonHistory WHERE email = ?',
		[email],
		function (error, results, fields) {
			if (error) {
				res.json({
					status: false,
					message: 'there are some error with query',
				});
			} else {
				console.log(results);

				const cardstml = results.map((el) => replacetemplate(template, el));
				output = index.replace('{%FOLDER_CARDS%}', cardstml);
				console.log(output);

				res.send(output);
			}
		},
	);
};
