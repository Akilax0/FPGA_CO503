/*
 * 	Template of consumer application using FIFO
 *
 *  	DATE		: 18-08-2016
 *      AUTHOR	: Isuru Nawinne
 */


#include "FIFO_1.h"


void delay(int n);
int consumer();


int main()
{
	consumer();
	
	while(1) { }
//	printf("consumer starting..\n");
//	printf("Sent number: %i\n",IORD_32DIRECT(MEM_BASE,readp));
//	printf("Data received\n");
//	while(1){}
	return 0;
}


int consumer()
{
	alt_u32 hw_fast_timeA, hw_fast_timeB;
	printf("Consumer starting..\n");

	FIFO_1_INIT(); // Initialize the producer-consumer fifo

	int j = 0;
	int k = 5;
	hw_fast_timeA = alt_timestamp();
	while(k<500)
	{
		READ_FIFO_1(&j);  // Read from the producer-consumer fifo
		if(j==k)
			printf("Consumer succefully received [%i]\t%x\n",j,readp);


		k+=10;
	}
	hw_fast_timeB = alt_timestamp();
	printf("Time for Read operation: %lu\n",(unsigned long)(hw_fast_timeB-hw_fast_timeA));
	printf("Consumer finished..\n");
	return 0;
}


void delay(int n)
{
	int i;
	for(i=n; i>0; i--)
	{
		continue;
	}
}
