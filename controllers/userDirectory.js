const express = require('express');
const path = require('path');
var mysql = require('mysql');
var Config = require('../config');
const fs = require('fs');

module.exports.CreateUserDirectory = function (req, res) {
    console.log('create user', req.user);
    var email = req.body.email || req.user.email;
    req.session.email = email;
    var MYMAIL = email;

    //  var result = 'Result';
    const userFolder = path.resolve(`models`, `MODULAR_CODE`, `Testing`);

    // const userResultFolder = path.resolve(`${userFolder}`, `${result}`);
    // MYFOLDERPATH = userFolder;

    // try {
    //     if (!fs.existsSync(userFolder)) {
    //         fs.mkdirSync(userFolder);
    //     }

    //     if (!fs.existsSync(userResultFolder)) {
    //         fs.mkdirSync(userResultFolder);
    //     }
    // } catch (err) {
    //     console.error(err);
    // }
    req.session.folderpath = userFolder;
    console.log(req.session.folderpath, 'folder path');

    return userFolder;
};
