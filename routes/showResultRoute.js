const express = require('express');
const showResultController = require('../controllers/showResultController.js');

router = express.Router();

router.route('/').get(showResultController.showresult).post(showResultController.fetchResult);

module.exports = router;
