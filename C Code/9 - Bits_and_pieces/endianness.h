/* Header file to aid the example of determining the endian-ness of a machine */
#ifndef __ENDIANNESS_H
#define __ENDIANNESS_H 

#include <stdio.h>

/********************************/
/*    Declaring structures      */
/********************************/

struct mybits
{
	unsigned char b7 : 1;
	unsigned char b6 : 1;
	unsigned char b5 : 1;
	unsigned char b4 : 1;
	unsigned char b3 : 1;
	unsigned char b2 : 1;
	unsigned char b1 : 1;
	unsigned char b0 : 1;
};

union myunion
{
	struct mybits bits;
	char ch;
};

/**********************************/
/* Declaring function prototypes  */
/**********************************/

void printByte (struct mybits);

#endif