#include <stdio.h>
#include <string.h>

int main()
{
 char singleVar[] = "";
 char first[] = "";
 char second[] = "";
 char third[] = "";
 
 strcpy(singleVar, "Hello World!");
 strcat(singleVar, "test");
 strcat(singleVar, "Elephants");
 
 printf("%s\n", singleVar);
 
 int i = 0;
 for(i; i<25; i++)
  {
   if (i < 12)
    strcat(first, singleVar[i]);
   if (i >= 12 && i < 15)
    strcat(second, singleVar[i]);
   else
    strcat(third, singleVar[i]);
  }
  
  printf("%s\n", first);
  printf("%s\n", second);
  printf("%s\n", third);

 return 0;
}