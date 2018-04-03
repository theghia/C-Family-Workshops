#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************/
/* This structure stores one node in the linked list.                        */
/*****************************************************************************/

struct anode
   { char           monarchName[51];
     int            startYear;
     struct anode  *next;
     struct anode  *prev;
   };
typedef struct anode NODE;

int main(void)
{
  NODE *root = NULL;
  
  /*The NODEs we will use to play around with*/
  NODE *first = (NODE *)malloc(sizeof(NODE));
  NODE *second = (NODE *)malloc(sizeof(NODE));
  NODE *third = (NODE *)malloc(sizeof(NODE));
  NODE *fourth = (NODE *)malloc(sizeof(NODE));
  
  /*Slow way of populating*/
  strcpy(first->monarchName, "FIRST");
  first -> startYear = 100;
  
  strcpy(second->monarchName, "SECOND");
  second -> startYear = 200;
  
  strcpy(third->monarchName, "THIRD");
  third -> startYear = 300;
  
  strcpy(fourth->monarchName, "FOURTH");
  fourth -> startYear = 400;
  
  
  /*CASE 1: Inserting into an empty list*/
  if(root == NULL)
  {
    third -> prev = NULL;
    third -> next = NULL;
    
    root = third; 
    
    /*Checking if NODE has been inserted -YES*/
    printf("The name: %s\n", root -> monarchName);
    printf("\n");
  }
  
  /*CASE 2: Inserting at the beginning of the list*/
  if (root -> startYear > first -> startYear)
  {
    root -> prev = first;
    first -> next = root;
    first -> prev = NULL;
    
    root = first;
    
    printf("The current node's name: %s\n", root -> monarchName);
    printf("The next node's name: %s\n", root -> next -> monarchName);
    printf("The current node's name coming back from the next node: %s\n", root -> next -> prev -> monarchName);
    printf("\n");
  } 
  
  /*CASE 3: Insert into the middle of the list*/
  if (root -> next -> startYear > second -> startYear)
  {
    /*Note that root should be r, the node we want before the one we are inserting*/
    /*and second is the node we are inserting into the list*/
    second -> next = root -> next;
    second -> prev = root;
    root -> next -> prev = second;
    root -> next = second;
    
    printf("The current node's name: %s\n", root -> monarchName);
    printf("The next node's name: %s\n", root -> next -> monarchName);
    printf("The one after is: %s\n", root -> next -> next -> monarchName);
    printf("The second node's name coming back from the last node is: %s\n", root -> next -> next -> prev -> monarchName);
    printf("The first node's name coming back from the last node is: %s\n", root -> next -> next -> prev -> prev -> monarchName);
    printf("\n");
  }
  
  /*CASE 4: Insert at the end of the list*/
  if (root[2].next == NULL)
  {
    fourth -> next = NULL;
    fourth -> prev = root -> next -> next;
    root -> next -> next -> next = fourth;
    
    printf("The current node's name: %s\n", root -> monarchName);
    printf("The next node's name: %s\n", root -> next -> monarchName);
    printf("The one after is: %s\n", root -> next -> next -> monarchName);
    printf("The last one is: %s\n", root -> next -> next -> next -> monarchName);
    printf("The third node's name coming back from the last node is: %s\n", root -> next -> next -> next -> prev -> monarchName);
    printf("The second node's name coming back from the last node is: %s\n", root -> next -> next -> next -> prev -> prev -> monarchName);
    printf("The first node's name coming back from the last node is: %s\n", root -> next -> next -> next -> prev -> prev -> prev -> monarchName);
    printf("\n");
  }
  
  
  
  
  if(first != NULL)
    printf("This will print only if the list of NODEs 'first' is not empty\n");
    
  if (root != NULL)
  {
    printf("Now this should print because first has been assigned to root\n");
  }
  
  
  return 0;
}
