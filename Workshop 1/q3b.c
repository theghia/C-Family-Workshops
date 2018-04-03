#include <string.h>
#include <stdio.h>

int main() 
{
 int anArray[10];
 int a[10];
 /* code to print out all the values in array a */
 int i = 0;
 for(i; i < 10; i++)
  {
   printf("For index %d: %d\n", i, a[i]);
  }
 anArray[15] = 999;
 /* code to print out all the values in array a */
 int j = 0;
 for(j; j < 10; j++)
  {
   printf("For index %d: %d\n", j, a[j]);
  }
}

/*All of the array values are equal to 0 except*/
/*the 8th index - contains 1*/
/*Then we get segmentation fault (core dumped)*/