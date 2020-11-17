const express = require('express');
const app = express();
const url = require('url');
const fs = require('fs');
//var exec = require('child_process').execFile;
const path = require('path');
const { json } = require('body-parser');
const PutFolderName = require('./PutFolderName');
const loadFunction = require('./loaderFunction.js');
const session_check_controller = require('./session_check_controller.js');
//const { resolve } = require('bluebird');
var Promise = require('bluebird');
var exec = require('child_process').execFile;
function promiseFromChildProcess(child) {
    return new Promise(function (resolve, reject) {
        console.log('inside promise child process');
        child.addListener("error", reject);
        child.addListener("exit", resolve);
    });
}

exports.runPlagEngine = async  (req, res)=>{
    console.log('fun() start');
    console.log(req.session.executepath);
    const arg1 = req.session.dir;
    const arg2 = path.join(req.session.folderpath, 'Result');
    var details = req.session.uploadDetails;
    const arg3= req.session.language;

    console.log(arg2);
    var start = Date.now();
    try {
        var engine = './models/MODULAR_CODE/src/a.exe';//C:\Users\lenovo\Desktop\MODULAR_CODE\src
        var data = await execPromise (engine, arg1, arg2,arg3);//
        console.log(Date.now()-start,'hi',data);
        var JsonResult = path.join(arg2, '/');
        req.session.JsonResult = JsonResult;
        var obj={};
        var object=await CreateJsonPlag(JsonResult, obj);
        console.log(Date.now()-start,'before put folder name');
        await PutFolderName.CompFolder(req,res);// database entry
        console.log(Date.now()-start,'after put folder name');
        var results = await loadFunction.loader(req,res);//return data selected
        if(fs.existsSync(arg1)){//
            fs.rmdirSync(arg1, { recursive: true });

        }
        // if(fs.existsSync(JsonResult)){//
        //     fs.rmdirSync(JsonResult, { recursive: true });

        // }

        if(session_check_controller.check_session(req,res)){
            console.log("inside checker")
            res.render('dashboard.ejs',{session:session_check_controller.check_session(req,res),
                                        username:req.session.user,
                                        results : results,
                                        details : details});
        }
    else{
        console.log("outiside checker")
        res.render('homePage.ejs',{session:session_check_controller.check_session(req,res),username:req.session.user});
    }
    
    } catch (error) {

        console.log(error)
    }
}
//     exec('./models/MODULAR_CODE/a.exe', [arg1, arg2], async function (err, data) {
//         console.log(Date.now()-start,'after callback plag');
//         console.log("outside");
//         if (err) {
//             //delete
//             console.log("inside");
//             console.log(err);
//             return;
//         } else {
//             console.log(data);
//             console.log('reached upto this');
            
//             var obj = {};
//             console.log(Date.now()-start,'before creatjson plag');


           
//             console.log(object,'affter creatjson plag');
//             myobj = {};
//             myobj.result = obj;
        
          
//             console.log(Date.now()-start);
//     //pushes json into database
//            console.log('json pushed to database');
//            console.log(Date.now()-start,'after database push plag');
//            // timestamp folder deletion
//             // 
         
//           // console.log(results);
           
//            //fs.readdirSync(dir).forEach(function (file) {
//           //  obj[file.replace(/\.json$/, '')] = require(dir + file);
        

        
//     });
// };
function CreateJsonPlag(dir, obj) {
    return new Promise ((resolve,reject)=>{
        fs.readdirSync(dir).forEach(function (file) {
            obj[file.replace(/\.json$/, '')] = require(dir + file);
         
        });
        resolve(obj);
    }
     );
  
    
}
function execPromise(command,arg1,arg2,arg3) {
    
    return new Promise(function(resolve, reject) {
        exec(command,[arg1,arg2,arg3], (error, data) => {
            if (error) {
                reject(error);
                return;
            }
            console.log("exec promise")
            console.log(data);
            resolve(data);
        });
    });
}
