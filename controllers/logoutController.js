const fs = require('fs');
exports.logoutpage = function (req, res) {
    // let folderpath =  req.session.folderpath;
    // if(fs.existsSync(folderpath)){
    //     fs.rmdirSync(folderpath, { recursive: true });
    //     console.log(req.sessionID);
    //     console.log(`../sessions/${req.sessionID}.json`);
        
    //     console.log(`${folderpath} is deleted!`);
        req.session.destroy(function(err) {
            console.log("user logged out")
            res.redirect('/api/v1/login');
            
          });
         // fs.unlinkSync(`../sessions/${req.sessionID}.json`);
         
          
    }
    
   
};


