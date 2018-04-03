/*#include <readMonarchs.h>
#include <seperate.h>*/
#include "readMonarchs.h"
#include "seperate.h"

/*****************************************************************************/
/* Function: processFile                                                     */
/*    Reads the contents of the file (pairs of monarch name and start year)  */
/*    and creates a linked list containing the monarchs in year order.       */
/* Parameters:                                                               */
/*    p_fp       Points to open file containing data.                        */
/*    p_filename String containing the name of the file being read.          */
/* Returns:                                                                  */
/*    A pointer to the first node in the list.                               */
/*****************************************************************************/
NODE *processFile ( FILE   **p_fp,
                    char    *p_fileName )
{
   NODE   *root = NULL;   /* the root node of the linked list */
   
   /* your code goes here */
   char * line = NULL;
   size_t len = 0;
   ssize_t read;
   
   /*Open the file and check if it was opened*/
   *p_fp = fopen(p_fileName, "r");
   if (*p_fp == NULL) {
     printf("Cannot open file for read access\n");
     exit(1);
    }
   
   /*Take away blank spaces*/
   while ((read = getline(&line, &len, *p_fp)) != -1) 
     {
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
	
	NODE *oneNode = newNode(getName(royalty), getYear(royalty), **p_fp);
     }
   
   
   /*In each loop, take split the name and year and use the function below to
   create a new node and link it to the root*/
   
   fclose(*p_fp);
   
   return root;
}

/*****************************************************************************/
/* Function: newNode                                                         */
/*    Allocates memory to a new node and populates it with the name and year */
/*    specified.  The next pointer is set to NULL.                           */
/* Parameters:                                                               */
/*    p_name     The monarch's name.                                         */
/*    p_year     The monarch's start year.                                   */
/*    p_fp       The file pointer in case we get an error and want to close  */
/*               the input file before exiting.                              */
/* Returns:                                                                  */
/*    A pointer to the new node.                                             */
/*****************************************************************************/
NODE *newNode ( char    *p_name,
                int      p_year,
                FILE   **p_fp )
{
   NODE   *node;

   /* - check that the memory was successfully allocated */
   if ( !(node = (NODE *)malloc(sizeof(NODE))))
   {
    printf("Out of memory\n");
    fclose(*p_fp);
    exit(1);
   }
   
   /* - populate the node's fields */
   strcpy(node->monarchName, p_name);
   node->startYear = p_year;
   node->next = NULL;
   /*For a double linked list*/
   node->prev = NULL;

   /* return the node */
   return node;
}

/*****************************************************************************/
/* Function: printList                                                       */
/*    Recursively prints out the contents of the list in year order.         */
/* Parameters:                                                               */
/*    p_node     The node to be printed out.                                 */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void printList ( NODE   *p_node )
{
   /* your code goes here */
}

/*****************************************************************************/
/* Function: deleteList                                                      */
/*    Free the memory held by the list from the root node down.              */
/* Parameters:                                                               */
/*    p_root     The root node of the list.                                  */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void deleteList ( NODE *p_root )
{
   /* your code goes here */
}

/*****************************************************************************/
/* Function: insertCorrect                                                   */
/*    Inserts the NODE anode in the correct order of the list root           */
/* Parameters:                                                               */
/*    root     The root node of the list.                                    */
/*    anode    The NODE to be inserted in the list                           */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void insertCorrect(NODE **root, NODE *anode)
{
  NODE *r = *root;
  
  while (r != NULL && r -> next != NULL && r -> startYear < anode -> startYear && r -> next -> startYear < anode -> startYear)
  { 
    r = r -> next;
  }
  
  if ( r == NULL )
   {
      anode -> prev = NULL;
      anode -> next = NULL;
      *root = anode;
   }
    
  else if ( r -> startYear > anode -> startYear)
   {
      root[0] -> prev = anode;
      anode -> next = *root;
      anode -> prev = NULL;
      
      *root = anode;
   }
   
   else if ( r -> next == NULL )
   {
     anode -> next = NULL;
     anode -> prev = r;
     r -> next = anode;
   }
   
   else if ( r -> next -> startYear > anode -> startYear )
   {
     anode -> next = r -> next;
     anode -> prev = r;
     r -> next -> prev = anode;
     r -> next = anode;
   } 
}