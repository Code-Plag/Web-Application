const express = require('express');
const paymentController = require('../controllers/paymentController.js');

router = express.Router();

router
    .get('/paymentpage', paymentController.paymentPage)
    .post('/orders', paymentController.order)
    .post('/capture/:paymentId', paymentController.paymentCapture);

module.exports = router;
