/* Exercise 6 */

#include<stdio.h>
#include<stdlib.h>

int main (int argc, char** argv) 
/* (number_of_arguments, array_of_string_values)*/
{
	int len = atoi(argv[1]);
	short int *p = NULL;
	p = (short int *) malloc (len*sizeof(short int)); /* Dynamic allocation */
	int i = 0;
	
	/* Populate array */
	for(i = 0; i<len; i++)
		*(p+i) = (short int)(i+1);	
	
	/* Print values */
	for (i=0; i<len; i++)
		printf("The value is %d at address %p\n", *(p+i), (p+i));

	/* Free memory */
	free(p);
	
	return 0;
	
}

