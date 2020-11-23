exports.check_session= function(req,res){
    var flag = false; 
	if(req.session.user!= null){
		flag=true;
	}
   // console.log(flag);
    return flag;
}