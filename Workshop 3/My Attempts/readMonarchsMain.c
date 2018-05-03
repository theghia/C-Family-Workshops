#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "verify.h"
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
 
 switch (argc)
 {
   case 2:
     printf("Verifying if it is a text file..\n");
     
     /*For some reason it reads the length one less than it should*/
     int length = (sizeof(argv[1])/sizeof(char)) + 1;
     
     if (isFileName(argv[1], length) == TRUE)
       printf("Your text file is: %s\n", argv[1]);
       
     else
       printf("Not in the right format\n"); 
          
   break;
   
   case 1: 
     printf("Type a text file name please\n");
   break;
   
   default: 
     printf("Only one text file please\n");
     
 }
 
 
 /*char textFile[15];
  printf("Type something\n");
 if ( scanf("%s", textFile) == 1 )
  printf("You typed the following: %s", textFile);
 else
  printf("you entered the wrong thing");*/
  
  verifyFile(argc, (sizeof(argv[1])/sizeof(char)), argv);
  
  return 0;
}

