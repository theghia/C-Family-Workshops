/* An example of using flow control that C provides the programmer with */

#include <stdio.h>

int main(void)
{
	/* Trying to improve my behaviour in using less memory */
    char a = 8;
	char b = 4;
	
	/* Just one of the expressions is true, but that is all the OR operand */
	/* needs to be evaluated as true */
	if ( a == 3 || b == 4 )
	{
		printf("%s\n", "Should print!! Using OR");
	}

	/* In an AND statement, both expressions need to evaluate as true */
	if ( a < 6 && b >23 )
	{
		printf("%s\n", "Should not print here!! Using AND");
	}
	else
	{
		printf("%s\n", "After the statement has evaluated as false, this should print");
	}
	
	/* The difference between bitwise AND (&) and AND (&&) */
	printf("a & b = %d\n", a & b);
	printf("a && b = %d\n", a && b);
	
    return 0;
}