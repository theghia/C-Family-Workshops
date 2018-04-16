/* Example code to show how to use bit fields */

#include "bit_fields.h"

int main (void)
{
	struct textflags mytext;
	struct rgbcolour scarlet;
	
	mytext.bold      = 1;
	mytext.italic    = 0;
	mytext.underline = 1;
	
	/* NOTE: char is one byte */
	printf("sizeof(mytext) = %d; mytext = %d\n", 
	sizeof(mytext), mytext);
	
	scarlet.red   = 15;
	scarlet.green = 0;
	scarlet.blue  = 0;
	
	/* NOTE: unsigned short int is 2 bytes */
	printf("sizeof(scarlet) = %d; scarlet = %d\n",
	sizeof(scarlet), scarlet);
	
	return 0;
}