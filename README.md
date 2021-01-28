# Web-Application

for windows system 

# To run the database script
  1.open the mysql workbench 
  2.run the sql script named as "code_plag_sql_script.sql" file
  3.and database schema is updated .
  4.update the your database configuration in config.js file (imp)
 
# To start Mailing smtp (verfifcation via mail)
  1.go to .env file
  2.add your email id and password in the EMAIL and PASSWORD section 
  3.if you are using gmail
    1. go to "https://myaccount.google.com/lesssecureapps" this link
    2. switch on the allow less secure apps

# To start application
  1. run "npm install" in the folder containing index.js
  2. after successfull installation of node modules
  3.run "npm start" and wait till you see message "server is Running at Port 3000";
  4.and application is running 
  5.in browser go to "localhost:3000/api/v1".
  6.once you have started mailing smtp you can signup signin and start checking plagiarism 




