const express = require('express');
const dashboardController = require('../controllers/dashboardController');

router = express.Router();

router.route('/').get(dashboardController.getdashboard);

module.exports = router;
