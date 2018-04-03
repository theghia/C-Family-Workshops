#include <stdio.h>
#include <string.h>

int main() 
{
 char first[19];
 char second[19];
 char third[26];
 
 strcpy(first, "small");
 strcpy(second, "middle-sized");
 strcpy(third, "absolutely enormously huge");
 
 printf("*%-19s*\n", first);
 printf("*%-19s*\n", second);
 printf("*%-19.19s*\n", third);
 
}