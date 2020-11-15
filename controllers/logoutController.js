const fs = require('fs');
exports.logoutpage = function (req, res) {
    res.send(
        '<form action="/logout" method="post"><input type="submit" value="logout"/></form>'
    );
};

exports.logout = function (req, res) {
    // if (req.session.user == '') {
        
    //     res.redirect('/api/v1/login');
    // }
    // console.log(req.user);
    // req.session.destroy(function(err) {
    //     console.log("user logged out")
    //   });
    // req.logout();
    let folderpath =  req.session.folderpath;
    if(fs.existsSync(folderpath)){
        fs.rmdirSync(folderpath, { recursive: true });
        console.log(`${folderpath} is deleted!`);
    }
    req.session.destroy(function(err) {
            console.log("user logged out")
          });
          res.redirect('/api/v1/login');
    
};
