const express = require('express');
const passport = require('passport');
const googleLoginController = require('../controllers/googleLoginController.js');

router = express.Router();

router.get(
    '/',
    passport.authenticate('google', {
        scope: [
            'https://www.googleapis.com/auth/userinfo.profile',
            'https://www.googleapis.com/auth/userinfo.email',
        ],
    })
);

router.get(
    '/callback',
    passport.authenticate('google'),
    googleLoginController.loginCallback
);

module.exports = router;
