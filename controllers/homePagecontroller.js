



module.exports.homePage=function (req, res) {
	console.log(req.sessionID);
	console.log();

	res.render('home_page.ejs',{username:req.session.user});
//	res.sendFile(__dirname + '/public' + '/index.html');
}