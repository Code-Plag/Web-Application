const express = require('express');
const app = express();
var jwt = require('jsonwebtoken');

module.exports.authenticateJWT = (req, res, next) => {
	//console.log(req.cookies);

	if (req.cookies.token) {
		var token = req.cookies.token;
		const accessTokenSecret = '12345abc';
		jwt.verify(token, accessTokenSecret, (err, user) => {
			if (err) {
				return res.sendStatus(403);
			}
			//console.log(user);
			req.user = user;
			next();
		});
	} else {
		res.sendStatus(401);
	}
};
