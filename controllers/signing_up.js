const crypto = require('crypto');
var register = require('./register');
var sendMail = require('./sendmail.js');
var path = require('path');
var session_check_controller = require('./session_check_controller');
module.exports.singing_up = function (req, res) {
    let activeToken = crypto.randomBytes(17).toString('hex');
    let mailid = req.body.email;
    let link = 'http://' + req.get('host') + '/api/v1/verify?id=' + activeToken + '&email=' + mailid;
    let activeExpires = Date.now() + 1 * 3600 * 1000;

    let mailOption = {
        from: 'laxnp9@gmail.com', // sender address
        to: mailid, // list of receivers
        subject: 'Please confirm your Email account', // Subject line
        html:
            'Hello, <br> Please Click on the link to verify your email.<br> click <a href="' +
            link +
            '"> here </a> to verify.',
    };

    async function Registerandsendmail() {
        const result1 = await register.register(req, res, activeToken, activeExpires);
        console.log(result1, 'heyyyyyy');

        const result2 = await sendMail.wrapedSendmail(mailOption);
        console.log(result2, 'send mail details...................');
        var combineresult = { result1, result2 };
        return combineresult;
    }

    Registerandsendmail()
        .then((result) => {
            console.log(result);
            res.render('emailsent.ejs');
        })
        .catch((err) => {
            console.log(err);
        });
};
