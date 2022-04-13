// (C) 2001-2012 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/rel/12.1/ip/merlin/altera_merlin_router/altera_merlin_router.sv.terp#1 $
// $Revision: #1 $
// $Date: 2012/08/12 $
// $Author: swbranch $

// -------------------------------------------------------
// Merlin Router
//
// Asserts the appropriate one-hot encoded channel based on 
// either (a) the address or (b) the dest id. The DECODER_TYPE
// parameter controls this behaviour. 0 means address decoder,
// 1 means dest id decoder.
//
// In the case of (a), it also sets the destination id.
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module SoC_addr_router_011_default_decode
  #(
     parameter DEFAULT_CHANNEL = 0,
               DEFAULT_DESTID = 0 
   )
  (output [84 - 78 : 0] default_destination_id,
   output [66-1 : 0] default_src_channel
  );

  assign default_destination_id = 
    DEFAULT_DESTID[84 - 78 : 0];
  generate begin : default_decode
    if (DEFAULT_CHANNEL == -1)
      assign default_src_channel = '0;
    else
      assign default_src_channel = 66'b1 << DEFAULT_CHANNEL;
  end
  endgenerate

endmodule


module SoC_addr_router_011
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // Command Sink (Input)
    // -------------------
    input                       sink_valid,
    input  [95-1 : 0]    sink_data,
    input                       sink_startofpacket,
    input                       sink_endofpacket,
    output                      sink_ready,

    // -------------------
    // Command Source (Output)
    // -------------------
    output                          src_valid,
    output reg [95-1    : 0] src_data,
    output reg [66-1 : 0] src_channel,
    output                          src_startofpacket,
    output                          src_endofpacket,
    input                           src_ready
);

    // -------------------------------------------------------
    // Local parameters and variables
    // -------------------------------------------------------
    localparam PKT_ADDR_H = 49;
    localparam PKT_ADDR_L = 36;
    localparam PKT_DEST_ID_H = 84;
    localparam PKT_DEST_ID_L = 78;
    localparam ST_DATA_W = 95;
    localparam ST_CHANNEL_W = 66;
    localparam DECODER_TYPE = 0;

    localparam PKT_TRANS_WRITE = 52;
    localparam PKT_TRANS_READ  = 53;

    localparam PKT_ADDR_W = PKT_ADDR_H-PKT_ADDR_L + 1;
    localparam PKT_DEST_ID_W = PKT_DEST_ID_H-PKT_DEST_ID_L + 1;




    // -------------------------------------------------------
    // Figure out the number of bits to mask off for each slave span
    // during address decoding
    // -------------------------------------------------------
    localparam PAD0 = log2ceil(64'h2000 - 64'h1800);
    localparam PAD1 = log2ceil(64'h2800 - 64'h2000);
    localparam PAD2 = log2ceil(64'h28e0 - 64'h28c0);
    localparam PAD3 = log2ceil(64'h2900 - 64'h28e0);
    localparam PAD4 = log2ceil(64'h2920 - 64'h2900);
    localparam PAD5 = log2ceil(64'h2940 - 64'h2920);
    localparam PAD6 = log2ceil(64'h2960 - 64'h2940);
    localparam PAD7 = log2ceil(64'h2980 - 64'h2960);
    localparam PAD8 = log2ceil(64'h29a0 - 64'h2980);
    localparam PAD9 = log2ceil(64'h29c0 - 64'h29a0);
    localparam PAD10 = log2ceil(64'h29c8 - 64'h29c0);
    localparam PAD11 = log2ceil(64'h29fc - 64'h29f8);
    localparam PAD12 = log2ceil(64'h2a00 - 64'h29fc);
    localparam PAD13 = log2ceil(64'h2a04 - 64'h2a00);
    localparam PAD14 = log2ceil(64'h2a08 - 64'h2a04);
    localparam PAD15 = log2ceil(64'h2a0c - 64'h2a08);
    localparam PAD16 = log2ceil(64'h2a10 - 64'h2a0c);
    localparam PAD17 = log2ceil(64'h2a14 - 64'h2a10);
    localparam PAD18 = log2ceil(64'h2a18 - 64'h2a14);
    localparam PAD19 = log2ceil(64'h2a1c - 64'h2a18);
    localparam PAD20 = log2ceil(64'h2a20 - 64'h2a1c);
    localparam PAD21 = log2ceil(64'h2a24 - 64'h2a20);
    localparam PAD22 = log2ceil(64'h2a28 - 64'h2a24);
    // -------------------------------------------------------
    // Work out which address bits are significant based on the
    // address range of the slaves. If the required width is too
    // large or too small, we use the address field width instead.
    // -------------------------------------------------------
    localparam ADDR_RANGE = 64'h2a28;
    localparam RANGE_ADDR_WIDTH = log2ceil(ADDR_RANGE);
    localparam OPTIMIZED_ADDR_H = (RANGE_ADDR_WIDTH > PKT_ADDR_W) ||
                                  (RANGE_ADDR_WIDTH == 0) ?
                                        PKT_ADDR_H :
                                        PKT_ADDR_L + RANGE_ADDR_WIDTH - 1;
    localparam RG = RANGE_ADDR_WIDTH-1;

      wire [PKT_ADDR_W-1 : 0] address = sink_data[OPTIMIZED_ADDR_H : PKT_ADDR_L];

    // -------------------------------------------------------
    // Pass almost everything through, untouched
    // -------------------------------------------------------
    assign sink_ready        = src_ready;
    assign src_valid         = sink_valid;
    assign src_startofpacket = sink_startofpacket;
    assign src_endofpacket   = sink_endofpacket;

    wire [PKT_DEST_ID_W-1:0] default_destid;
    wire [66-1 : 0] default_src_channel;




    SoC_addr_router_011_default_decode the_default_decode(
      .default_destination_id (default_destid),
      .default_src_channel (default_src_channel)
    );

    always @* begin
        src_data    = sink_data;
        src_channel = default_src_channel;

        src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = default_destid;
        // --------------------------------------------------
        // Address Decoder
        // Sets the channel and destination ID based on the address
        // --------------------------------------------------

        // ( 0x1800 .. 0x2000 )
        if ( {address[RG:PAD0],{PAD0{1'b0}}} == 14'h1800 ) begin
            src_channel = 66'b00000000000000000000001;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 0;
        end

        // ( 0x2000 .. 0x2800 )
        if ( {address[RG:PAD1],{PAD1{1'b0}}} == 14'h2000 ) begin
            src_channel = 66'b00010000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 62;
        end

        // ( 0x28c0 .. 0x28e0 )
        if ( {address[RG:PAD2],{PAD2{1'b0}}} == 14'h28c0 ) begin
            src_channel = 66'b00000100000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 18;
        end

        // ( 0x28e0 .. 0x2900 )
        if ( {address[RG:PAD3],{PAD3{1'b0}}} == 14'h28e0 ) begin
            src_channel = 66'b00000001000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 16;
        end

        // ( 0x2900 .. 0x2920 )
        if ( {address[RG:PAD4],{PAD4{1'b0}}} == 14'h2900 ) begin
            src_channel = 66'b00000000001000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 13;
        end

        // ( 0x2920 .. 0x2940 )
        if ( {address[RG:PAD5],{PAD5{1'b0}}} == 14'h2920 ) begin
            src_channel = 66'b00000000000000100000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 9;
        end

        // ( 0x2940 .. 0x2960 )
        if ( {address[RG:PAD6],{PAD6{1'b0}}} == 14'h2940 ) begin
            src_channel = 66'b00000000000000000100000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 6;
        end

        // ( 0x2960 .. 0x2980 )
        if ( {address[RG:PAD7],{PAD7{1'b0}}} == 14'h2960 ) begin
            src_channel = 66'b00000000000000000000100;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 3;
        end

        // ( 0x2980 .. 0x29a0 )
        if ( {address[RG:PAD8],{PAD8{1'b0}}} == 14'h2980 ) begin
            src_channel = 66'b10000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 65;
        end

        // ( 0x29a0 .. 0x29c0 )
        if ( {address[RG:PAD9],{PAD9{1'b0}}} == 14'h29a0 ) begin
            src_channel = 66'b01000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 64;
        end

        // ( 0x29c0 .. 0x29c8 )
        if ( {address[RG:PAD10],{PAD10{1'b0}}} == 14'h29c0 ) begin
            src_channel = 66'b00100000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 63;
        end

        // ( 0x29f8 .. 0x29fc )
        if ( {address[RG:PAD11],{PAD11{1'b0}}} == 14'h29f8 ) begin
            src_channel = 66'b00001000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 19;
        end

        // ( 0x29fc .. 0x2a00 )
        if ( {address[RG:PAD12],{PAD12{1'b0}}} == 14'h29fc ) begin
            src_channel = 66'b00000010000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 17;
        end

        // ( 0x2a00 .. 0x2a04 )
        if ( {address[RG:PAD13],{PAD13{1'b0}}} == 14'h2a00 ) begin
            src_channel = 66'b00000000100000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 15;
        end

        // ( 0x2a04 .. 0x2a08 )
        if ( {address[RG:PAD14],{PAD14{1'b0}}} == 14'h2a04 ) begin
            src_channel = 66'b00000000010000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 14;
        end

        // ( 0x2a08 .. 0x2a0c )
        if ( {address[RG:PAD15],{PAD15{1'b0}}} == 14'h2a08 ) begin
            src_channel = 66'b00000000000100000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 12;
        end

        // ( 0x2a0c .. 0x2a10 )
        if ( {address[RG:PAD16],{PAD16{1'b0}}} == 14'h2a0c ) begin
            src_channel = 66'b00000000000010000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 11;
        end

        // ( 0x2a10 .. 0x2a14 )
        if ( {address[RG:PAD17],{PAD17{1'b0}}} == 14'h2a10 ) begin
            src_channel = 66'b00000000000001000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 10;
        end

        // ( 0x2a14 .. 0x2a18 )
        if ( {address[RG:PAD18],{PAD18{1'b0}}} == 14'h2a14 ) begin
            src_channel = 66'b00000000000000010000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 8;
        end

        // ( 0x2a18 .. 0x2a1c )
        if ( {address[RG:PAD19],{PAD19{1'b0}}} == 14'h2a18 ) begin
            src_channel = 66'b00000000000000001000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 7;
        end

        // ( 0x2a1c .. 0x2a20 )
        if ( {address[RG:PAD20],{PAD20{1'b0}}} == 14'h2a1c ) begin
            src_channel = 66'b00000000000000000010000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 5;
        end

        // ( 0x2a20 .. 0x2a24 )
        if ( {address[RG:PAD21],{PAD21{1'b0}}} == 14'h2a20 ) begin
            src_channel = 66'b00000000000000000001000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 4;
        end

        // ( 0x2a24 .. 0x2a28 )
        if ( {address[RG:PAD22],{PAD22{1'b0}}} == 14'h2a24 ) begin
            src_channel = 66'b00000000000000000000010;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 2;
        end

end


    // --------------------------------------------------
    // Ceil(log2()) function
    // --------------------------------------------------
    function integer log2ceil;
        input reg[65:0] val;
        reg [65:0] i;

        begin
            i = 1;
            log2ceil = 0;

            while (i < val) begin
                log2ceil = log2ceil + 1;
                i = i << 1;
            end
        end
    endfunction

endmodule

