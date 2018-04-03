/* Exercise 5 */
#include<stdio.h>

/* function prototype */
int updateInteger (int *);

int main (void)
{
	int anInt = 0;
	
	printf("Print integer value before addition: %d\n", anInt);
	
	updateInteger(&anInt);
	
	printf("Print integer value after addition: %d\n", anInt);	
	
	return 0;
}

/* function implementation */
int updateInteger(int *p)
{
	*p = *p + 3;
}
