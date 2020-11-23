const express = require('express');
const path = require('path');
var mysql = require('mysql');
var Config = require('../config');
const fs = require('fs');

module.exports.CreateUserDirectory = function (req, res) {
    
    
    const userFolder = path.resolve(`Core_Engine`, `Testing`);
    req.session.folderpath = userFolder;
  //  console.log(req.session.folderpath, 'folder path');

    return userFolder;
};
