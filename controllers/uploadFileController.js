const tempDirectory = require('./tempDirectory.js');

module.exports.fileUpload = function (req, res) {
    tempDirectory.createtempdir(req, res);

    const current = req.session.dir;
    req.session.executepath = current;
};
