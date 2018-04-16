/* Header for example code on using bit fields */
#ifndef __BITFIELDS_H
#define __BITFIELDS_H

#include <stdio.h>

/* This allows us to address smaller units of memory than one byte */
struct textflags
{
	unsigned char bold      : 1;
	unsigned char italic    : 1;
	unsigned char underline : 1;
};

/* However, it does not have to be just one bit */
struct rgbcolour
{
	unsigned short int red   : 4;
	unsigned short int green : 4;
	unsigned short int blue  : 4;
};

#endif