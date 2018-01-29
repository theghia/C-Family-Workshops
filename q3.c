#include <stdio.h>

int main()
{
 /*When running the program several times, the memory address keeps changing
 but the memory address of x and xPtr remain the same */
 
 short int x = 4;
 
 printf("The value of x is: %d\n", x);
 
 printf("The memory address at which x is stored in is: %d\n", &x);
 
 short int *xPtr = &x;
 
 *xPtr = 6;
 
 printf("The new value of x using xPtr is: %d\n", *xPtr);
 
 printf("The memory address of where xPtr is stored is: %d\n", &xPtr);
 
 /*the value stored in x should have changed now*/
 printf("Just verifying that the value of x has been updated to %d\n",x);
 
 return 0;
}
