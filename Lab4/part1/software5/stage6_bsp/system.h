/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu_5' in SOPC Builder design 'SoC'
 * SOPC Builder design path: C:/Users/DELL/Documents/Academics/sem6/CO503/FPGA_CO503/Lab4/part1/SoC.sopcinfo
 *
 * Generated: Fri Apr 15 20:51:46 IST 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x1820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "small"
#define ALT_CPU_DATA_ADDR_WIDTH 0xe
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x20
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INST_ADDR_WIDTH 0xe
#define ALT_CPU_NAME "cpu_5"
#define ALT_CPU_RESET_ADDR 0x0


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x1820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "small"
#define NIOS2_DATA_ADDR_WIDTH 0xe
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x20
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INST_ADDR_WIDTH 0xe
#define NIOS2_RESET_ADDR 0x0


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_FIFO
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_5"
#define ALT_STDERR_BASE 0x2860
#define ALT_STDERR_DEV jtag_uart_5
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_5"
#define ALT_STDIN_BASE 0x2860
#define ALT_STDIN_DEV jtag_uart_5
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_5"
#define ALT_STDOUT_BASE 0x2860
#define ALT_STDOUT_DEV jtag_uart_5
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "SoC"


/*
 * atof_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_atof_0_in altera_avalon_fifo
#define ATOF_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define ATOF_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define ATOF_0_IN_BASE 0x29fc
#define ATOF_0_IN_BITS_PER_SYMBOL 16
#define ATOF_0_IN_CHANNEL_WIDTH 8
#define ATOF_0_IN_ERROR_WIDTH 8
#define ATOF_0_IN_FIFO_DEPTH 16
#define ATOF_0_IN_IRQ -1
#define ATOF_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ATOF_0_IN_NAME "/dev/atof_0_in"
#define ATOF_0_IN_SINGLE_CLOCK_MODE 1
#define ATOF_0_IN_SPAN 4
#define ATOF_0_IN_SYMBOLS_PER_BEAT 2
#define ATOF_0_IN_TYPE "altera_avalon_fifo"
#define ATOF_0_IN_USE_AVALONMM_READ_SLAVE 1
#define ATOF_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define ATOF_0_IN_USE_AVALONST_SINK 0
#define ATOF_0_IN_USE_AVALONST_SOURCE 0
#define ATOF_0_IN_USE_BACKPRESSURE 1
#define ATOF_0_IN_USE_IRQ 1
#define ATOF_0_IN_USE_PACKET 1
#define ATOF_0_IN_USE_READ_CONTROL 0
#define ATOF_0_IN_USE_REGISTER 0
#define ATOF_0_IN_USE_WRITE_CONTROL 1


/*
 * atof_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_atof_0_in_csr altera_avalon_fifo
#define ATOF_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define ATOF_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define ATOF_0_IN_CSR_BASE 0x28c0
#define ATOF_0_IN_CSR_BITS_PER_SYMBOL 16
#define ATOF_0_IN_CSR_CHANNEL_WIDTH 8
#define ATOF_0_IN_CSR_ERROR_WIDTH 8
#define ATOF_0_IN_CSR_FIFO_DEPTH 16
#define ATOF_0_IN_CSR_IRQ 5
#define ATOF_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ATOF_0_IN_CSR_NAME "/dev/atof_0_in_csr"
#define ATOF_0_IN_CSR_SINGLE_CLOCK_MODE 1
#define ATOF_0_IN_CSR_SPAN 32
#define ATOF_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define ATOF_0_IN_CSR_TYPE "altera_avalon_fifo"
#define ATOF_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define ATOF_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define ATOF_0_IN_CSR_USE_AVALONST_SINK 0
#define ATOF_0_IN_CSR_USE_AVALONST_SOURCE 0
#define ATOF_0_IN_CSR_USE_BACKPRESSURE 1
#define ATOF_0_IN_CSR_USE_IRQ 1
#define ATOF_0_IN_CSR_USE_PACKET 1
#define ATOF_0_IN_CSR_USE_READ_CONTROL 0
#define ATOF_0_IN_CSR_USE_REGISTER 0
#define ATOF_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * atof_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_atof_0_out altera_avalon_fifo
#define ATOF_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define ATOF_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define ATOF_0_OUT_BASE 0x29f8
#define ATOF_0_OUT_BITS_PER_SYMBOL 16
#define ATOF_0_OUT_CHANNEL_WIDTH 8
#define ATOF_0_OUT_ERROR_WIDTH 8
#define ATOF_0_OUT_FIFO_DEPTH 16
#define ATOF_0_OUT_IRQ -1
#define ATOF_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ATOF_0_OUT_NAME "/dev/atof_0_out"
#define ATOF_0_OUT_SINGLE_CLOCK_MODE 1
#define ATOF_0_OUT_SPAN 4
#define ATOF_0_OUT_SYMBOLS_PER_BEAT 2
#define ATOF_0_OUT_TYPE "altera_avalon_fifo"
#define ATOF_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define ATOF_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define ATOF_0_OUT_USE_AVALONST_SINK 0
#define ATOF_0_OUT_USE_AVALONST_SOURCE 0
#define ATOF_0_OUT_USE_BACKPRESSURE 1
#define ATOF_0_OUT_USE_IRQ 1
#define ATOF_0_OUT_USE_PACKET 1
#define ATOF_0_OUT_USE_READ_CONTROL 0
#define ATOF_0_OUT_USE_REGISTER 0
#define ATOF_0_OUT_USE_WRITE_CONTROL 1


/*
 * data_mem_5 configuration
 *
 */

