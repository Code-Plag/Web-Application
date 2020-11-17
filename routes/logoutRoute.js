const express = require('express');
const logoutController = require('../controllers/logoutController.js');

router = express.Router();

router
    .route('/')
    .get(logoutController.logoutpage);

module.exports = router;
