const express = require('express');
const checkPlagairismController = require('../controllers/checkPlagairismController');

router = express.Router();

router.route('/').get(checkPlagairismController.checkplag);

module.exports = router;
