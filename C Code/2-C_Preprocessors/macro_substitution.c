/* An example of using Macro Substitution */

#include <stdio.h>

/* Careful use of brackets because the arguments X and Y might not just be */
/* normal numbers but actually evaluations to be done */
#define add(X, Y) ( (X) + (Y) ) 

int main(void)
{
    int added = add(3+3,5*5); /* Evaluations instead of just numbers */
	
	printf("%d\n", added); /* Should print out 31 */
	
	return 0;
}