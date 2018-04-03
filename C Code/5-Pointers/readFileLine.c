#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*http://c-for-dummies.com/blog/?p=1112 has more info
  https://stackoverflow.com/questions/3501338/c-read-file-line-by-line*/

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    /*fp = fopen("/etc/motd", "r");*/
    fp = fopen("monarchs.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
	
	/*A way to only get the characters that are not blank spaces*/
	int i;
	int j = 0;
	
	/*To reset the chars put into the royalty var*/
	char royalty[read];
	for (i = 0; i < read - 1; i++) {
	
	/*The following chars are not blank spaces - added to royalty*/
	  if (*(line + i) != ' ') {
	    royalty[j] = *(line +i);
	    j++;
	  } 
	}
	/*Since we've been adding chars, we need to include a null terminator*/
	royalty[j] = '\0';
	
	/*To check the output - correct (5th Feb 2018)*/
	printf("Without BLANK SPACES: %s\n", royalty);
	printf("Length of the string: %d\n", strlen(royalty));
	
	/*Debugging statement*/
	printf("The last char of the new string is: %c\n", royalty[strlen(royalty) - 1]);
    }

    /*To let go of the lock*/
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}
