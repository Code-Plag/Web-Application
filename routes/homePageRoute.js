var express = require('express')
const homePagecontroller = require('../controllers/homePagecontroller')

var router = express.Router()

// middleware that is specific to this router
/* router.use(function timeLog (req, res, next) {
  console.log('Time: ', Date.now())
  next()
}) */
// define the home page route

router.route('/').get(homePagecontroller.homePage);

module.exports = router