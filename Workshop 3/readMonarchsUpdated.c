/*#include <readMonarchs.h>*/
#include "readMonarchs.h"

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
   
   /* Checking if the file can be opened*/
   if ( (*p_fp = fopen (p_fileName, "r")) == NULL )
   {
     printf (" Unable  to open  file  for  read  access .\n");
     fprintf(stderr , "error %d: %s\n", errno , strerror(errno ));
     exit (1);
   }
  
   /*While we have not reached the end of the file...*/
   while ( !feof(*p_fp) )
   {
    char name[81];
    int year;
  
    if ( fscanf(*p_fp, "%80s %4d", name, &year) == 2)
    {
      NODE *anode = newNode(name, year, p_fp);
	  insertCorrect(&root, anode);
    }
  }
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
   /* Base case */
   if (p_node -> next == NULL)
   {
	   printf("Royalty name: %s\n", p_node -> monarchName);
	   printf("Year: %d\n", p_node -> startYear);
   }
   /* General case */
   else{
	   printf("Royalty name: %s\n", p_node -> monarchName);
	   printf("Year: %d\n", p_node -> startYear);
	   p_node = p_node -> next;
	   printList(p_node);
   }
	   
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
/*printf("DELETING\n");*/
   NODE *tmp;

   while (p_root != NULL)
    {
       p_root -> prev = NULL;
       tmp = p_root;
       p_root = p_root -> next;
       tmp -> next = NULL;
       free(tmp);
    }
    /*printf("Done\n");*/
    free(p_root);
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
