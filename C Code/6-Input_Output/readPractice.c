#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "readMenuFile.h"

NODE *newNode(char *, int, FILE **);
NODE *findNode(NODE *, int);
void linkTree(NODE **, NODE **);

/*This should be in your process file*/

int main(int argc, char **argv)
{
  FILE *fp;
  NODE *root = NULL; /* This will be in the main part of your program*/
  
   /* Checking if the file can be opened*/
   if ( (fp = fopen (argv[1], "r")) == NULL )
   {
     printf (" Unable  to open  file  for  read  access .\n");
     fprintf(stderr , "error %d: %s\n", errno , strerror(errno ));
     exit (1);
   }
   
   fprintf(stderr, "Parameter listing:\n");
   fprintf(stderr, "%d: input file name: %s\n\n", argc - 1, argv[1]);
   fprintf(stderr, "Data values read from file:\n");
   
   /*While we have not reached the end of the file...*/
   while ( !feof(fp) )
   {
    char decider;
    int id;
    char label[81];
  
    if ( fscanf(fp, "%1c%4d%[^\n]", &decider, &id, label) == 3)
    
      {
         NODE *anode = newNode(label, id, &fp);

         if (decider == 'A')
	 {
	   fprintf(stderr, "%4d: %s\n", id, label);
	   insertCorrect(&root, anode);
	   
	 }
 
	 else {
	   int parentID = atoi(label);
	   if (parentID != 0)
	   {
	     NODE *self = findNode(root, id);
	     NODE *theParent = findNode(root, parentID);
	     printf("WHO AM I? %s\n", self -> menuItem);
	     printf("SO MY PARENT IS --> %s\n", theParent -> menuItem);
	     /*fprintf(stderr, "  child %d, parent %d\n", id, parentID);*/
	     linkTree(&theParent, &self);
	   }

	 }

      }
    }
    /* Then have a function here that prints all of the nodes things to stderr*/
    printf("The 4th node is: %s\n", root -> next -> next -> next -> menuItem);
    printf("The first child of PARENT is: %s\n", root -> children);
    printf("The second child is: %s\n", root -> children -> nextSibling);
    printf("The third child is: %s\n", root -> children -> nextSibling -> nextSibling);
    printf("The fourth child is: %s\n", root -> children -> nextSibling -> nextSibling -> nextSibling);
    printf("The fifth child is: %s\n", root -> children -> nextSibling -> nextSibling -> nextSibling -> nextSibling);
    
    /* Checking if the grandkids are there */
    printf("Now for the second child's children\n");
    printf("The 1st grandkid is: %s\n", root -> children -> nextSibling -> nextSibling -> children);
    printf("The 2nd grandkid is: %s\n", root -> children -> nextSibling -> nextSibling -> children -> nextSibling);
  
  fclose(fp);
  
  return 0;
}

/*****************************************************************************/
/* Function: newNode                                                         */
/*    Allocates memory to a new node and populates it with the label and ID  */
/*    specified.  The next, prev, nextSibling, prevSibling, parent, children */
/*    pointers are set to NULL.                                              */
/* Parameters:                                                               */
/*    p_menuItem  The label item given to the node from the file             */
/*    p_id        The ID that the node has from the file being read in       */
/*    p_fp        The file pointer in case we get an error and want to close */
/*                the input file before exiting.                             */
/* Returns:                                                                  */
/*    A pointer to the new node.                                             */
/*****************************************************************************/
NODE *newNode ( char    *p_menuItem,
                int      p_id,
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
   strcpy(node -> menuItem, p_menuItem);
   node-> id = p_id;
   node -> next = NULL;
   node -> prev = NULL;
   node -> nextSibling = NULL;
   node -> prevSibling = NULL;
   node -> parent = NULL;
   node -> children = NULL;

   /* return the node */
   return node;
}

/*****************************************************************************/
/* Function: insertCorrect                                                   */
/*    Inserts the NODE anode in the correct order of the list root           */
/*    This order is dependent on the ID of the node. This function is        */
/*    is called when the character 'A' is read at the start of each line     */
/*    in the file. Links each other using the 'next' and 'prev' pointers     */
/* Parameters:                                                               */
/*    root     The root node of the list.                                    */
/*    anode    The NODE to be inserted in the list                           */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void insertCorrect(NODE **root, NODE *anode)
{
  NODE *r = *root;
  
  while (r != NULL && r -> next != NULL && r -> id < anode -> id && r -> next -> id < anode -> id)
  { 
    r = r -> next;
  }
  /* Add cases here so that it is either prev or prevSibling etc. +1 argument */
  if ( r == NULL )
   {
      anode -> prev = NULL;
      anode -> next = NULL;
      *root = anode;
   }
    
  else if ( r -> id > anode -> id)
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
   
   else if ( r -> next -> id > anode -> id )
   {
     anode -> next = r -> next;
     anode -> prev = r;
     r -> next -> prev = anode;
     r -> next = anode;
   } 
}

/*****************************************************************************/
/* Function: findNode                                                        */
/*    Locates the specified NODE in the second argument in the list          */
/*    of NODES given in the first argument. Then returns it.                 */
/* Parameters:                                                               */
/*    p_node   The root node of the list.                                    */
/*    toFind   The ID of the NODE to be found                                */
/* Returns:                                                                  */
/*    The NODE with the queried ID, else NULL                                */
/*****************************************************************************/
NODE *findNode(NODE *p_node, int toFind)
{
  NODE *current = p_node;
  while ( current != NULL )
  {
    if (current -> id == toFind)
      return current;
    current = current -> next;
  }
  return NULL;
}

/*****************************************************************************/
/* Function: linkTree                                                        */
/*    Links the parent node to the child node and if that parent node has    */
/*    any children nodes, the children will be linked as siblings in a       */
/*    sorted manner.                                                         */
/* Parameters:                                                               */
/*    inputParent   The parent node we want to link with the child node      */
/*    inputChild    The child node that we want to link with the parent node */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void linkTree(NODE **inputParent, NODE **inputChild)
{
  NODE *dummyParent = *inputParent;
  NODE *dummyChild = *inputChild;
  /* CASE 1: Insert into empty children list */
  if (dummyParent -> children == NULL)
  {
    dummyChild -> parent = dummyParent;
    dummyParent -> children = dummyChild;
  }
  else
  {
     /* To hold the first child in the list of children the parent has */
    NODE *r = dummyParent -> children;
    
    /* To loop through all of the children and place it in order */
    while ( r -> nextSibling != NULL && r -> id < dummyChild -> id && r -> nextSibling -> id < dummyChild -> id)
    {
      r = r -> nextSibling;
    }
    
    /* CASE 2: Inserting at the front of the list */
    if ( r -> id > dummyChild -> id )
    {
      r -> prevSibling = dummyChild;
      dummyChild -> nextSibling = dummyParent -> children;
      
      dummyChild -> parent = dummyParent;
      
      /* We want the link to point to the front of the list */
      dummyParent -> children = dummyChild;
    }
    
    /* CASE 1: Inserting the node at the end of the list */
    else if (  r -> nextSibling == NULL )
    {
      dummyChild -> prevSibling = r;
      r -> nextSibling = dummyChild;
      
      dummyChild -> parent = dummyParent;
    }
    
    /* CASE 4: Inserting the node in between siblings */
    else if ( r -> nextSibling -> id > dummyChild -> id)
    {
      dummyChild -> nextSibling = r -> nextSibling;
      dummyChild -> prevSibling = r;
      
      r -> nextSibling -> prevSibling = dummyChild;
      r -> nextSibling = dummyChild;
      
      dummyChild -> parent = dummyParent;
    }
  }
}
