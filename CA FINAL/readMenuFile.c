#include "readMenuFile.h"
#include "forGlue.h"

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
NODE *processFile ( FILE **p_fp, char *p_fileName, int numArguments )
{
   NODE   *root = NULL;   /* the root node of the linked list */
   
   /* Checking if the file can be opened*/
   if ( (*p_fp = fopen (p_fileName, "r")) == NULL )
   {
     printf (" Unable  to open  file  for  read  access .\n");
     fprintf(stderr , "error %d: %s\n", errno , strerror(errno ));
     exit (1);
   }
  
   fprintf(stderr, "Parameter listing:\n");
   fprintf(stderr, "%d: input file name: %s\n\n", numArguments - 1, p_fileName);
   fprintf(stderr, "Data values read from file:\n");
   
   /*While we have not reached the end of the file...*/
   while ( !feof(*p_fp) )
   {
    char decider;
    char label[81];
    int id;
  
    if ( fscanf(*p_fp, "%1c%4d%[^\n]", &decider, &id, label) == 3)
    {
      
      
        /* Considering the two cases of for the two different chars 'A' and 'B' */
        if ( decider == 'A' )
        {
          NODE *anode = newNode(label, id, p_fp);
          fprintf(stderr, "%4d: %s\n", id, label);
	      insertCorrect(&root, anode);
        }
      
        else if ( decider == 'B' )
        {
            /* As I did not use fscanf to make sure of the 4 digits only at the start, I use these cases to do so */
	    unsigned char i; unsigned char count = 0;
	    for ( i = 0; i < strlen(label); i++ )
	    {
	        if ( isdigit(label[i]) )
		    count++;
	    }
	        if ( count == 4 && ( strlen(label) == 4 || strlen(label) == 5 ) ) 
		    {
	            unsigned short int parentID = atoi(label);
	            if (parentID != 0)
	            {
	                NODE *self = findNode(root, id);
	                NODE *theParent = findNode(root, parentID);
	                if ( self == NULL )
	                  fprintf(stderr, "The ID %d cannot be found\n", id);
	                if ( theParent == NULL )
	                  fprintf(stderr, "The ID %d cannot be found\n", parentID);
	     
	                /* Error handling when an ID is given that was not specified before */
	                if ( self != NULL && theParent != NULL )
	                {
	                    fprintf(stderr, "  child %d, parent %d\n", id, parentID);
	                    /* Checking if the child node has a parent already */
	                    if ( self -> parent != NULL )
	                    {
	                        /* If the child has a parent - a clone of that child will be made */
	                        NODE *cloneSelf = newNode(self -> menuItem, self -> id, p_fp);
	                        addClone(&root, &cloneSelf);
	                        linkTree(&theParent, &cloneSelf);
	                    }
	                    else
	                        linkTree(&theParent, &self);
	                }
	            }	 	 
	            else 
		        {
	                NODE *self = findNode(root, id);
	                if ( self -> id != root -> id )
	                    linkTopLevel(&root, &self);
	            }
	        }

        }
  
    }
    
    } 
    fclose(*p_fp);
   
    return root;
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
NODE *newNode ( char *p_menuItem, int p_id, FILE **p_fp )
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
/* Function: printList                                                       */
/*    Uses the depth search method to print out the labels of the NODE and   */
/*    its children and continues until there are no more children NODEs and  */
/*    carries on with the siblings but prioritises the children NODEs        */
/* Parameters:                                                               */
/*    p_node     The current node to be printed out.                         */
/*    numSpaces  The number of times the file name must be tabbed            */
/*    orderNum   The order p_node is it relative to its siblings             */
/*    label      The current label the previous sibling or parent has        */
/*    p_fp        The file pointer in case we get an error and want to close */
/*                the input file before exiting.                             */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void printList ( NODE *p_node, int numSpaces, int orderNum, char *label, FILE **p_fp )
{
  int newOrderNum = orderNum + 1;
  char *newLabel; 
  /* If the node has children */  
  if ( p_node -> children != NULL )
  { 
    newLabel = makeLabel(p_node -> menuItem, newOrderNum, numSpaces, label, p_fp);
    free(label);
    
    /* The number part of the label */
    char *numberLabel = getLabel(newLabel, p_fp);
    free(newLabel);
    
    printList(p_node -> children, numSpaces + 1, 0, numberLabel, p_fp);
  }
  
  /* If the node has no children but another sibling */
  else if ( p_node -> nextSibling != NULL )
  {    
    newLabel = makeLabel(p_node -> menuItem, newOrderNum, numSpaces, label, p_fp);
    free(newLabel);
	
    /* Carry on with the recursion */  
    printList(p_node -> nextSibling, numSpaces, newOrderNum, label, p_fp);
  }
    
  /* If the node has no children and no more siblings */
  else
  {    
    newLabel = makeLabel(p_node -> menuItem, newOrderNum, numSpaces, label, p_fp);
    free(label);
     
    /* To aid with the recursion */
    glue(p_node, numSpaces, newOrderNum, newLabel, p_fp);
  } 
}

/*****************************************************************************/
/* Function: makeLabel                                                       */
/*    Creates the labels for all NODEs                                       */
/* Parameters:                                                               */
/*    itemName       The name of the NODE                                    */
/*    newOrderNum    The order the NODE is at relative to its siblings       */
/*    numSpaces      The number of times the label must be tabbed            */
/*    label          The current number label of the NODE e.g. 1.1           */
/*    p_fp        The file pointer in case we get an error and want to close */
/*                the input file before exiting.                             */
/* Returns:                                                                  */
/*    A string that contains the file number and file name                   */
/*****************************************************************************/
char *makeLabel(char *itemName, int newOrderNum, int numSpaces, char *label, FILE **p_fp)
{
  char *newLabel;
  if (label == NULL)
    newLabel = makeLabelTop(itemName, newOrderNum, p_fp);
  else
    newLabel = makeLabelNormal(itemName, newOrderNum, label, p_fp);
  
    int tab = strlen(newLabel) + (numSpaces*3);
    printf("%*s", tab , newLabel);
    printf("\n");
  return newLabel;
}

/*****************************************************************************/
/* Function: addClone                                                        */
/*    Adds a NODE at the end of the list of NODEs                            */
/* Parameters:                                                               */
/*    root        The root NODE of the tree                                  */
/*    self        The NODE to be inserted at the end of the list of NODEs    */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void addClone( NODE **root, NODE **self )
{
  NODE *r = *root;
  NODE *cloneSelf = *self;
  
  while ( r -> next != NULL )
    r = r -> next;
  /* Reached the end of the list of NODEs */
  r -> next = cloneSelf;
  cloneSelf -> prev = r;
}

/*****************************************************************************/
/* Function: makeLabelNormal                                                 */
/*    Creates the labels for any NODE except the top level NODEs             */
/* Parameters:                                                               */
/*    menuLabel   The name of the NODE                                       */
/*    orderNum    The order in which the NODE is at relative to its siblings */
/*    label       The current number label of the NODE e.g. 1.1 or 1.5.1 etc.*/
/*    p_fp        The file pointer in case we get an error and want to close */
/*                the input file before exiting.                             */
/* Returns:                                                                  */
/*    A string that contains the file number and file name                   */
/*****************************************************************************/
char *makeLabelNormal(char *menuLabel, int orderNum, char *label, FILE **p_fp)
{
  char *toReturn;
  if ( !(toReturn = (char *)malloc(81*sizeof(char))) )
  {
    printf("Out of memory\n");
    fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
    fclose(*p_fp);
    exit(1);
  }
  char newLabel[81]; int j;
  /* Copying in the contents of the previous number label */
  for (j = 0; j < strlen(label); j++)
    newLabel[j] = label[j];
  /* To denote the sub-level of the file */
  newLabel[j] = '.'; j++;
  
  char dummyNum[6];
  sprintf(dummyNum, "%d", orderNum);
  dummyNum[strlen(dummyNum)] = '\0';
  
  unsigned char i;
  for ( i = 0; i < strlen(dummyNum); i++)
  {
	  newLabel[j] = dummyNum[i];
	  j++;
  }
  newLabel[j] = ' '; j++;
  for ( i = 0; i < strlen(menuLabel); i++)
  {
	  newLabel[j] = menuLabel[i];
	  j++;
  }
  newLabel[j] = '\0';
  for ( i = 0; i < strlen(newLabel); i++)
  {
	  toReturn[i] = newLabel[i];
  }
  toReturn[i] = '\0';
  return toReturn;
}

/*****************************************************************************/
/* Function: makeLabelTop                                                    */
/*    Creates the labels for any top level NODEs                             */
/* Parameters:                                                               */
/*    menuLabel   The name of the NODE                                       */
/*    orderNum    The order in which the NODE is at relative to its siblings */
/*    p_fp        The file pointer in case we get an error and want to close */
/*                the input file before exiting.                             */
/* Returns:                                                                  */
/*    A string that contains the file number and file name                   */
/*****************************************************************************/
char *makeLabelTop(char *menuLabel, int orderNum, FILE **p_fp)
{
  char *toReturn;
  if ( !(toReturn = (char *)malloc(81*sizeof(char))) )
  {
    printf("Out of memory\n");
    fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
    fclose(*p_fp);
    exit(1);
  }
  char newLabel[81];
  sprintf(newLabel, "%d", orderNum);
  
  /* To give a space in between the number and label item */
  int i = strlen(newLabel); int j;
  newLabel[i] = ' '; i ++;
  
  for (j = 0; j < strlen(menuLabel); j++)
  {
	  newLabel[i] = menuLabel[j];
	  i++;
  }
  newLabel[i] = '\0';
  for ( i = 0; i < strlen(newLabel); i++)
  {
	  toReturn[i] = newLabel[i];
  }
  toReturn[i] = '\0';
  return toReturn;
}

/*****************************************************************************/
/* Function: getLabel                                                        */
/*    Returns the newly formed number part of the label of parent NODEs      */
/* Parameters:                                                               */
/*    fullLabel   The full label of the NODE - the number and name           */
/*    p_fp        The file pointer in case we get an error and want to close */
/*                the input file before exiting.                             */
/* Returns:                                                                  */
/*    A string that contains the file number of the parent                   */
/*****************************************************************************/
char *getLabel(char *fullLabel, FILE **p_fp)
{
  char *label;
  if (!(label = (char *)malloc(21*sizeof(char))))
  {
    printf("Out of memory\n");
    fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
    fclose(*p_fp);
    exit(1);
  }
  int i = 0;

  for(i; i < strlen(fullLabel); i++)
  {
    if (fullLabel[i] == ' ')
      break;
    else
      label[i] = fullLabel[i];
  }
  label[i] = '\0';
  return label;
}

/*****************************************************************************/
/* Function: glue                                                            */
/*    Aids in the recursion by checking if the current NODE has anymore      */
/*    siblings. If not, then the parent is checked as to whether there are   */
/*    anymore siblings to be checked and so forth until the final NODE is    */
/*    reached.                                                               */
/* Parameters:                                                               */
/*    queried      The NODE we check as to whether there are more siblings   */
/*    numSpaces    The amount of times that NODE's label must be tabbed      */
/*    orderNum     The order in which queried is at relative to its siblings */
/*    label        The label that the queried NODE has                       */
/*    p_fp        The file pointer in case we get an error and want to close */
/*                the input file before exiting.                             */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void glue ( NODE *queried, int numSpaces, int orderNum, char *label, FILE **p_fp )
{
   if ( queried -> nextSibling != NULL )
     /* Then there are more siblings to explore */
     printList(queried -> nextSibling, numSpaces, orderNum, label, p_fp);
      
   else if (queried -> parent != NULL)
   {
	   /* No more siblings - check the parent NODE */
	   char *newLabel = trimDots(label, p_fp);
	   int newOrdNum = getOrderNum(label);
	   free(label);
	   
	   glue( queried -> parent, numSpaces - 1, newOrdNum, newLabel, p_fp ); 
   }  
   else
	   free(label);	   
}

/*****************************************************************************/
/* Function: linkTopLevel                                                    */
/*    Links Top level nodes and orders them in ascending order of their ID   */
/* Parameters:                                                               */
/*    root               The root node of the list.                          */
/*    anotherTopLevel    Top level node to be linked to the root - a sibling */
/* Returns:                                                                  */
/*    (nothing)                                                              */
/*****************************************************************************/
void linkTopLevel (NODE **root, NODE **anotherTopLevel)
{
  NODE *r = *root;
  NODE *dummyTop = *anotherTopLevel;
  
  while ( r->nextSibling != NULL && r->id < dummyTop->id && r-> nextSibling->id < dummyTop-> id )
    r = r -> nextSibling;
    
  if ( r -> nextSibling == NULL )
  {
    r -> nextSibling = dummyTop;
    dummyTop -> prevSibling = r;
  }
  
  else if (r -> nextSibling -> id > dummyTop -> id)
  {
    dummyTop -> nextSibling = r -> nextSibling;
    dummyTop -> prevSibling = r;
    
    r -> nextSibling -> prevSibling = dummyTop;
    r -> nextSibling = dummyTop;
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
  /* Hold the head of the root - the one to be freed */
  NODE *tmp;
  
  while (p_root != NULL)
  {
    p_root -> prev = NULL;
    tmp = p_root;
    p_root = p_root -> next;
    tmp -> next = NULL;
    tmp -> nextSibling = NULL;
    tmp -> prevSibling = NULL;
    tmp -> parent = NULL;
    tmp -> children = NULL;
    free(tmp);
  }
    free(p_root);
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
    
    /* CASE 3: Inserting the node at the end of the list */
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

