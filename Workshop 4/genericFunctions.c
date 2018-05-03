/* File contains implementations for the functions in genericFunctions.h */

#include "genericFunctions.h"

int indexOfSpace(const char *sentence)
{
    int index = 0;
    for (index; index < strlen(sentence); index++)
    {
        if(sentence[index] == ' ')
	{
	    break;
	}
    }
    return index +1;
}


/*****************************************************************/
/* Function: words - counts number of words in a string          */
/* Arguments:                                                    */
/*    sentence - The string we will count the number of          */
/*               words from                                      */
/*****************************************************************/
int words(const char *sentence)
{
    /* The number of counted words */
    int count = 0; 
    
    /* State */
    const char* it = sentence;
    int inword = 0;
    
    do switch(*it)
    {
        case '\0': case ' ': case '\t' : case '\n' : case '\r':
	    
	    /* So everytime you come across a character it */
	    /* could be part of a word. Once you encounter */
	    /* any of the above cases, that is one word!   */
	    if (inword)
	    {
	        inword = 0;
		count++;
	    }
	    break;
	    
	default: inword = 1; 
    } while(*it++);
    
    return count;
}


/*****************************************************************/
/* Function: numberOfWords                                       */
/* Arguments:                                                    */
/*    p_fp       - A file pointer                                */
/*    p_filename - The name of the file                          */
/*****************************************************************/
int numberOfWords(FILE **p_fp, char *p_filename)
{

    /* Defensive programming */
    if( ( *p_fp = fopen (p_filename, "r") ) == NULL )
    {
        printf("Unable to open file for read access\n");
	fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
	exit(1);
    }
    
    /* The variable that will hold the number */
    /* of lines traversed in the file */
    int count = 0;
    
    /* While we have not reached the end of the file... */
    while( !feof(*p_fp) )
    {
        char line[101];
	
	/* Reading in the line to count the words */
        if ( fscanf(*p_fp, "%100s", line) == 1 )
	{
	    count += words(line);
	}
    }
    
    /* House keeping - always close the file */
    fclose(*p_fp);
    
    return count;
}


/*****************************************************************/
/* Function: numberOfLines                                       */
/* Arguments:                                                    */
/*    p_fp       - A file pointer                                */
/*    p_filename - The name of the file                          */
/*****************************************************************/
int numberOfLines(FILE **p_fp, char *p_filename)
{

    /* Defensive programming */
    if( ( *p_fp = fopen (p_filename, "r") ) == NULL )
    {
        printf("Unable to open file for read access\n");
	fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
	exit(1);
    }
    
    /* The variable that will hold the number */
    /* of lines traversed in the file */
    int count = 0;
    
    /* While we have not reached the end of the file... */
    while( !feof(*p_fp) )
    {
       char ch = fgetc(*p_fp);
       
       /* Everytime there is a newline character - so a new line */
       if( ch == '\n' )
       {
           count++;
       }
    }
    
    /* House keeping - always close the file */
    fclose(*p_fp);
    
    return count;
}

/*****************************************************************************/
/* Function: printList                                                       */
/*    Recursively prints out the contents of the list in year order.         */
/* Parameters:                                                               */
/*    p_node     The node to be printed out.                                 */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void printList ( CHARAC   *p_node )
{
   /* Base case */
   if (p_node -> next == NULL)
   {
	   printf("Name of character: %s\n", p_node -> name);
	   printf("Number of times: %d\n\n", p_node -> numberOfAppearances);
   }
   /* General case */
   else{
	   printf("Name of character: %s\n", p_node -> name);
	   printf("Number of times: %d\n\n", p_node -> numberOfAppearances);
	   p_node = p_node -> next;
	   printList(p_node);
   }
	   
}
