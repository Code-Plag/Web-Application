require('dotenv').config();
const nodemailer = require('nodemailer');
const path = require('path');

//step1
module.exports.wrapedSendmail = function (mailOption) {
    return new Promise((resolve, reject) => {
       // console.log(process.env.EMAIL);
        let transporter = nodemailer.createTransport({
            service: 'gmail',
            auth: {
                user: process.env.EMAIL,
                pass: process.env.PASSWORD,
            },
        });
        //step2
    
        transporter.sendMail(mailOption, function (err, data) {
            if (err) {
                console.log('error is :' + err);
                reject(err);
            }

            console.log('message sent sucessfully');
            resolve(data);
        });
    });
};
