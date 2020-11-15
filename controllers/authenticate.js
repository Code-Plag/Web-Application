const express = require('express');
const app = express();
var mysql = require('mysql');
var Config = require('../config');
const bcrypt = require('bcrypt');

//var jwt = require('jsonwebtoken');
//var User_Directory = require('./user_directory.js');

module.exports.authenticate1 = function (email, password) {
	return new Promise((resolve, reject) => {
		console.log('hii i am in try block');

		console.log(email);
		console.log(password);

		const Connection = mysql.createConnection(Config);

		Connection.query(
			'SELECT * FROM users WHERE email = ?',
			[email],
			(err, results, fields) => {
				if (err) {
					console.log("message:'there are some error with query'");
					reject("message:'there are some error with query");
				} else if (results.length > 0) {
					bcrypt.compare(password, results[0].password, (err, result) => {
						if (err) {
							console.log('password doesnt match');
							reject('password doesnt match');
						} else if (result == true && results[0].activestatus == true) {
							console.log('result is sucessfully fetched');
							resolve(results[0]);
							//req.session.email = req.body.email;
						} else if (result == true && results[0].activestatus == false) {
							console.log('result is not sucessfully fetched');
							reject('result is not sucessfully fetched');
						} else {
							console.log('Email and password does not match');
							reject('result is not not fetched');
						}
					});
				} else {
					console.log('message: Email does not exits');
					reject('result is not Email fetched');
				}
			},
		);
	});
};
