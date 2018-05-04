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
	if (signo == SIGUSR1)
	{
		printf("Received SIGUSR1\n");
		exit(0);
		
		/* If SIGUSR1 is received, then call the function sig_handler */
		if(signal(SIGUSR1, sig_handler) == SIG_ERR)
		{
			printf("\nCan't catch SIGUSR1\n");
		}
	}
}