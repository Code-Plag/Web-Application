var uniqid = require('uniqid');
const bcrypt = require('bcrypt');
var config = require('../config');
const e = require('express');
var mysql = require('mysql');
module.exports.registerViagoogle = function (profile) {
	return new Promise(function (resolve, reject) {
		const connection = mysql.createConnection(config);
		console.log(profile);
		var today = new Date();
		var googleuser = {
			userid: profile.id,
			fullname: profile.displayName,
			email: profile.emails[0].value,
			provider: profile.provider,
			created_at: today,
			updated_at: today,
		};

		connection.query('INSERT INTO googleuser SET ?', googleuser, function (
			error,
			newUser,
		) {
			if (error) {
				return reject(error);
			} else {
				console.log(newUser);
				console.log('hello hiii');

				return resolve(newUser);
			}
		});
	});
	connection.end();
};
