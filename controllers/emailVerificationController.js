const verifyUser = require('../models/verifyUser.js');

module.exports.emailVerification = function (req, res) {
    verifyUser.verify(req, res);
};
