const passport = require('passport');
const userDirectory = require('./userDirectory.js');
const path = require('path');
exports.getloginPage = function (req, res) {
    res.sendFile(path.resolve(__dirname + '/../public' + '/login.html'));
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
