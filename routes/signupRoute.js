const express = require('express');

const signupController = require('../controllers/signupController.js');

router = express.Router();

router.route('/').get(signupController.getSingupPage).post(signupController.register);

module.exports = router;
