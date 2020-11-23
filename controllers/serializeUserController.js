module.exports.serializeUserCallback = (user, done) => {
   /* console.log(
        'Inside serializeUser callback. User id is save to the session file store here'
    );*/

   return done(null, {
        userid: user.userid,
        registerCode: user.registercode === 1, // this does require that `cust_code`
        // is defined for all regular users.
    });
};
