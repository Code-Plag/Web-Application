



module.exports.homePage=function (req, res) {
	console.log(req.sessionID);

	res.sendFile(__dirname + '/public' + '/index.html');
}