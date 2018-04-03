#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int j = 0;
  char *dummy2 = "1.2";
  char newLabel[81];
  printf("%d\n", strlen(dummy2));
  for (j; j < strlen(dummy2); j++)
    newLabel[j] = dummy2[j];
  
  newLabel[j] = '.';
  printf("%s\n", newLabel);
  
  int hold = 4;
  char holdUp[5];
  sprintf(holdUp, "%d", hold);
  strcat(newLabel, holdUp);
  newLabel[strlen(newLabel)] = '\0';
  printf("%s\n", newLabel);
    
}
