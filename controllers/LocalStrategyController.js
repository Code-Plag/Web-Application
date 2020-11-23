const Authenticate = require('../models/authenticate');

module.exports.LocalStrategyCallback = async (email, password, done) => {
    try {
       // console.log('Inside local strategy callback');

        const result = await Authenticate.authenticate1(email, password);//
        const user = result;

        return done(null, user);
    } catch (err) {
        console.log('authentication failed in local strategy call back',err.message);
        return done(null, false);
    }
};
