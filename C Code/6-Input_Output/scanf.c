/* An example to show how to use scanf */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char firstName[11];
	char lastName [11];
	
	printf("What is your first and last name? ");
	
	if ( scanf("%10s %10s", firstName, lastName) == 2 )
	{
	    printf( "So your first name is: %s\n", firstName );
		printf( "And your last name is: %s\n", lastName  );
	}
	else
	{
		printf("You have entered the wrong thing\n");
	}
	
	return 0;
	/* Now what if you do not know the size of the string? Check this: */
	/* https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length */
}