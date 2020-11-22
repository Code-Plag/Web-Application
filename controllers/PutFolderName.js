var mysql = require('mysql');
var Config = require('../config');
const fs = require('fs');
var Promise = require('bluebird');
// Note that the library's classes are not properties of the main export
// so we require and promisifyAll them manually
Promise.promisifyAll(require('mysql/lib/Connection').prototype);
Promise.promisifyAll(require('mysql/lib/Pool').prototype);
/*  fs.readdirSync(req.session.JsonResult).forEach(function (file) {
        file.replace(/\.json$/, '') = require(dir + file);
    }); */

module.exports.CompFolder = (req, res) => {
    return new Promise((resolve, reject) => {
        const FolderName = req.body.CompFolder;
        today = new Date();
        var date = today.getFullYear() + '-' + (today.getMonth() + 1) + '-' + today.getDate();
        let file1 = 'match_data.json';
        let file2 = 'file_data.json';
        //console.log(req.body.ComparisonDate);
        const Connection = mysql.createConnection(config);
        email = req.session.email;
        folderName = req.session.foldername;
        console.log(email);
        let matchJson;
        let fileJson;

        if (fs.existsSync(req.session.JsonResult + file1) && fs.existsSync(req.session.JsonResult + file2)) {
            matchJson = fs.readFileSync(req.session.JsonResult + file1); // json

            fileJson = fs.readFileSync(req.session.JsonResult + file2); // json

            console.log(matchJson);
            console.log(typeof fileJson);
        }

        const data = {
            // email: email,
            // folderName: req.session.foldername,
            // fileCount: req.session.fileCount,
            MatchedDataJson: JSON.stringify(JSON.parse(matchJson)), //err
            fileDataJson: JSON.stringify(JSON.parse(fileJson)),
            status: 'Completed',
            // ComparisonDate: req.session.ComparisonDate,
            //  language: req.session.language,
        };

        Connection.query(
            'UPDATE ComparisonHistory SET ? WHERE email = ? AND folderName = ? ',
            [data, email, folderName],
            (err, results) => {
                if (err) {
                    console.log(err);
                    reject(err);
                }
                console.log('inserted');
                //console.log(results)
                resolve(results);
            }
        );
        Connection.end();
    });
};
module.exports.insert_folder = (req, res) => {
    return new Promise((resolve, reject) => {
        const FolderName = req.body.CompFolder;
        today = new Date();
        var date = today.getFullYear() + '-' + (today.getMonth() + 1) + '-' + today.getDate();

        const Connection = mysql.createConnection(config);
        email = req.session.email;
        const data = {
            email: email,
            folderName: req.session.foldername,
            fileCount: req.session.fileCount,
            ComparisonDate: req.session.ComparisonDate,
            language: req.session.language,
        };

        Connection.query('INSERT INTO ComparisonHistory SET ?', data, (err, results) => {
            if (err) {
                console.log(err);
                reject(err);
            }
            console.log('inserted');
            console.log(results);
            resolve(results);
        });
        Connection.end();
    });
};
