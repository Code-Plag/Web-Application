function getresultdata() {
    console.log('hello jhooooo ');
    //fetch('http://ec2-18-206-208-59.compute-1.amazonaws.com:8080/demo')
    fetch('http://localhost:3000/api/v1/checkplag')
        .then(function (response) {
            if (response.status !== 200) {
                console.log('Looks like there was a problem. Status Code: ' + response.status);
                return;
            }

            // Examine the text in the response
            response.text().then(function (text) {
                document.getElementById('hideme').style.display = 'none';
                document.getElementById('result').innerHTML = text;
            });
        })
        .catch(function (err) {
            console.log('Fetch Error :-S', err);
        });
}
