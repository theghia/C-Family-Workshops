#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getLabel(char *);

int main(void)
{
  char *practice = malloc(6*sizeof(char));
  practice[0] = '1';
  practice[1] = ' ';
  practice[2] = 'F';
  practice[3] = 'i';
  practice[4] = 'l';
  practice[5] = 'e';
  practice[6] = '\0';
  printf("%s\n", practice);
  char *hold = getLabel(practice);
  printf("Should be the number part: %s\n", hold);
  return 0;
}

/*****************************************************************************/
/* Function: getLabel                                                        */
/*    Returns the newly formed number part of the label of parent NODEs      */
/* Parameters:                                                               */
/*    fullLabel   The full label of the NODE - the number and name           */
/* Returns:                                                                  */
/*    A string that contains the file number of the parent                   */
/*****************************************************************************/
char *getLabel(char *fullLabel)
{
  char *label = malloc(21*sizeof(char));
  int i = 0;

  for(i; i < strlen(fullLabel); i++)
  {
    if (fullLabel[i] == ' ')
      break;
    else
      label[i] = fullLabel[i];
  }
  label[i] = '\0';
  return label;
}
