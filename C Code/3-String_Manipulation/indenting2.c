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
  
  char *practice = "1.3.1 Text";
  int lengthStr = strlen(practice);
  printf("%d\n", lengthStr);
  char label[81];
  int i = 0;
  printf("wink\n");
  while (practice[i] != ' ')
  {
    label[i] = practice[i];
    printf("hi\n");
    i++;
  }
  label[i] = ' '; i++;
  label[i] = '\0';
  printf("%s\n", label);
  
  char newLabel[81];
  int ord = 1;
  sprintf(newLabel, "%d", ord);
  newLabel[strlen(newLabel)] = ' ';
  
  strcat(newLabel, "why");
  
  
  printf("%s\n", newLabel); fflush(stdout);
  
  int j = 0;
  char *dummy2 = "A string";
  printf("%c\n", dummy2[3]); fflush(stdout);
  char newNewLabel[81];
  printf("%d\n", strlen(dummy2));
  /*for (j; j < strlen(dummy2); j++)
  {
  }*/
    /*newNewLabel[j] = dummy2[j];*/
  
  
  return 0;
}