#define ALT_MODULE_CLASS_data_mem_5 altera_avalon_onchip_memory2
#define DATA_MEM_5_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define DATA_MEM_5_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define DATA_MEM_5_BASE 0x2000
#define DATA_MEM_5_CONTENTS_INFO ""
#define DATA_MEM_5_DUAL_PORT 0
#define DATA_MEM_5_GUI_RAM_BLOCK_TYPE "Automatic"
#define DATA_MEM_5_INIT_CONTENTS_FILE "data_mem_5"
#define DATA_MEM_5_INIT_MEM_CONTENT 1
#define DATA_MEM_5_INSTANCE_ID "NONE"
#define DATA_MEM_5_IRQ -1
#define DATA_MEM_5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DATA_MEM_5_NAME "/dev/data_mem_5"
#define DATA_MEM_5_NON_DEFAULT_INIT_FILE_ENABLED 0
#define DATA_MEM_5_RAM_BLOCK_TYPE "Auto"
#define DATA_MEM_5_READ_DURING_WRITE_MODE "DONT_CARE"
#define DATA_MEM_5_SINGLE_CLOCK_OP 0
#define DATA_MEM_5_SIZE_MULTIPLE 1
#define DATA_MEM_5_SIZE_VALUE 1365u
#define DATA_MEM_5_SPAN 1365
#define DATA_MEM_5_TYPE "altera_avalon_onchip_memory2"
#define DATA_MEM_5_WRITABLE 1


/*
 * etof_0_in configuration
 *
 */

#define ALT_MODULE_CLASS_etof_0_in altera_avalon_fifo
#define ETOF_0_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define ETOF_0_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define ETOF_0_IN_BASE 0x289c
#define ETOF_0_IN_BITS_PER_SYMBOL 16
#define ETOF_0_IN_CHANNEL_WIDTH 8
#define ETOF_0_IN_ERROR_WIDTH 8
#define ETOF_0_IN_FIFO_DEPTH 16
#define ETOF_0_IN_IRQ -1
#define ETOF_0_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ETOF_0_IN_NAME "/dev/etof_0_in"
#define ETOF_0_IN_SINGLE_CLOCK_MODE 1
#define ETOF_0_IN_SPAN 4
#define ETOF_0_IN_SYMBOLS_PER_BEAT 2
#define ETOF_0_IN_TYPE "altera_avalon_fifo"
#define ETOF_0_IN_USE_AVALONMM_READ_SLAVE 1
#define ETOF_0_IN_USE_AVALONMM_WRITE_SLAVE 1
#define ETOF_0_IN_USE_AVALONST_SINK 0
#define ETOF_0_IN_USE_AVALONST_SOURCE 0
#define ETOF_0_IN_USE_BACKPRESSURE 1
#define ETOF_0_IN_USE_IRQ 1
#define ETOF_0_IN_USE_PACKET 1
#define ETOF_0_IN_USE_READ_CONTROL 0
#define ETOF_0_IN_USE_REGISTER 0
#define ETOF_0_IN_USE_WRITE_CONTROL 1


