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
 
 /*Remember tha 0 is false in a condition*/
 if (!strcmp(last4, ".txt"))
  return TRUE;
 else
  return FALSE;
}

void verifyFile(int numArguments, int length, char **argument)
{
  switch (numArguments)
 {
   case 2:
     printf("Verifying if it is a text file..\n");
     
     if (isFileName(argument[1], length) == TRUE)
       printf("Your text file is: %s\n", argument[1]);
       
     else
       printf("Not in the right format\n"); 
          
   break;
   
   case 1: 
     printf("Type a text file name please\n");
   break;
   
   default: 
     printf("Only one text file please\n");
 }

}
