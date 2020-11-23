const express = require('express');
const checkFolderController = require('../controllers/checkFolderController');

router = express.Router();

router.route('/').get(checkFolderController.check_status);

module.exports = router;
