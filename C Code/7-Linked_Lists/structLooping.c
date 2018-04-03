#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct anode
   { char           monarchName[51];
     int            startYear;
     struct anode  *next;
     struct anode  *prev;
   };
typedef struct anode NODE;

void insertCorrect(NODE **, NODE *);

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
  
  insertCorrect(&root, third);
  printf("Should be a name: %s\n", root -> monarchName);
  printf("\n");
  
  insertCorrect(&root, first);
  printf("Should be a name: %s\n", root -> monarchName);
  printf("Should be a name: %s\n", root -> next -> monarchName);
  printf("\n");
  
  insertCorrect(&root, second);
  printf("Should be a name: %s\n", root -> monarchName);
  printf("Should be a name: %s\n", root -> next -> monarchName);
  printf("Should be a name: %s\n", root -> next -> next -> monarchName);
  printf("\n");
  
  insertCorrect(&root, fourth);
  printf("Should be a name: %s\n", root -> monarchName);
  printf("Should be a name: %s\n", root -> next -> monarchName);
  printf("Should be a name: %s\n", root -> next -> next -> monarchName);
  printf("Should be a name: %s\n", root -> next -> next -> next -> monarchName);
  printf("\n");
  
  return 0;
}

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
