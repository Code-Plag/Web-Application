const multer = require('multer');
const fs = require('fs');
const path = require('path');
const session_check_controller = require('../controllers/session_check_controller.js');

var jwt = require('jsonwebtoken');
const { request } = require('http');

module.exports.createtempdir = function (req, res) {
    //console.log(req.session.folderpath);

    const dir = path.resolve(req.session.folderpath, (`${req.session.email}`+`${Date.now()}`));
    req.session.dir = dir;

    var result = 'Result';

    const userResultFolder = path.resolve(`${dir}`, `${result}`);

    try {
        if (!fs.existsSync(dir)) {
            fs.mkdirSync(dir);
        }

        if (!fs.existsSync(userResultFolder)) {
            fs.mkdirSync(userResultFolder);
        }
    } catch (err) {
        console.error(err);
    }

    try {
        upload(req, res, (err) => {
            var fileCount = req.files.length;
            req.session.fileCount = fileCount;
            if (req.fileValidationError) {
                return res.send(req.fileValidationError);
            } else if (!req.files) {
                return res.send('Please select an image to upload');
            } else if (err instanceof multer.MulterError) {
                return res.send(err);
            } else {
                //res.sendFile(path.join(__dirname, '/..', '/public', '/response.html'));
                var details = {
                    foldername: req.body.foldername,
                    language: req.body.language,
                    no_of_files: fileCount,
                };
                req.session.language = req.body.language;
                req.session.uploadDetails = details;
                req.session.ComparisonDate = req.body.ComparisonDate;
                req.session.foldername = req.body.foldername;
              //  console.log(req.session.foldername);
                if (session_check_controller.check_session(req, res)) {
               //     console.log('inside checker');
                    res.render('check_plagiarism.ejs', {
                        session: session_check_controller.check_session(req, res),
                        username: req.session.user,
                        details: details,
                    });
                } else {
                //    console.log('outiside checker');
                    res.render('homePage.ejs', {
                        session: session_check_controller.check_session(req, res),
                        username: req.session.user,
                    });
                }
            }
        });
    } catch (error) {
        console.log(error);
        res.send(400);
    }
};
var storage = multer.diskStorage({
    destination: (req, file, cb) => {
        try {
            if (!fs.existsSync(req.session.dir)) {
                fs.mkdirSync(req.session.dir);
            }
        } catch (err) {
            console.error(err);
        }

        cb(null, req.session.dir);
    },
    filename: function (req, file, cb) {
        cb(null, file.originalname);
    },
});

var upload = multer({
    storage: storage,
    limits: { fileSize: 2 * 1024 * 1024, files: 100, fields: 100 },
}).array('multiple_files', 100);
