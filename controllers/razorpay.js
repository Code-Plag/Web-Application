
const Razorpay = require('razorpay');
require('dotenv').config();



module.exports.createOrderID = async (req,res)=>{

   let options=req.body;
   console.log(options)

const instance = new Razorpay({
    key_id:'rzp_test_nraFQYmH47MQ7Z',
    key_secret:'PDDiKhxLlRAirzEXnJdTGE29',
});


    
  instance.orders.create(options,  function (err, order) {

        if(err)
        return err;
    
    
res.send(order);
  
 

})

}