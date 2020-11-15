const executerEngine = require('./executerEngine');

module.exports.checkplag = function (req, res) {
    console.log("inside check plag controller");
    executerEngine.runPlagEngine(req, res);
};
