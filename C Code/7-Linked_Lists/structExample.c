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
   };
typedef struct anode NODE;

int main(void)
{
  NODE *root = NULL;
  
  printf("CAN I? %d\n", sizeof(root[0]));
  
  NODE *first;
  
  first = (NODE *)malloc(sizeof(NODE));
  
  /*Using arrows because first is a list of structs of type NODE*/
  
  strcpy(first->monarchName, "THIRD");
  first -> startYear = 300;
  
  /*For the first item that we insert, there will not be any follow items yet*/
  
  first -> next = NULL;
  
  int emptyList = sizeof(root);
  printf("The list is: %d\n", emptyList);
  printf("The amount of bytes in first is: %d\n", sizeof(first));
  printf("The amount of bytes in first[0] is: %d\n", sizeof(first[0]));
  printf("LOOK --> %d\n", sizeof(NODE));
  
  if(root == NULL)
  {
    printf("To identify an empty list of structs of type NODE\n");
    printf("In our case, root is empty since we set it to NULL\n");
    root = first; 
    printf("\n");
    printf("Assigning first to root...\n");
  } 
  if(first != NULL)
    printf("This will print only if the list of NODEs 'first' is not empty\n");
    
  if (root != NULL)
  {
    printf("Now this should print because first has been assigned to root\n");
  }
  
  
  return 0;
}
