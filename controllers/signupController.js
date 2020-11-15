const Signing_Up = require('./signing_up.js');
const path = require('path');

exports.getSingupPage = function (req, res) {
    res.sendFile(path.resolve(__dirname + '/../public' + '/signup.html'));
};

exports.register = function (req, res) {
    Signing_Up.singing_up(req, res);
};
