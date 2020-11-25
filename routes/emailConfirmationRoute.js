const express = require('express');
const emailConfirmation = require('../controllers/emailConfirmationController');

router = express.Router();

router.route('/').get(emailConfirmation.sendPage);

module.exports = router;
