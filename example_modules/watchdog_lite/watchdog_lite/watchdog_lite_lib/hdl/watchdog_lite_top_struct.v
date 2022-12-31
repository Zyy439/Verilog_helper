//
// Module watchdog_lite_lib.watchdog_lite_top.struct
//
// Created:
//          by - Administrator.UNKNOWN (WIN-P4J5GE79P21)
//          at - 10:55:46 2022/12/11
//
// Generated by Mentor Graphics' HDL Designer(TM) 2021.1 Built on 14 Jan 2021 at 15:11:42
//

`resetall
`timescale 1ns/10ps
module watchdog_lite_top( 
   // Port Declarations
   input   wire            wLB_Clk, 
   input   wire            wLB_Rst, 
   input   wire    [7:0]   wLB_add, 
   input   wire            wLB_rd, 
   input   wire            wLB_wr, 
   input   wire    [31:0]  wLB_wr_data, 
   output  wire            nwWatchdogRst
);


// Internal Declarations


// Local declarations

// Internal signal declarations


// Instances 
watchdog U_0( 
   .wLB_Clk       (wLB_Clk), 
   .wLB_Rst       (wLB_Rst), 
   .wLB_wr        (wLB_wr), 
   .wLB_rd        (wLB_rd), 
   .wLB_add       (wLB_add), 
   .wLB_wr_data   (wLB_wr_data), 
   .nwWatchdogRst (nwWatchdogRst)
); 


endmodule // watchdog_lite_top

