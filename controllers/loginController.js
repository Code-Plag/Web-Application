const passport = require('passport');
const userDirectory = require('./userDirectory.js');
const session_check_controller = require('./session_check_controller.js');
const path = require('path');
exports.getloginPage = function (req, res) {
    //res.sendFile(path.resolve(__dirname + '/../public' + '/login.html'));
    console.log(session_check_controller.check_session(req,res))
    if(session_check_controller.check_session(req,res)){
        console.log("inside checker")
        res.render('homePage.ejs',{session:session_check_controller.check_session(req,res),username:req.session.user});
    }
    else{
    console.log("outiside checker")
    res.render('login.ejs',{session:session_check_controller.check_session(req,res)});
}
};

exports.userlogin = function (req, res) {
    //Authenticate.authenticate(req, res);

    console.log('Inside POST /login callback');
    console.log(req.body.email);
    req.session.user = req.body.email;
    passport.authenticate('local', (err, user, info) => {
        req.login(user, (err) => {
            userDirectory.CreateUserDirectory(req, res);

            res.redirect('/api/v1');
        });
    })(req, res);
};
