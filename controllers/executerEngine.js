const express = require('express');
const app = express();
const url = require('url');
const fs = require('fs');
var exec = require('child_process').execFile;
const path = require('path');
const { json } = require('body-parser');

exports.runPlagEngine = function (req, res) {
    console.log('fun() start');
    console.log(req.session.folderpath);
    const arg1 = req.session.executepath;
    const arg2 = path.join(req.session.folderpath, 'Result');
    console.log(arg2);
    exec('./models/MODULAR_CODE/a.exe', [arg1, arg2], function (err, data) {
        if (err) {
            return;
        } else {
            console.log(data);
            console.log('reached upto this');
            var JsonResult = path.join(arg2, '/');
            req.session.JsonResult = JsonResult;
            var obj = {};
            console.log('before', obj);
            CreateJsonPlag(JsonResult, obj);
            // console.log("after",obj)
            myobj = {};
            myobj.result = obj;

            //  console.log(myobj);
            //ok

            //console.log(myobj);
            //res.set('application/json')
            //res.send(data);
            res.statusCode = 200;
            res.set('text/html');

            res.sendFile(path.resolve(__dirname + '/..' + '/public' + '/PutFolderName.html'));
        }

        function CreateJsonPlag(dir, obj) {
            fs.readdirSync(dir).forEach(function (file) {
                obj[file.replace(/\.json$/, '')] = require(dir + file);
            });
        }
    });
};
