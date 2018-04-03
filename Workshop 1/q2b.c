#include <stdio.h>

int main() 
{
 double anArray[3] = {0, 100.123, -123456.7891};
 
 printf("%+10.2f\n", anArray[0]);
 printf("%+10.2f\n", anArray[1]);
 printf("%10.2f\n", anArray[2]);
 
}