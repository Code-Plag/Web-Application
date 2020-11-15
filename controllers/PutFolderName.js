var mysql = require('mysql');
var Config = require('../config');
const fs = require('fs');

/*  fs.readdirSync(req.session.JsonResult).forEach(function (file) {
        file.replace(/\.json$/, '') = require(dir + file);
    }); */

module.exports.CompFolder = (req, res) => {

	return new Promise((resolve,reject)=>{


	
	const FolderName = req.body.CompFolder;
	today = new Date();
	var date =
		today.getFullYear() + '-' + (today.getMonth() + 1) + '-' + today.getDate();
	let file1 = 'match_data.json';
	let file2 = 'file_data.json';

	const Connection = mysql.createConnection(config);
	email = req.session.email;
	const data = {
		email: email,
		folderName: req.body.CompareFolder,
		fileCount: req.session.fileCount,
		MatchedDataJson: JSON.stringify(require(req.session.JsonResult + file1)),
		fileDataJson: JSON.stringify(require(req.session.JsonResult + file2)),
		ComparisonDate: date,
	};

	Connection.query(
		'INSERT INTO ComparisonHistory SET ?',
		data,
		(err, results) => {
			if (err) {
				reject(err);
			}
			console.log(results)
			resolve(results)
		},
	);
	Connection.end();

})
};
