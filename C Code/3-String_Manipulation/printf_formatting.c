/* An example of using printf statements from the lecture slides */
/* I also will use Workshop 1 to practice the printf statements */

#include <stdio.h>
#include <string.h>

int main() 
{
	
    short int first = 0;
    short int second = 100;
    int third = -123456;
 
    /* The following statements will print the numbers above in a right justified manner */
    printf("Variable 1 is %10d\n", first);
    printf("Variable 2 is %10d\n", second);
	printf("Variable 3 is %10d\n", third);
	
	/* The following statements will print the numbers in a left justified manner */
	printf("Variable 1 now is %-10d\n", first);
    printf("Variable 2 now is %-10d\n", second);
	printf("Variable 3 now is %-10d\n", third);

    char first[4];
    char second[12];
    char third[26];
 
    /* Using the strcpy() function to copy the string to the char array */
    strcpy(first, "tiny");
    strcpy(second, "middle-sized");
    strcpy(third, "absolutely enormously huge");
 
    short int fLne = (strlen(third) - strlen(first))/2;
    short int sLne = (strlen(third) - strlen(second))/2;
 
    /* Using the %*.*s notation to create tab spaces for when the number is not defined yet */
	/* This would have been useful to remember in your coursework as you needed to create different */
	/* tab spaces when printing out the file names */
    printf("%*.*s\n", fLne + strlen(first), strlen(first), first);
    printf("%*.*s\n", sLne + strlen(second), strlen(second), second);
    printf("%s\n", third);
	
	/* You can also use %*s if you only want the width to be defined and not the precision */
	short int practice = 20;
	printf("%*s\n", practice, "This is for practice");
 
    return 0;
}