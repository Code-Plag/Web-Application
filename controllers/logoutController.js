const fs = require('fs');
exports.logoutpage = function (req, res) {
      req.session.destroy(function(err) {
            //console.log("user logged out")
            res.redirect('/api/v1/login');
            
          });   
    }
    
   



