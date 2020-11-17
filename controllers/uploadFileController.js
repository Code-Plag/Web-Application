const tempDirectory = require('./tempDirectory.js');
const userDirectory = require('./userDirectory.js');
const session_check_controller = require('./session_check_controller.js');
module.exports.fileUpload = function (req, res) {
    userDirectory.CreateUserDirectory(req, res);
    tempDirectory.createtempdir(req, res);
    
    const current = req.session.dir;
    req.session.executepath = current;
};
module.exports.getfile_upload = function (req, res) {
    if(session_check_controller.check_session(req,res)){
        console.log("inside checker")
        res.render('upload_files.ejs',{session:session_check_controller.check_session(req,res),username:req.session.user});
    }
    else{
        console.log("outiside checker")
        res.render('homePage.ejs',{session:session_check_controller.check_session(req,res),username:req.session.user});
    }
};
