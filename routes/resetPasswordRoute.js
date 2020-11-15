const express = require('express');

const resetPasswordController = require('../controllers/resetPasswordController.js');

router = express.Router();

router.get('/:id/:token', resetPasswordController.resetPasswordmail);

router.route('/').post(resetPasswordController.resetPassword);

module.exports = router;
