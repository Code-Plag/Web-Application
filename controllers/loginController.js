const passport = require('passport');
const userDirectory = require('../models/userDirectory.js');
const session_check_controller = require('./session_check_controller.js');
const path = require('path');
exports.getloginPage = function (req, res) {
    //res.sendFile(path.resolve(__dirname + '/../public' + '/login.html'));
   // console.log(session_check_controller.check_session(req,res))
    if(session_check_controller.check_session(req,res)){
    //    console.log("inside checker")
        res.render('homePage.ejs',{session:session_check_controller.check_session(req,res),username:req.session.user});
    }
    else{
    //console.log("outiside checker");
    res.render('login.ejs',{session:session_check_controller.check_session(req,res), flag:true});
}
};

exports.userlogin = function (req, res) {
    //Authenticate.authenticate(req, res);

    //console.log('Inside POST /login callback');
  //  console.log(req.body.email);
    req.session.user = req.body.email;
    req.session.email = req.body.email;
    passport.authenticate('local', (err, user, info) => {//done(null,false)
 //       console.log('inside callback of passport authenticate',user);
        req.login(user, (err) => {
            if(user){
                res.redirect('/api/v1');
            }
            else if(!user){
                req.session.destroy(function(err) {
   //                 console.log("session destroyed");

                    res.render('login.ejs',{session:false,
                        flag:false,
                        status:'failure',
                        msg : 'username or password is not valid'});
                    
                  });
                
            }
           // userDirectory.CreateUserDirectory(req, res);

            
        });

        
    })(req, res);
};
