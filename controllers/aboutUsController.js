
const session_check_controller = require('./session_check_controller.js');
module.exports.get_about_us_page=(req,res)=>{
    if (session_check_controller.check_session(req, res)) {
        // console.log('inside checker');
         res.render('contact.ejs', {
             session: session_check_controller.check_session(req, res),
             username: req.session.user,
             results: results,
            
         });
     } else {
       //  console.log('outiside checker');
         res.render('contact.ejs', {
             session: session_check_controller.check_session(req, res),
             username: req.session.user,
         });
     }
    }
    