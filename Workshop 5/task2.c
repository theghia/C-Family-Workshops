#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
	int i;
	int x;
	
	
	for (i = -5; i <= 5; i++)
	{
		x = 10/i;
		printf("%d: x = %d\n", i, x);
	}
	
	printf("Finished\n");
	
	return 0;
}