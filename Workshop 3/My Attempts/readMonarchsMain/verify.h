#ifndef __VERIFY_H
#define __VERIFY_H

#include <string.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

int isFileName(char fileName[], int length)
{
 /*This will hold the ".txt" part*/
 char last4[4];
 
 int counter;
 for (counter = 4; counter > 0; counter--)
 {
  /*Starting from the 4th to last element in the char array*/
  int slice = length - counter;
  
  /*Assigning the last 4 char elements found in the string to last4*/
  last4[4 - counter] = fileName[slice];
 }
 
 /*Remember that 0 is false in a condition*/
 if (!strcmp(last4, ".txt"))
  return TRUE;
 else
  return FALSE;
}

int verifyFile(int numArguments, int length, char **argument)
{
  switch (numArguments)
 {
   case 2:
     printf("Verifying if it is a text file..\n");
     
     if (isFileName(argument[1], length) == TRUE)
	 {
		printf("Your text file is: %s\n", argument[1]);
        return TRUE;		
	 } 
     else {
		printf("Not in the right format\n");
        return FALSE;		
	 }

   default: 
     printf("Type in only one text file please\n");
	 return FALSE;
 }

}

#endif