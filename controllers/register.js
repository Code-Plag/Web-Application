var uniqid = require('uniqid');
const bcrypt = require('bcrypt');
var config = require('../config');
const e = require('express');
var mysql = require('mysql');

//console.log(uniqid());

module.exports.register = function (req, res, activeToken, activeExpires) {
	return new Promise(function (resolve, reject) {
		const connection = mysql.createConnection(config);
		console.log(req.body.password);
		console.log(req.body.email);
		console.log(req.body.repassword);
		const myPassword = req.body.password;

		const saltRounds = 10;

		bcrypt.hash(myPassword, saltRounds, function (err, hash) {
			if (err) {
				// throw err;
				return reject(err);
			}

			console.log(`hash created : ${hash}`);
			var today = new Date();
			var users = {
				userid: uniqid(),
				fullname: req.body.fullname,
				email: req.body.email,
				password: hash,
				created_at: today,
				updated_at: today,
				activeToken: activeToken,
				activeExpires: activeExpires,
				activestatus: false,
			};

			connection.query('INSERT INTO users SET ?', users, function (
				error,
				results,
			) {
				if (error) {
					//throw error;
					return reject(error);
					/* res.json({
            status:false,
            message:'there are some error with query'
        }) */
				} else {
					/* res.json({
            status:true,
            data:results,
            message:'user registered sucessfully'
            
        }) */
					console.log('hello result is here');
					// console.log(results);
					return resolve(results);
				}
			});
		});
	});
	connection.end();
};
