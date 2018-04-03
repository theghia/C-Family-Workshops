#include <stdio.h>
#include <string.h>

char *makeLabelTop(char *, int);

int main (void)
{
  char *why = "File";
  int ord = 1;
  const char *hold = makeLabelTop(why, ord);
  printf("WORK --> %s\n", hold);  
  
  char *testing = malloc(23*sizeof(char));
  testing = "hello";
  
  return 0;
}

/* Mini function to get 1 File or 2 USSR */
char *makeLabelTop(char *menuLabel, int orderNum)
{
  char *toReturn = malloc(81*sizeof(char));
  char *newLabel[81];
  sprintf(newLabel, "%d", orderNum);
  
  /* To give a space in between the number and label item */
  int i = strlen(newLabel); int j;
  newLabel[i] = ' '; i ++;
  
  for (j = 0; j < strlen(menuLabel); j++)
  {
	  newLabel[i] = menuLabel[j];
	  i++;
  }
  newLabel[i] = '\0';
  
  for ( i = 0; i < strlen(newLabel); i++)
  {
	  toReturn[i] = newLabel[i];
  }
  return toReturn;
}