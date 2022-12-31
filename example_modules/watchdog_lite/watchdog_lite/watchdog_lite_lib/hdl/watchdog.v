//
// Verilog Module watchdog_lite_lib.watchdog
//
// Created:
//          by - Administrator.UNKNOWN (WIN-P4J5GE79P21)
//          at - 17:58:16 2022/11/12
//
// using Mentor Graphics HDL Designer(TM) 2021.1 Built on 14 Jan 2021 at 15:11:42
// created by zyy

`resetall
`timescale 1ns/10ps
module watchdog #
(
	parameter		INITIAL_PERIODS = 64'hFFFF_FFFF_FFFF_FFFF	
)
(
	input           			wLB_Clk  		,
	input           			wLB_Rst  		,
	
	input						wLB_wr			,
	input						wLB_rd			,
	input	[7:0]				wLB_add			,
	input	[31:0]				wLB_wr_data		,
	
	output		  				nwWatchdogRst
);

//----------------------------------------------------
//signal define
reg						wSafeGuard			;
reg		[63:0]			bWatchdogCounter	;

//====================================================
always @(posedge wLB_Clk)begin
	if(wLB_Rst)begin
		bWatchdogCounter	<=	INITIAL_PERIODS	;
	end
	else if(wLB_wr && (wLB_add == 8'h04))begin
		bWatchdogCounter	<=	INITIAL_PERIODS	;
	end
	else if(wLB_wr && (wLB_add == 8'h08))begin
		bWatchdogCounter	<=	wLB_wr_data		;
	end
	else if(bWatchdogCounter > 0)begin
		bWatchdogCounter	<=	bWatchdogCounter - 1;
	end
end

always @(posedge wLB_Clk)begin
	if(wLB_Rst)begin
		wSafeGuard	<=	1'b1	;
	end
	else if(wLB_wr && (wLB_add == 8'h01))begin
		wSafeGuard	<=	wLB_wr_data[0]	;
	end
end

//====================================================
//watchdog output
assign	nwWatchdogRst = wSafeGuard && (bWatchdogCounter != 0);

endmodule
