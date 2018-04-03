/* Exercise 4 */

#include<stdio.h>

int main(void)
{
	/* part a */
	unsigned short int intArray[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	
	int len = sizeof(intArray)/sizeof(unsigned short int);
	
	int i = 0;
	
	for (i=0; i<len; i++)
		printf("value: %3d, memory address: %p\n", intArray[i], &intArray[i]);
		
	/* part b */
	unsigned short int *ptr;
	ptr = &intArray[0];
	printf("Print using pointers... \n");
	for (i=0; i<len; i++)
	{
		printf("value: %3d, memory address: %p\n", *ptr, ptr);
		ptr++;
	}
	
	return 0;
}
