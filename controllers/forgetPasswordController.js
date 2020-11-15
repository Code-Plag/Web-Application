const path = require('path');

const resetPasswordEmail = require('./resetPasswordEmail.js');

exports.forgotPasswordPage = function (req, res) {
    res.sendFile(path.resolve(__dirname + '/../public/ForgotPassword.html'));
};

exports.resetMail = function (req, res) {
    resetPasswordEmail.passwordreset(req, res);
};
