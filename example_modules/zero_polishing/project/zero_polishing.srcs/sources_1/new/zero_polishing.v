`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: zyy
// 
// Create Date: 2022/12/31 23:18:08
// Design Name: 
// Module Name: zero_polishing
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module zero_polishing #
(
    parameter       WIDTH_INPUT				=	14	,
	parameter		WIDTH_OUTPUT			=	16	,
	parameter		HIGHBITS_ALLOCATE		=	0	,
	parameter		FILL_BIT1				=	0
)
(
	input		[WIDTH_INPUT - 1 : 0]		bData_in	,
	output		[WIDTH_OUTPUT - 1: 0]		bData_out	
);

//=====================================================================================
//parameter define
localparam	WIDTH_GAP	=	difference(WIDTH_OUTPUT,WIDTH_INPUT);

//=====================================================================================
//					data polishing
//=====================================================================================
generate
if(HIGHBITS_ALLOCATE == 1)begin
	if(FILL_BIT1 == 1)begin
		assign	bData_out	=	{bData_in,{{WIDTH_GAP}{1'b1}}};
	end
	else begin
		assign	bData_out	=	{bData_in,{{WIDTH_GAP}{1'b0}}};
	end
end
else begin
	if(FILL_BIT1 == 1)begin
		assign	bData_out	=	{{{WIDTH_GAP}{1'b1}},bData_in};
	end
	else begin
		assign	bData_out	=	{{{WIDTH_GAP}{1'b0}},bData_in};
	end
end
endgenerate
	

//=====================================================================================
//					ensure that the width gap is not negative
//=====================================================================================
function integer	difference;
input	integer		long_width,short_width;
	begin
		difference = 0;
		if(long_width - short_width > 0)begin
			difference = long_width - short_width;
		end
	end
endfunction


endmodule
