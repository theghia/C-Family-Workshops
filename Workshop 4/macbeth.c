/* The main file to execute the code */

#include "genericFunctions.h"
#include "macbeth.h"

int main( int argc, char **argv)
{

    FILE *fp;
    
    int lines = numberOfLines(&fp, argv[1]);
    int words = numberOfWords(&fp, argv[1]);
    int acts  = numberOfActs (&fp, argv[1]);
    
    printf("The number of lines are: %d\n", lines);
    printf("The number of words are: %d\n", words);
    printf("The number of acts are : %d\n", acts);
    
    scenaryInformation(&fp, argv[1]);
    CHARAC *use = processFile(&fp, argv[1]);
    printf("First in list: %s, No: %d\n", use->name, use->numberOfAppearances);
    
    printList(use);

    return 0;
}



CHARAC *processFile(FILE **p_fp, char *p_filename)
{
    /* The root node of the linked list */
    CHARAC *root = NULL; 

    /* Defensive programming */
    if( ( *p_fp = fopen (p_filename, "r") ) == NULL )
    {
        printf("Unable to open file for read access\n");
	fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
	exit(1);
    }
    
    /* The name of the character with all capital letters */
    char foundName[21];
    
    /* While we have not reached the end of the file... */
    while( !feof(*p_fp) )
    {
        /* Storing a string read in from stream */
        /*fgets(foundName, 20, *p_fp);
	foundName[20] = '\0';*/
	fscanf(*p_fp,"%20s",foundName);
	
	/* Checking for a capital letters */
	int i; int numCap = 0;
	for(i = 0; i < strlen(foundName); i++)
	{
	    /* Adding unique names to the linked list */
	    if(foundName[i] >= 65 && foundName[i] <= 90)
	    {
		numCap++;
	    }
	}
	
	/* Checking if the word is all capital */
	if( numCap == strlen(foundName) && numCap > 3 && strcmp(foundName,"SCENE") )
	    {
	        addUniqueCharacter(&root, foundName, p_fp);
		/*printf("%s\n", foundName);*/
	    }
    
    }
    
    fclose(*p_fp);
    
    return root;
}





void addUniqueCharacter(CHARAC **root, char *name, FILE **p_fp)
{
    CHARAC *r = *root;
    
    while ( r != NULL && r -> next != NULL && strcmp(name, r -> name))
    {
        r = r -> next;
    }
    
    if ( r == NULL )
    {
        CHARAC *uniqueCharacter = newChar(name, p_fp);
	*root = uniqueCharacter;
    }
    
    /* If the name has not been found before */
    else if ( strcmp(name, r -> name) )
    {
        CHARAC *uniqueCharacter = newChar(name, p_fp);
	r -> next = uniqueCharacter;
    }
    
    /* If the name has been found - increment the counter */
    else if ( !strcmp(name, r -> name) )
    {
        r -> numberOfAppearances += 1;
    }

    
}








CHARAC *newChar(char *name, FILE **p_fp)
{
    CHARAC *charac;
    
    /* Checking if memory was allocated successfully */
    if( !(charac = (CHARAC *)malloc(sizeof(CHARAC))))
    {
        printf("Out of memory\n");
	fclose(*p_fp);
	exit(1);
    }
    
    /* Create the character's profile */
    strcpy(charac -> name, name);
    charac -> numberOfAppearances =    1;
    charac -> next                 = NULL;
    
    return charac;
}







void scenaryInformation(FILE **p_fp, char *p_filename)
{
    /* Defensive programming */
    if( ( *p_fp = fopen (p_filename, "r") ) == NULL )
    {
        printf("Unable to open file for read access\n");
	fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
	exit(1);
    }
    
    /* Variable will hold the act and scene number */
    int act = 0;
    int scene = 0;
    
    while( !feof(*p_fp) )
    {
        char three[6];
	char five[6];
	char rest[101];
	
	/* Determining if we are on the line that starts with 'ACT' */
	if ( fscanf(*p_fp, "%5s %[^\n]", three, rest) == 2)
	{
	    /* We want to determine how many acts */   
	    if( !strcmp(three, "ACT") )
	    {
	        act++;
		scene = 0;
		printf("Act %d\n", act);
	    }
	    else if( !strcmp(three, "SCENE") )
	    {
	        scene++;
		char scenary[101];
		int index = indexOfSpace(rest);
		int toPivot = index;
		for(index; index <strlen(rest); index++)
		{
		    scenary[index - toPivot] = rest[index];
		} 
		scenary[index - toPivot] = '\0';
		
		printf("%d: %s\n", scene, scenary);
	    }
	}
    }
}


/*****************************************************************/
/* Function: numberOfActs - returns number of acts the play has  */
/* Arguments:                                                    */
/*    p_fp       - A file pointer                                */
/*    p_filename - The name of the file                          */
/*****************************************************************/
int numberOfActs(FILE **p_fp, char *p_filename)
{
    if( ( *p_fp = fopen(p_filename, "r") ) == NULL )
    {
        printf("Unable to open file for read access\n");
	fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
	exit(1);
    }
    
    /* The variable that will hold the number of acts */
    int count = 0;
    
    /* While we have not reached the end of the file... */
    while( !feof(*p_fp) )
    {
        char three[4];
	
	/* Checking any 3 letter string words at the start */
	/* of the line. Looking for ACT */
	if ( fscanf(*p_fp, "%3s", three ) == 1 )
	{
	    /* We want to determine how many acts */   
	    if( !strcmp(three, "ACT") )
	    {
	        count++;
	    }
	}
    }
    return count;
}
