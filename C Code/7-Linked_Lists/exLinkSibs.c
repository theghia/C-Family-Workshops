#include "readMenuFile.h"

void insertCorrect(NODE **, NODE *);
NODE *findNode(NODE *, int);

int main(void)
{
  NODE *root = NULL;
  
  /*The NODEs I will play around with*/
  NODE *parentMum = (NODE *)malloc(sizeof(NODE));
  NODE *child1 = (NODE *)malloc(sizeof(NODE));
  NODE *child2 = (NODE *)malloc(sizeof(NODE)); 
  NODE *child3 = (NODE *)malloc(sizeof(NODE));
  NODE *child4 = (NODE *)malloc(sizeof(NODE));
  
  /* Slow way of populating */
  strcpy(parentMum -> menuItem, "PARENT");
  parentMum -> id = 1;
  
  strcpy(child1 -> menuItem, "CHILD1");
  child1 -> id = 2;
  
  strcpy(child2 -> menuItem, "CHILD2");
  child2 -> id = 3;
  
  strcpy(child3 -> menuItem, "CHILD3");
  child3 -> id = 4;
  
  strcpy(child4 -> menuItem, "CHILD4");
  child4 -> id = 5;
  
  /* This test has been done in structLooping */
  insertCorrect(&root, child1);
  insertCorrect(&root, parentMum);
  insertCorrect(&root, child2);
  insertCorrect(&root, child3);
  insertCorrect(&root, child4);
  
  /* Seeing if we have found child2 - YES */
  NODE *dummyChild = (NODE *)malloc(sizeof(NODE));
  dummyChild = findNode(root, 3);
  printf("The label for dummyChild is: %s\n", dummyChild -> menuItem);
  printf("\n");
  
  /* Seeing if we have found the parent - YES */
  NODE *dummyParent = (NODE *)malloc(sizeof(NODE));
  dummyParent = findNode(root, 1);
  printf("The label for dummyParent is: %s\n", dummyParent -> menuItem);
  printf("\n");
  
  /* Looking for Child1 */
  NODE *dummyChild2 = (NODE *)malloc(sizeof(NODE));
  dummyChild2 = findNode(root, 2);
  printf("The label for dummyChild2 is: %s\n", dummyChild2 -> menuItem);
  printf("\n");
  
  /* Looking for Child3 */
  NODE *dummyChild3 = (NODE *)malloc(sizeof(NODE));
  dummyChild3 = findNode(root, 4);
  printf("The label for dummyChild3 is: %s\n", dummyChild3 -> menuItem);
  printf("\n");
  
  /* Looking for Child4 */
  NODE *dummyChild4 = (NODE *)malloc(sizeof(NODE));
  dummyChild4 = findNode(root, 5);
  printf("The label for dummyChild4 is: %s\n", dummyChild4 -> menuItem);
  printf("\n");
  
  /* Now we want to link Child3 to Parent */
  /* CASE 1: This is essentially adding a new node to an empty list*/
  if (dummyParent -> children == NULL) /* NOTE: dummyParent -> children is like root*/
  {
    dummyChild3 -> nextSibling = NULL; /* Possibly not needed - can do this at creating the NODE*/
    dummyChild3 -> prevSibling = NULL;
    
    dummyChild3 -> parent = dummyParent;
    dummyParent -> children = dummyChild3;
  }
  
  printf("The first child of the parent is: %s\n", parentMum -> children -> menuItem);
  printf("The parent of child3 is: %s\n", child3 -> parent -> menuItem);
  printf("\n");
  
  /* Now we want to link Child1 to this family tree */
  /* CASE 2: This is essentially adding a node to the start of the list */
  if (dummyParent -> children != NULL)
  {
    /* When you know that it is not NULL, loop through the children.*/
    
    if (dummyParent -> children -> id > dummyChild2 -> id)
      {
        dummyParent -> children -> prevSibling = dummyChild2;
	dummyChild2 -> nextSibling = dummyParent -> children;
	
	dummyChild2 -> parent = dummyParent;
	dummyParent -> children = dummyChild2;
      }
  }
  printf("The first child of the parent is: %s\n", parentMum -> children -> menuItem);
  printf("The second child of the parent is: %s\n", parentMum -> children -> nextSibling -> menuItem);
  printf("The parent of child1 is: %s\n", child1 -> parent -> menuItem);
  printf("\n");
  
  
  
  /* Now we want to link Child2 to this family tree */
  /* CASE 3: Inserting into the middle of siblings */
  if (dummyParent -> children != NULL)
  {
    /* When you know that it is not NULL, loop through the children.*/
    
    if (dummyParent -> children -> nextSibling -> id > dummyChild -> id)
      {
        dummyChild -> nextSibling = dummyParent -> children -> nextSibling;
	dummyChild -> prevSibling = dummyParent -> children;
	
	dummyParent -> children -> nextSibling -> prevSibling = dummyChild;
	dummyParent -> children -> nextSibling = dummyChild;
	
		
	dummyChild -> parent = dummyParent;
      }
  }
  printf("The first child of the parent is: %s\n", parentMum -> children -> menuItem);
  printf("The second child of the parent is: %s\n", parentMum -> children -> nextSibling -> menuItem);
  printf("The third child of the parent is: %s\n", parentMum -> children -> nextSibling -> nextSibling -> menuItem);
  printf("The parent of child2 is: %s\n", child2 -> parent -> menuItem);
  printf("\n");
  
  /* Now we want to link Child4 to this family tree */
  /* CASE 4: Inserting at the end of siblings */
  if (dummyParent -> children -> nextSibling -> nextSibling -> nextSibling == NULL)
  {
    dummyChild4 -> nextSibling = NULL;
    dummyChild4 -> prevSibling = dummyParent -> children -> nextSibling -> nextSibling;
    dummyParent -> children -> nextSibling -> nextSibling -> nextSibling = dummyChild4; 
    
    dummyChild4 -> parent = dummyParent;
  }
  printf("The first child of the parent is: %s\n", parentMum -> children -> menuItem);
  printf("The second child of the parent is: %s\n", parentMum -> children -> nextSibling -> menuItem);
  printf("The third child of the parent is: %s\n", parentMum -> children -> nextSibling -> nextSibling -> menuItem);
    printf("The fourth child of the parent is: %s\n", parentMum -> children -> nextSibling -> nextSibling -> nextSibling -> menuItem);
  printf("The parent of child4 is: %s\n", child4 -> parent -> menuItem);
  printf("\n");
  
  
  /* If prevSibling == NULL, then first child */
  /* If nextSibling == NULL, then last child */
  
  /* Now what if a child has two parents? I will make child 4 have another parent -> child 1 */
  if (dummyChild4 -> parent != NULL)
  {
    char *dummyName = dummyChild4 -> menuItem;
    int dummyID = dummyChild4 -> id;
    
    NODE *newDummyChild = (NODE *)malloc(sizeof(NODE));
    
    strcpy(newDummyChild -> menuItem, "CHILD4");
    newDummyChild -> id = 5; 
   
  }
  
  return 0;
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

