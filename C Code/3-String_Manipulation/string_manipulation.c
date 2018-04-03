/* An example of using functions from the string.h library */

#include <stdio.h>
#include <string.h>

int main(void)
{
    /* A pointer to the character array. This is not a string copy */
	char *pmessage = "now is the time"; 
	
	/* An array that is just big enough to hold the sequence */
	/* of characters and '\0' that initialises it */
	char amessage[] = "now is the time"; 
	
	/* Now going to use strcpy */
	char *pmessage2;
	char amessage2[20];
	
	strcpy( pmessage2, "now is the time" );
	strcpy( amessage2, "now is the time" );


    return 0;
}