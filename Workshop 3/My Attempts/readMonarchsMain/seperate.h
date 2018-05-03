#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getYear(char *);
char * getName(char *);

/*Get the last 4 items in the last and convert to an int using*/
int getYear(char * noSpace)
{
  char year[4];
  int length = strlen(noSpace);
  int i;
  
  for (i = 4; i > 0; i--)
  {
    year[4 - i] = noSpace[length - i];
  }
  
  
  return atoi(year);
}
/*Get everything bar the last 4 elements*/ 
char * getName(char * noSpace)
{
  int limit = strlen(noSpace) - 4;
  char *name = (char *)malloc(sizeof(char) * (limit+1));
  int i;
  
  for (i = 0; i<limit;i++)
  {
    name[i] = noSpace[i];
  }
  name[i] = '\0';
  
  return name;
}

