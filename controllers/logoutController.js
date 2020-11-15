exports.logoutpage = function (req, res) {
    res.send(
        '<form action="/logout" method="post"><input type="submit" value="logout"/></form>'
    );
};

exports.logout = function (req, res) {
    if (req.user == '') {
        res.redirect('/login');
    }
    console.log(req.user);
    req.logout();
    console.log(req.user);
};
