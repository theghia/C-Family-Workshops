#include <string.h>
#include <stdio.h>

int main() 
{
 char array2[5] = {'A','B','C','D','E'};
 int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
 int anArray[10];
 int a2[2][3] = { {1, 2, 3} , {4, 5, 6} };
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