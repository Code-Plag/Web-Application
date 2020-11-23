const crypto = require('crypto');
var register = require('./register');
var sendMail = require('./sendmail.js');
var path = require('path');
var session_check_controller = require('../controllers/session_check_controller');
module.exports.singing_up = function (req, res) {
    let activeToken = crypto.randomBytes(17).toString('hex');
    let mailid = req.body.email;
  
    let link = 'http://' + req.get('host') + '/api/v1/verify?id=' + activeToken + '&email=' + mailid;
    let activeExpires = Date.now() + 1 * 3600 * 1000;

    let mailOption = {
        from: process.env.EMAIL, // sender address
        to: mailid, // list of receivers
        subject: 'Please confirm your Email account', // Subject line
        html:
            'Hello, <br> Please Click on the link to verify your email.<br> click <a href="' +
            link +
            '"> here </a> to verify.',
    };

    async function Registerandsendmail() {
            const result1 = await register.register(req, res, activeToken, activeExpires);
           

            const result2 = await sendMail.wrapedSendmail(mailOption);
            var combineresult = { result1, result2 };
            return combineresult;
        
    }

    Registerandsendmail()
        .then((result) => {
         //   console.log(result);
            res.render('emailsent.ejs');
        })
        .catch((err) => {
            console.log(err);
            if(err.errno==1062)
            res.render('signup.ejs',{session:session_check_controller.check_session(req,res)
                                    ,flag:false,
                                    status:'failure',
                                    msg:'email already exists try loggin in  with another email '})
        });
};
