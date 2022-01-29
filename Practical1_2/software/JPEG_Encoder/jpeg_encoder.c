/*************************************************************************************
 * CO503 Advanced Embedded Systems
 *
 * Date			: 16-08-2016
 * Author 		: Isuru Nawinne
 * Edited by	:
 *
 * Description	: Compress and convert a BMP image file into JPEG format
 *
 *************************************************************************************/

#include "application/jpeg_encoding.h"
#include "application/bmp_extract.h"


#include<stdio.h>
#include<stdint.h>
#include<io.h>
#include<unistd.h>

#define LED_BASE 0x09001000
#define OFFSET 0x00000000

/*8-bit loop counter*/
static uint8_t count;

#define NO_OF_FILES 7

void convert_picture(const char *jtag_input);

int main()
{
	char jtag_input[20];

	// Print that welcome message. Programmers looove welcome messages! ;)
	printf("CO503 JPEG Encoder \n\n");



	while(1) {
		printf("Input file: ");
		scanf("%s", jtag_input); // Ask for the input BMP file

		// Check if the filename ends in '.bmp'
		if(strcmp(&jtag_input[strlen(jtag_input) - 4], ".bmp") == 0) {

			count = 0xC0;
			IOWR_8DIRECT(LED_BASE,OFFSET,count);
			usleep(1000000);

			convert_picture(jtag_input); // See function at the bottom

		}
		printf("\n\n");
	}

	return 0;
}

/*
 * Convert a BMP picture of name <jtag_input> into JPEG.
 */
void convert_picture(const char *jtag_input)
{
	char file_name[80] = "/mnt/host/files/";
	char destination[80] = "/mnt/host/files/";
	Bmp_data pic_data;

	strcat(file_name, jtag_input);
	strcat(destination, jtag_input);


	count = 0xF0;
	IOWR_8DIRECT(LED_BASE,OFFSET,count);
	usleep(1000000);

	// Replace the '.bmp' with '.jpg'
	strcpy(&destination[strlen(destination) - 3], "jpg");

	int i=0;
	if(bmp_extract(file_name, &pic_data) == 0) {
		// Convert to JPEG. This is where the magic happens!

		count = 0xFC;
		IOWR_8DIRECT(LED_BASE,OFFSET,count);
		usleep(1000000);

		jpeg_encode(destination, pic_data.bitmap, pic_data.header->BMPHeight, pic_data.header->BMPWidth, 90);

		count = 0xFF;
		IOWR_8DIRECT(LED_BASE,OFFSET,count);
		usleep(1000000);

	} else {
		printf("Error\n");
	}
}
