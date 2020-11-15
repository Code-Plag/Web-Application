module.exports.getPaymentDeatils = function (req, res) {
    try {
        return request(
            {
                method: 'POST',
                url: `https://rzp_test_nraFQYmH47MQ7Z:PDDiKhxLlRAirzEXnJdTGE29@api.razorpay.com/v1/payments/${req.params.paymentId}/capture`,
                form: {
                    amount: 10 * 100, // amount == Rs 10 // Same As Order amount
                    currency: 'INR',
                },
            },
            async function (err, response, body) {
                if (err) {
                    return res.status(500).json({
                        message: 'Something Went Wrong',
                    });
                }
                console.log('Status:', response.statusCode);
                console.log('Headers:', JSON.stringify(response.headers));
                console.log('Response:', body);
                return res.status(200).json(body);
            }
        );
    } catch (err) {
        return res.status(500).json({
            message: 'Something Went Wrong',
        });
    }
};
