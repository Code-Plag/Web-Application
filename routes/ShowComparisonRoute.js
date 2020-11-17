const express = require('express');
const ShowComparisonController = require('../controllers/ShowComparisonController');

router = express.Router();

router.route('/').get(ShowComparisonController.loadJson);

module.exports = router;
