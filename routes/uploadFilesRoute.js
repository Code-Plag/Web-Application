const express = require('express');

const uploadFileController = require('../controllers/uploadFileController.js');

router = express.Router();

router.route('/').get(uploadFileController.getfile_upload).post(uploadFileController.fileUpload);

module.exports = router;