/*
 * etof_0_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_etof_0_in_csr altera_avalon_fifo
#define ETOF_0_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define ETOF_0_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define ETOF_0_IN_CSR_BASE 0x2840
#define ETOF_0_IN_CSR_BITS_PER_SYMBOL 16
#define ETOF_0_IN_CSR_CHANNEL_WIDTH 8
#define ETOF_0_IN_CSR_ERROR_WIDTH 8
#define ETOF_0_IN_CSR_FIFO_DEPTH 16
#define ETOF_0_IN_CSR_IRQ 3
#define ETOF_0_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ETOF_0_IN_CSR_NAME "/dev/etof_0_in_csr"
#define ETOF_0_IN_CSR_SINGLE_CLOCK_MODE 1
#define ETOF_0_IN_CSR_SPAN 32
#define ETOF_0_IN_CSR_SYMBOLS_PER_BEAT 2
#define ETOF_0_IN_CSR_TYPE "altera_avalon_fifo"
#define ETOF_0_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define ETOF_0_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define ETOF_0_IN_CSR_USE_AVALONST_SINK 0
#define ETOF_0_IN_CSR_USE_AVALONST_SOURCE 0
#define ETOF_0_IN_CSR_USE_BACKPRESSURE 1
#define ETOF_0_IN_CSR_USE_IRQ 1
#define ETOF_0_IN_CSR_USE_PACKET 1
#define ETOF_0_IN_CSR_USE_READ_CONTROL 0
#define ETOF_0_IN_CSR_USE_REGISTER 0
#define ETOF_0_IN_CSR_USE_WRITE_CONTROL 1


/*
 * etof_0_out configuration
 *
 */

#define ALT_MODULE_CLASS_etof_0_out altera_avalon_fifo
#define ETOF_0_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define ETOF_0_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define ETOF_0_OUT_BASE 0x2898
#define ETOF_0_OUT_BITS_PER_SYMBOL 16
#define ETOF_0_OUT_CHANNEL_WIDTH 8
#define ETOF_0_OUT_ERROR_WIDTH 8
#define ETOF_0_OUT_FIFO_DEPTH 16
#define ETOF_0_OUT_IRQ -1
#define ETOF_0_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ETOF_0_OUT_NAME "/dev/etof_0_out"
#define ETOF_0_OUT_SINGLE_CLOCK_MODE 1
#define ETOF_0_OUT_SPAN 4
#define ETOF_0_OUT_SYMBOLS_PER_BEAT 2
#define ETOF_0_OUT_TYPE "altera_avalon_fifo"
#define ETOF_0_OUT_USE_AVALONMM_READ_SLAVE 1
#define ETOF_0_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define ETOF_0_OUT_USE_AVALONST_SINK 0
#define ETOF_0_OUT_USE_AVALONST_SOURCE 0
#define ETOF_0_OUT_USE_BACKPRESSURE 1
#define ETOF_0_OUT_USE_IRQ 1
#define ETOF_0_OUT_USE_PACKET 1
#define ETOF_0_OUT_USE_READ_CONTROL 0
#define ETOF_0_OUT_USE_REGISTER 0
#define ETOF_0_OUT_USE_WRITE_CONTROL 1


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK HIGH_SCALE_TIMER_5
#define ALT_TIMESTAMP_CLK none


/*
 * high_scale_timer_5 configuration
 *
 */

