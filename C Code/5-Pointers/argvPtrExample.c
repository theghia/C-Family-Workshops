#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
 int numArg = sizeof(argv);
 printf("The amount of bytes that pointer *argv[] takes is: %d\n", numArg);
 printf("The legit value at argv[] is: %s\n", argv);
 printf("The amount of arguments at the terminal is: %d\n", argc);
 
 int i;
 for(i = 0; i < argc; i++)
 {
  printf("Value number %d is %s\n", i + 1, argv[i]);
 } 

}
