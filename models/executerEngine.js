const express = require('express');
const app = express();
const url = require('url');
const fs = require('fs');
//var exec = require('child_process').execFile;
const path = require('path');
const { json } = require('body-parser');
const PutFolderName = require('./PutFolderName');
const loadFunction = require('./loaderFunction.js');
const session_check_controller = require('../controllers/session_check_controller.js');
//const { resolve } = require('bluebird');
var Promise = require('bluebird');
var exec = require('child_process').execFile;
function promiseFromChildProcess(child) {
    return new Promise(function (resolve, reject) {
        console.log('inside promise child process');
        child.addListener('error', reject);
        child.addListener('exit', resolve);
    });
}

exports.runPlagEngine = async (req, res) => {
   // console.log('fun() start');
    //console.log(req.session.executepath);
    const arg1 = req.session.dir;
    const arg2 = path.join(req.session.dir, 'Result');
    var details = req.session.uploadDetails;
    const arg3 = req.session.language;

    //console.log(arg2);
    var start = Date.now();
    try {
        var engine = './Core_Engine/a.exe'; //../Core_Engine/a.out
        
        await PutFolderName.insert_folder(req, res);
        res.on('finish',async ()=>{
            try {
                var data = await execPromise(engine, arg1, arg2, arg3); //
          //      console.log(Date.now() - start, 'hi');
                var JsonResult = path.join(arg2, '/');
                req.session.JsonResult = JsonResult;
                var obj = {};
                var object = await CreateJsonPlag(JsonResult, obj);
          //      console.log(Date.now() - start, 'before put folder name');
                await PutFolderName.CompFolder(req, res); // database entry
            //    console.log(Date.now() - start, 'after put folder name');
                
    
                if (fs.existsSync(arg1)) {
                    //
                    fs.rmdirSync(arg1, { recursive: true });
                }
                
            //    console.log('after r3edirect.........................');
            } catch (error) {
                console.log(error);
                let results  = await PutFolderName.delete_folder(req,res);
                if (fs.existsSync(arg1)) {
                    //
                    fs.rmdirSync(arg1, { recursive: true });
                }
            }
           
        })
        res.redirect('/api/v1/dashboard');
        // var data = await execPromise(engine, arg1, arg2, arg3); //
        // console.log(Date.now() - start, 'hi');
        // var JsonResult = path.join(arg2, '/');
        // req.session.JsonResult = JsonResult;
        // var obj = {};
        // var object = await CreateJsonPlag(JsonResult, obj);
        // console.log(Date.now() - start, 'before put folder name');
        // await PutFolderName.CompFolder(req, res); // database entry
        // console.log(Date.now() - start, 'after put folder name');
      

        // if (fs.existsSync(arg1)) {
        //     //
        //     fs.rmdirSync(arg1, { recursive: true });
        // }
        
        // console.log('after r3edirect.........................');
        
    } catch (error) {
        console.log(error);
        let results  = await PutFolderName.delete_folder(req,res);
        if (fs.existsSync(arg1)) {
            //
            fs.rmdirSync(arg1, { recursive: true });
        }

    }
};

function CreateJsonPlag(dir, obj) {
    return new Promise((resolve, reject) => {
        fs.readdirSync(dir).forEach(function (file) {
            
            obj[file.replace(/\.json$/, '')] = fs.readFileSync(dir+file);
        });
        resolve(obj);
    });
}
function execPromise(command, arg1, arg2, arg3) {
    return new Promise(function (resolve, reject) {
        exec(command, [arg1, arg2, arg3], (error, data) => {
            if (error) {
                reject(error);
                return;
            }
         //   console.log('exec promise');
            resolve(data);
        });
    });
}