#define ALT_MODULE_CLASS_high_scale_timer_5 altera_avalon_timer
#define HIGH_SCALE_TIMER_5_ALWAYS_RUN 0
#define HIGH_SCALE_TIMER_5_BASE 0x2800
#define HIGH_SCALE_TIMER_5_COUNTER_SIZE 32
#define HIGH_SCALE_TIMER_5_FIXED_PERIOD 0
#define HIGH_SCALE_TIMER_5_FREQ 50000000u
#define HIGH_SCALE_TIMER_5_IRQ 2
#define HIGH_SCALE_TIMER_5_IRQ_INTERRUPT_CONTROLLER_ID 0
#define HIGH_SCALE_TIMER_5_LOAD_VALUE 49ull
#define HIGH_SCALE_TIMER_5_MULT 1.0E-6
#define HIGH_SCALE_TIMER_5_NAME "/dev/high_scale_timer_5"
#define HIGH_SCALE_TIMER_5_PERIOD 1
#define HIGH_SCALE_TIMER_5_PERIOD_UNITS "us"
#define HIGH_SCALE_TIMER_5_RESET_OUTPUT 0
#define HIGH_SCALE_TIMER_5_SNAPSHOT 1
#define HIGH_SCALE_TIMER_5_SPAN 32
#define HIGH_SCALE_TIMER_5_TICKS_PER_SEC 1000000u
#define HIGH_SCALE_TIMER_5_TIMEOUT_PULSE_OUTPUT 0
#define HIGH_SCALE_TIMER_5_TYPE "altera_avalon_timer"


/*
 * ins_mem_5 configuration
 *
 */

#define ALT_MODULE_CLASS_ins_mem_5 altera_avalon_onchip_memory2
#define INS_MEM_5_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define INS_MEM_5_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define INS_MEM_5_BASE 0x0
#define INS_MEM_5_CONTENTS_INFO ""
#define INS_MEM_5_DUAL_PORT 0
#define INS_MEM_5_GUI_RAM_BLOCK_TYPE "Automatic"
#define INS_MEM_5_INIT_CONTENTS_FILE "ins_mem_5"
#define INS_MEM_5_INIT_MEM_CONTENT 1
#define INS_MEM_5_INSTANCE_ID "NONE"
#define INS_MEM_5_IRQ -1
#define INS_MEM_5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INS_MEM_5_NAME "/dev/ins_mem_5"
#define INS_MEM_5_NON_DEFAULT_INIT_FILE_ENABLED 0
#define INS_MEM_5_RAM_BLOCK_TYPE "Auto"
#define INS_MEM_5_READ_DURING_WRITE_MODE "DONT_CARE"
#define INS_MEM_5_SINGLE_CLOCK_OP 0
#define INS_MEM_5_SIZE_MULTIPLE 1
#define INS_MEM_5_SIZE_VALUE 4096u
#define INS_MEM_5_SPAN 4096
#define INS_MEM_5_TYPE "altera_avalon_onchip_memory2"
#define INS_MEM_5_WRITABLE 1


/*
 * jtag_uart_5 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_5 altera_avalon_jtag_uart
#define JTAG_UART_5_BASE 0x2860
#define JTAG_UART_5_IRQ 16
#define JTAG_UART_5_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_5_NAME "/dev/jtag_uart_5"
#define JTAG_UART_5_READ_DEPTH 64
#define JTAG_UART_5_READ_THRESHOLD 8
#define JTAG_UART_5_SPAN 8
#define JTAG_UART_5_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_5_WRITE_DEPTH 64
#define JTAG_UART_5_WRITE_THRESHOLD 8


/*
 * timer_5 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_5 altera_avalon_timer
#define TIMER_5_ALWAYS_RUN 0
#define TIMER_5_BASE 0x2820
#define TIMER_5_COUNTER_SIZE 32
#define TIMER_5_FIXED_PERIOD 0
#define TIMER_5_FREQ 50000000u
#define TIMER_5_IRQ 1
#define TIMER_5_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_5_LOAD_VALUE 49999ull
#define TIMER_5_MULT 0.0010
#define TIMER_5_NAME "/dev/timer_5"
#define TIMER_5_PERIOD 1
#define TIMER_5_PERIOD_UNITS "ms"
#define TIMER_5_RESET_OUTPUT 0
#define TIMER_5_SNAPSHOT 1
#define TIMER_5_SPAN 32
#define TIMER_5_TICKS_PER_SEC 1000u
#define TIMER_5_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_5_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
