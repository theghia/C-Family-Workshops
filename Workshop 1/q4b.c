#include <stdio.h>
#include <string.h>

/*This one works*/
int main()
{
 char oneVar[][13] = {"Hello World!", "test", "Elephants"};

 /*we need the second array to be of size 13 to have the /0 operator
 so that we don't print out "test" along with "Hello World!" */
 
 printf("%s\n", oneVar[0]);
 printf("%s\n", oneVar[1]);
 printf("%s\n", oneVar[2]);
 
 return 0;
}