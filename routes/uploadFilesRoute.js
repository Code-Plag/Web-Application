const express = require('express');

const uploadFileController = require('../controllers/uploadFileController.js');

router = express.Router();

router.route('/').post(uploadFileController.fileUpload);

module.exports = router;
