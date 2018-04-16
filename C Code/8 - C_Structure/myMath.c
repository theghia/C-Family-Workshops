/* An example to show how to use the math library in C */

#include <stdio.h>
#include <math.h>

/* For this code to compile, you need to tell the linker to link */
/* in the "math" library (Look at the script in this directory) */
int main (void)
{
	float radians = 1.345;
	
	/* The cos function comes from the math.h file */
	printf("cos(%f) = %f\n", radians, cos(radians));
	
	return 0;
}