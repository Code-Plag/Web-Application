const path = require('path');

const resetPasswordEmail = require('../models/resetPasswordEmail.js');
const session_check_controller = require('./session_check_controller.js');

exports.forgotPasswordPage = function (req, res) {
   // res.sendFile(path.resolve(__dirname + '/../public/ForgotPassword.html'));
    if(session_check_controller.check_session(req,res)){
       // console.log("inside checker")
        res.render('homePage.ejs',{session:session_check_controller.check_session(req,res),username:req.session.user});
    }
    else{
   // console.log("outiside checker")
    res.render('forgotpassword.ejs',{session:session_check_controller.check_session(req,res)});
}
};

exports.resetMail = function (req, res) {
    resetPasswordEmail.passwordreset(req, res);
};
