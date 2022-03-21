/*
 * 	FIFO queue for shared memory communication between niosII processors
 *
 *  	DATE		: 18-08-2016
 *      AUTHOR	: Isuru Nawinne
*
*	Structure of the FIFO:
*	___________________________________________________________________________
*	| 	full	| 	empty	| 	count		|	|	|	|	|	|	|	|	|
*	| 	?	| 	?		| 	?		|	|	|	|	|	|	|	|	|
*	___________________________________________________________________________
*/


#include "FIFO_1.h"


void WRITE_FIFO_1(int *buffer)
{
	// Wait if the fifo is full
	while(fullp){}

	// Write the data to FIFO
	IOWR_32DIRECT(MEM_BASE,writep,buffer);

	// Update the write pointer
	writep += 0x4;

	// Update "count" in shared mem
	IOWR_32DIRECT(MEM_BASE, countp, IORD_32DIRECT(MEM_BASE,countp) + 0x1);

	// Update the "full?" and "empty?" flags accordingly
	// Set the full flag if FIFO is now full
	// Reset the empty flag if FIFO now has 1 entry
}


void READ_FIFO_1(int *buffer)
{
	// Wait if the fifo is empty
	while(emptyp){}

	// Read the data
	IOWR_32RD(MEM_BASE,readp,buffer);

	// Update the read pointer
	readp += 0x4;

	// Update "count" in shared mem
	IOWR_32DIRECT(MEM_BASE, countp, IORD_32DIRECT(MEM_BASE,countp) - 0x1);

	// Update the "full?" and "empty?" flags accordingly
	// Set the empty flag if FIFO is now empty
	// Reset the full flag if FIFO now has 1 entry less than capacity
}



//Initialization
void FIFO_1_INIT()
{
	writep = STARTP; // Initially the FIFO is empty, so start writing at the first slot
	readp  = STARTP;
	fullp   = MEM_BASE; // SET THIS OFFSET (If there are previous FIFOs in shared memory, use Prev Fifo's STARTP + Prev Fifo's size)
	emptyp   = fullp + 0x4;
	countp  = emptyp + 0x4;

	// Assigning values for the flags.
	IOWR_32DIRECT(MEM_BASE, fullp, 0x0);
	IOWR_32DIRECT(MEM_BASE, emptyp, 0x0); // The fifo is empty at the start
	IOWR_32DIRECT(MEM_BASE, countp, 0x0); // The fifo is empty at the start
}
