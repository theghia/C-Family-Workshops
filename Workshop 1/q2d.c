#include <stdio.h>
#include <string.h>

int main() 
{
 char first[4];
 char second[12];
 char third[26];
 
 strcpy(first, "tiny");
 strcpy(second, "middle-sized");
 strcpy(third, "absolutely enormously huge");
 
 short int fLne = (strlen(third) - strlen(first))/2;
 short int sLne = (strlen(third) - strlen(second))/2;
 
 
 printf("%*.*s\n", fLne + strlen(first), strlen(first), first);
 printf("%*.*s\n", sLne + strlen(second), strlen(second), second);
 printf("%s\n", third);
 
 return 0;
 
}