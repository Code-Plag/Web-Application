var mysql=require('mysql');
var Config = require('../config');
const bcrypt = require('bcrypt');

module.exports.verify=function(req,res)
{

let host='localhost:3000';
//console.log(req.protocol+"://"+req.get('host'));
if((req.protocol+"://"+req.get('host'))==("http://"+host))
{
        
    console.log("Domain is matched. Information is from Authentic email");
    let id =req.query.id;
    let email =req.query.email;//http://localhost:3000/api/v1/verify?id=f657312b94e453ca86e3d6a41bb9671e5b&email=luckypatil15@gmail.com
   // console.log(id);
   // console.log(email);
    let Connection = mysql.createConnection(Config);
    var sql =`SELECT * FROM users WHERE activeToken = ? and email= ?`;
    let data = [id, email];
    Connection.connect();
    Connection.query(sql,data, (err,results) => {
     
             if(err) {

              res.send("credentials doesnt match please login again");

             };
    
              console.log('Data received from Db:');
            //  console.log(results);
             // console.log(results[0].activeExpires);

              if( Date.now()-results[0].activeExpires <= 3600000)
              {
                     console.log("email is verified");
                     let sql = `UPDATE users SET activestatus = ? WHERE userid =  ? AND email= ?`;
                      let data =[ true,results[0].userid,results[0].email];  
                     Connection.query(sql,data,function (err, result) {
                      if (err) throw err;
                      console.log(result.affectedRows + " record(s) updated");

                      res.render('verification_success.ejs');
                    });
                    
              }
              else{

                  res.end("fail to verify you please register again");

              }
      
              Connection.end();
    });
  }
  else{

    res.send("bad request");
  }
}
