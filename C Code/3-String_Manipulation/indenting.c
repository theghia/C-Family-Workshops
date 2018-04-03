#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  printf("%*s", 6, "hello\n");
  printf("%*s", 7, "hello\n");
  printf("%*s", 8, "hello\n");
  printf("%*s", 10, "hello\n");
  printf("%*s", 15, "hello\n");
  
  int orderNum = 12;
  char *fileNum;
  sprintf(fileNum, "%d", orderNum);
  
  char *dummy = "Hello";
  char dum[81] = " ";
  strcat(dum, dummy);
  printf("%s\n", dum);
  strcat(fileNum, dum);
  
  printf("WHAT --> %s\n", fileNum);
  
  return 0;
}
