#include <string.h>
#include <stdio.h>
#include "verifyPPtr.h"

/*https://stackoverflow.com/questions/13363229/notation-of-argv-in-main-function
https://stackoverflow.com/questions/18649547/how-to-find-the-length-of-argv-in-c
https://stackoverflow.com/questions/21136735/store-argv1-to-an-char-variable
https://www.tutorialspoint.com/cprogramming/c_header_files.htm
https://www.tutorialspoint.com/c_standard_library/c_function_strcpy.htm

Notations for printf %
https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
*/

int main(int argc, char **argv)
{
 printf("\n");
 printf("The amount of arguments at the terminal is: %d\n", argc);
 printf("\n");
 
 printf("Printing out all of the items at the terminal\n");
 int i;
 for(i = 0; i < argc; i++)
 {
  printf("Value number %d is %s\n", i + 1, argv[i]);
 } 
 
 /*Can we hold the string value from the command line in a variable? YES*/
 const char *src = argv[1];
 char typeTest[20];
 strcpy(typeTest, src);
 printf("HOLY COW ---> %s\n", typeTest);
 printf("HOLY COW COW --> %s\n", src);
 
 /* Don't really need to do the above */
 char *test = argv[1];
 printf("YES --> %s\n", test);
 
 
 /*The same way to print of the first item on the command line*/
 printf("FIRST --> %s\n", argv[0]);
 printf("FIRST --> %s\n", *argv);
 
 /*The same way to print of the second item on the command line*/
 printf("SECOND --> %s\n", argv[1]);
 printf("SECOND --> %s\n", *(argv + 1));
 
 /*The same way to get the first character of the second item on the cmd line*/
 printf("SECOND, FIRST CHAR --> %c\n", argv[1][0]);
 printf("SECOND, FIRST CHAR --> %c\n", *argv[1]);
 
 /*Can we get the length of one of the elements in the command line? YES*/
 int length = strlen(argv[1]);
 printf("The length of the 2nd element on the command line is: %d\n", length);
 
 printf("\n");
 verifyFile(argc, length, argv);

}
