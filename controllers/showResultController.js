const putFolderName = require('./PutFolderName.js');
const loadFunction = require('./loaderFunction.js');

exports.fetchResult = async (req, res) => {
    await putFolderName.CompFolder(req, res);
    res.redirect('/api/v1/showResult');
};

exports.showresult = function (req, res) {
    loadFunction.loader(req, res);
};
