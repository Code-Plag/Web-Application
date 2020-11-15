const verifyUser = require('./verifyUser.js');

module.exports.emailVerification = function (req, res) {
    verifyUser.verify(req, res);
};
