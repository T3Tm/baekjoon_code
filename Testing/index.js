function A(){
    $("#div_header").load("h_sugang_sincheong_i01_top_pre.jsp",function(response, status, xhr ){
        $("#div_middle").load("h_sugang_sincheong_i01_middle_pre.jsp",$('#frm1').serialize(), function(){
            $("#div_bottom").load("h_sugang_sincheong_i01_bottom_pre.jsp");		
        });	
    });		
    
    $("#div_middle").addClass("border border-primary");
    $("#divMyinfo").addClass("border border-primary");
}
