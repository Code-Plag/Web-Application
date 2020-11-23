const googleAuthenticate = require('../models/googleAuthenticate.js');
const registerViaGoogle = require('../models/registerViaGoogle.js');

module.exports.GoogleStrategyCallback = async (accessToken, refreshToken, profile, done) => {
    // passport callback function
    //check if user already exists in our db with the given profile ID
    try {
        console.log('Inside strategy callback');

        const currentUser = await googleAuthenticate.authenticateviagoogle(profile);
        console.log(currentUser);
        if (currentUser) {
            console.log('user alerady exist ');
            //if we already have a record with the given profile ID
            const user = currentUser;
            done(null, user);
        } else {
            console.log('inside new user registration');
            await registerViaGoogle.registerViagoogle(profile);
            const currentUser = await googleAuthenticate.authenticateviagoogle(profile);
            const user = currentUser;

            done(null, user);
        }
    } catch (err) {
        console.log(err.mesaage);
        return done(null, false);
    }
};
