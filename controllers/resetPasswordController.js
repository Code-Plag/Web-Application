const VerifyPasswordLink = require('../models/verifyResetPasswordLink.js');
const resettingPassword = require('../models/resettingPassword.js');

exports.resetPasswordmail = function (req, res) {
    VerifyPasswordLink.resetpasswordemailverify(req, res);
};

exports.resetPassword = function (req, res) {
    resettingPassword.setResetPassword(req, res);
};
