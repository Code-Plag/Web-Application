const express = require('express');
const forgetPasswordController = require('../controllers/forgetPasswordController');

router = express.Router();

router.route('/').get(forgetPasswordController.forgotPasswordPage).post(forgetPasswordController.resetMail);

module.exports = router;
