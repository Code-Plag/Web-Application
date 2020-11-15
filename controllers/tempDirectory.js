const multer = require('multer');
const fs = require('fs');
const path = require('path');

var jwt = require('jsonwebtoken');

module.exports.createtempdir = function (req, res) {
	console.log(req.session.folderpath);

	const dir = path.resolve(req.session.folderpath, `${Date.now()}`);
	req.session.dir = dir;
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
				res.sendFile(path.join(__dirname, '/..', '/public', '/response.html'));
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
}).array('multiple_files', 10);
