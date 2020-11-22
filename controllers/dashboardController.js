const loadFunction = require('./loaderFunction.js');
module.exports.getdashboard = async () => {
    await loadFunction.loader(req, res);

    if (session_check_controller.check_session(req, res)) {
        console.log('inside checker');
        res.render('dashboard.ejs', {
            session: session_check_controller.check_session(req, res),
            username: req.session.user,
            results: results,
            details: details,
        });
    } else {
        console.log('outiside checker');
        res.render('homePage.ejs', {
            session: session_check_controller.check_session(req, res),
            username: req.session.user,
        });
    }
};
