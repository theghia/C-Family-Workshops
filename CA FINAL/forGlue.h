#ifndef __FORGLUE_H
#define __FORGLUE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*****************************************************************************/
/* Function prototypes - to aid the glue function to keep track of the label */
/*****************************************************************************/
int countDots  (char *);
char* trimDots (char *, FILE **);
int firstDot   (char *);
int twoDot     (char *);
int getOrderNum(char *);

/*****************************************************************************/
/* Function: getOrderNumber                                                  */
/*    Returns the order number of the parent NODE from the current NODE's    */
/*    label. Works for all NODEs except the Top level NODEs                  */
/* Parameters:                                                               */
/*    numLabel       The label that the NODE has - the string to be read     */
/* Returns:                                                                  */
/*    The integer before the dot character                                   */
/*****************************************************************************/
int getOrderNum (char *label)
{
  int newOrdNum;
  if ( countDots(label) > 1 )
    newOrdNum = twoDot(label);
  else if (countDots(label) == 1)
    newOrdNum = firstDot(label);
  else
    newOrdNum = atoi(label);
  return newOrdNum;
}

/*****************************************************************************/
/* Function: twoDot                                                          */
/*    Reads the string and get the number in between the second to last dot  */
/*    and the last dot. This number represents the order that the parent     */
/*    of the current node is in terms of its siblings for all NODEs except   */
/*    the Top level NODEs and the first generation of children NODES         */
/* Parameters:                                                               */
/*    numLabel       The label that the NODE has - the string to be read     */
/* Returns:                                                                  */
/*    The integer in between the second to last dot and the last dot         */
/*****************************************************************************/
int twoDot(char *numLabel)
{
  int totalDots = countDots(numLabel);
  int count = 0; int j = 0;
  int i;
  char orderNum[5];
  
  for ( i = 0; i < strlen(numLabel); i++)
  {
	if ( numLabel[i] == '.' )
		count++;
	else if ( count == (totalDots - 1) )
	{
		orderNum[j] = numLabel[i];
		j++;
	}
  }
  orderNum[j] = '\0';
  return atoi(orderNum);
}

/*****************************************************************************/
/* Function: firstDot                                                        */
/*    Reads the string and returns the number before the first dot character */
/* Parameters:                                                               */
/*    numLabel       The label that the NODE has - the string to be read     */
/* Returns:                                                                  */
/*    The integer before the dot character                                   */
/*****************************************************************************/
int firstDot(char *numLabel)
{
  char num[4];
  int i = 0; int j = 0;
  int found = 0; /* false */ 
  
  for (i; i < strlen(numLabel); i++)
  {
    if (found) /*  We want to get the numbers after the dot */
    {
      num[j] = numLabel[i];
      j++;
    }
    
    if ( numLabel[i] == '.' )
      found = 1;
  }
  num[j] = '\0';
  return atoi(num);
} 

/*****************************************************************************/
/* Function: countDots                                                       */
/*    Reads a string and determines the amount of dot characters in it       */
/* Parameters:                                                               */
/*    numLabel       The label that the NODE has - the string to be read     */
/* Returns:                                                                  */
/*    An integer that is the amount of dots found in the string              */
/*****************************************************************************/
int countDots(char *numLabel)
{
  int count = 0; int i;
  for (i = 0; i < strlen(numLabel); i ++)
  {
    if (numLabel[i] == '.')
      count ++;
  }
  return count;
}

/*****************************************************************************/
/* Function: trimDots                                                        */
/*    Trims the characters from the second to last dot found in the string   */
/* Parameters:                                                               */
/*    numLabel       The label that the NODE has - the string to be read     */
/*    p_fp        The file pointer in case we get an error and want to close */
/*                the input file before exiting.                             */
/* Returns:                                                                  */
/*    A string that does not contain the characters from the second to last  */
/*    dot and onwards                                                        */
/*****************************************************************************/
char *trimDots(char *numLabel, FILE **p_fp)
{
  int totalDots = countDots(numLabel);
  char *headLabel;
   
  if ( totalDots > 1 )
  {
    if (!(headLabel = (char *)malloc(16*sizeof(char))) )
    {
      printf("Out of memory\n");
      fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
      fclose(*p_fp);
      exit(1);
    }
    int  count = 0; 
    /* The cut off line for the characters to be read */
    int  cutOff = totalDots - 2;
    /* To go through both the headLabel and numLabel char arrays */
    int  j = 0; int i = 0;
    while ( count <= cutOff)
    {
       if (numLabel[i] == '.')
       {
         if ( count < cutOff)
	 {
	   headLabel[j] = numLabel[i];
	   j++; 
	 }
         count++; i++;
       }
       
       else
       { 
         headLabel[j] = numLabel[i];
         i++; j++;   
       }  
    }
    i--;
    headLabel[i] = '\0';
  }
  
  else if (totalDots == 1)
  {
    if (! (headLabel = (char *)malloc(5*sizeof(char))) )
    {
      printf("Out of memory\n");
      fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
      fclose(*p_fp);
      exit(1);
    }
    int i = 0;
    while ( numLabel[i] != '.')
    {
      headLabel[i] = numLabel[i];
      i++;
    }
    headLabel[i] = '\0'; 
  }
  
  else
    headLabel = NULL;
  return headLabel;
}

#endif
