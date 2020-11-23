var mysql = require('mysql');
var Config = require('../config');
const fs = require('fs');
var Promise = require('bluebird');

Promise.promisifyAll(require('mysql/lib/Connection').prototype);
Promise.promisifyAll(require('mysql/lib/Pool').prototype);

module.exports.CompFolder =async (req, res) => {
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
       // console.log(email);
        let matchJson;
        let fileJson;

        if (fs.existsSync(req.session.JsonResult + file1) && fs.existsSync(req.session.JsonResult + file2)) {
            matchJson = fs.readFileSync(req.session.JsonResult + file1); // json

            fileJson = fs.readFileSync(req.session.JsonResult + file2); // json

          //  console.log(matchJson);
           // console.log(typeof fileJson);
        }

        const data = {
            
            MatchedDataJson: JSON.stringify(JSON.parse(matchJson)), //err
            fileDataJson: JSON.stringify(JSON.parse(fileJson)),
            status: 'Completed',
        };
        Connection.connect();
        Connection.query(
            'UPDATE ComparisonHistory SET ? WHERE email = ? AND folderName = ? ',
            [data, email, folderName],
            (err, results) => {
                if (err) {
                    console.log(err);
                    reject(err);
                }
               // console.log('inserted');
                //console.log(results)
                Connection.end();
                resolve(results);
            }
        );
        
    });
};
module.exports.insert_folder = async (req, res) => {
    return new Promise((resolve, reject) => {
        const FolderName = req.body.CompFolder;
        today = new Date();
        var date = today.getFullYear() + '-' + (today.getMonth() + 1) + '-' + today.getDate();

        const Connection = mysql.createConnection(config);
        email = req.session.user;
        const data = {
            email: email,
            folderName: req.session.foldername,
            fileCount: req.session.fileCount,
            ComparisonDate: req.session.ComparisonDate,
            language: req.session.language,
            comparisonTime:Date.now()
        };
        Connection.connect();
        Connection.query('INSERT INTO ComparisonHistory SET ?', data, (err, results) => {
            if (err) {
                console.log(err);
                reject(err);
            }
       //     console.log('inserted');
       //     console.log(results);
            Connection.end();
            resolve(results);
            
        });
       
    });
};

module.exports.delete_folder = async (req, res) => {
    return new Promise((resolve, reject) => {
      
       

        const Connection = mysql.createConnection(config);
       
       
        email = req.session.email;
        folderName = req.session.foldername;
        Connection.connect();
        Connection.query('delete from ComparisonHistory where email = ? AND folderName = ?', [email, folderName], (err,results) => {
            if (err) {
                console.log(err);
                reject(err);
            }
          //  console.log('deleted');
           
            Connection.end();
            resolve(results);
           
        });
       
    });
};
