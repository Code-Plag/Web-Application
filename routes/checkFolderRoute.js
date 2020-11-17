const express = require('express');
const checkFolderController = require('../controllers/checkFolderController');

router = express.Router();

router.route('/').post(checkFolderController.checkfolder);

module.exports = router;
