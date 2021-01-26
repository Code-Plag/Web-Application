const express = require('express');
const aboutUsController = require('../controllers/aboutUsController');

router = express.Router();

router.route('/').get(aboutUsController.get_about_us_page);

module.exports = router;
