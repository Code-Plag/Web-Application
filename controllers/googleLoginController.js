const userDirectory = require('../models/userDirectory.js');

module.exports.loginCallback = (req, res) => {
   // console.log('i am not authenticated');
    userDirectory.CreateUserDirectory(req, res);

    return res.status(200).redirect('/');
};
