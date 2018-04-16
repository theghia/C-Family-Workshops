/* Example code to show how to determine the endian-ness of a machine */

#include "endianness.h"

int main (void)
{
	union myunion u;
	
	u.ch = 1;
	printf("%d = ", u.ch);
	printByte(u.bits);
	
	return 0;
}

void printByte (struct mybits bits)
{
	printf("%d%d%d%d%d%d%d%d\n", bits.b7, bits.b6, bits.b5,
	bits.b4, bits.b3, bits.b2, bits.b1, bits.b0);
}