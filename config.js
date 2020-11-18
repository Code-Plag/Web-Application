
config={
    host:'us-cdbr-east-02.cleardb.com',
    user:'bd11ff71ba00ac',
    password:'a21553f2',
    database:'heroku_c82a9c7311ea00b'
}

/* 
function fetchfromdatabase(sql,data){

    return new Promise((resolve,reject)=>{
connection.query(sql,data, function (error, results) {
    if (error) { */
          //throw error;
        /*   return reject(error) */
      /* res.json({
          status:false,
          message:'there are some error with query'
      }) */
   /*  }else{ */
        /* res.json({
          status:true,
          data:results,
          message:'user registered sucessfully'
          
      }) */

      /* console.log(results);
      return resolve(results);
    }
  });
  connection.end();
});

} */
module.exports =config;
    
 
   

