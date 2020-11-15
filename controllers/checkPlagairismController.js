const executerEngine = require('./executerEngine');

module.exports.checkplag = function (req, res) {
    executerEngine.runPlagEngine(req, res);
};
