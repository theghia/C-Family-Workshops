#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler (int);
void sig2_handler(int);

int main(void)
{
    int i;
    int x;
    
    /* If SIGUSR1 is received, then call the function sig_handler */
    if(signal(SIGUSR1, sig_handler) == SIG_ERR)
    {
	printf("\nCan't catch SIGUSR1\n");
    }
	
    sleep(20);
    
    if(signal(SIGFPE, sig2_handler) == SIG_ERR)
    {
        printf("\nCan't catch SIGFPE\n");
    }
    
    for (i = -5; i <= 5; i++)
    {
        x = 10/i;
	printf("%d: x = %d\n", i,x);
    }
    
    printf("Finished\n");

    return 0;
}

void sig_handler(int signo)
{
    if (signo == SIGUSR1)
    {
	printf("Received SIGUSR1\n");
	/*exit(0);*/
		
	/* If SIGUSR1 is received, then call the function sig_handler */
	if(signal(SIGUSR1, sig_handler) == SIG_ERR)
	{
	    printf("\nCan't catch SIGUSR1\n");
	}
    }
}

void sig2_handler(int signo)
{
   if (signo == SIGFPE)
    {
	printf("I have detected an aithmetic error and am giving up\n");
	exit(0);
		
	/* If SIGFPE is received, then call the function sig2_handler */
	if(signal(SIGFPE, sig_handler) == SIG_ERR)
	{
	    printf("\nCan't catch SIGFPE\n");
	}
    }
}
