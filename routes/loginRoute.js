const express = require('express');
const loginController = require('../controllers/loginController');

router = express.Router();

router.route('/').get(loginController.getloginPage).post(loginController.userlogin);

module.exports = router;
