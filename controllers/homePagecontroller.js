



module.exports.homePage=function (req, res) {
	console.log(req.session.user);
	console.log();
	var flag = false; 
	if(req.session.user!= null){
		flag=true;
	}
	console.log(flag);
	
	res.render('homePage.ejs',{session:flag,username:req.session.user});
//	res.sendFile(__dirname + '/public' + '/index.html');
}