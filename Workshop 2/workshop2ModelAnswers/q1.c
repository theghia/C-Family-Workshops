/* Exercise 1 */

#include <stdio.h>

#define MYNUMBER 8

/* function prototypes */
int factorialLoop      (int);
int factorialRecursive (int);

int main ()
{
   printf("With loop: %d! = %d\n",MYNUMBER,factorialLoop(MYNUMBER));
   printf("With recursion: %d! = %d\n",MYNUMBER,factorialRecursive(MYNUMBER));
}

int factorialLoop (int n)
{
   int   nfactorial = 1;
   int   i;

   for (i=1; i<=n; i++)
      nfactorial = nfactorial * i;

   return nfactorial;
}

int factorialRecursive (int n)
{
   if (n==1)
      return n;
   else
      return n * factorialRecursive(n-1);
}
