#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void sig_handler(int);

int main(void)
{
	/* If SIGUSR1 is received, then call the function sig_handler */
	if(signal(SIGUSR1, sig_handler) == SIG_ERR)
	{
		printf("\nCan't catch SIGUSR1\n");
	}
	
	/* A long long wait so that we can easily issue a signal to this process */
	while(1)
	{
		/* Does not use as much CPU time as an infinite while loop */
		sleep(1);
	}
	printf("Finished\n");
	
	return 0;
}

void sig_handler(int signo)
{
	/* Variable continues to exist after this method has been called */
	static int count = 0;
	if (signo == SIGUSR1)
	{
		printf("Received SIGUSR1\n");
		count++;
		
		if (count >= 3)
		{
			printf("Ok, 3 times is enough\n");
			exit(0);
		}
		
		/* If SIGUSR1 is received, then call the function sig_handler */
		if(signal(SIGUSR1, sig_handler) == SIG_ERR)
		{
			printf("\nCan't catch SIGUSR1\n");
		}
	}
}