const express = require('express');
const app = express();
var mysql = require('mysql');
var Config = require('../config');

module.exports.authenticateviagoogle = function (profile) {
	return new Promise((resolve, reject) => {
		console.log(profile.id);

		let userid = profile.id;

		const Connection = mysql.createConnection(Config);
		Connection.connect();
		Connection.query(
			'SELECT * FROM googleuser WHERE userid = ?',
			[userid],
			(err, currentUser, fields) => {
				if (err) {
					console.log("message:'there are some error with query'");
					reject("message:'there are some error with query");
				} else {
					console.log('result is sucessfully fetched');
					resolve(currentUser[0]);
				}
				Connection.end();
			},
		);
	});
};
