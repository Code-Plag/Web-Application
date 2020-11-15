const express = require('express');

const emailVerificationController = require('../controllers/emailVerificationController.js');

router = express.Router();

router.route('/').get(emailVerificationController.emailVerification);

module.exports = router;
