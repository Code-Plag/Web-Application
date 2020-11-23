const Signing_Up = require('../models/signing_up.js');
const path = require('path');
const session_check_controller = require('./session_check_controller.js');
exports.getSingupPage = function (req, res) {
    //res.sendFile(path.resolve(__dirname + '/../public' + '/signup.html'));
    if(session_check_controller.check_session(req,res)){
       // console.log("inside checker")
        res.render('homePage.ejs',{session:session_check_controller.check_session(req,res),username:req.session.user});
    }
    else{
   // console.log("outiside checker")
    res.render('signup.ejs',{session:session_check_controller.check_session(req,res),flag:true});
}
};

exports.register = function (req, res) {
    Signing_Up.singing_up(req, res);
};
