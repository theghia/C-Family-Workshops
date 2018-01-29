#include <stdio.h>

void updateInteger(int *);

int main()
{
 int a = 3;
 printf("Starting with the variable 'a' that holds the int: %d\n", a);
 
 updateInteger(&a);
 printf("Updating the variable a...\n");
 printf("...\n");
 
 printf("Now 'a' holds: %d\n", a);
 
 return 0;
}

void updateInteger(int *ch)
{
 *ch += 3;
}
