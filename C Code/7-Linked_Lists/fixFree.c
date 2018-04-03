#include "readMenuFile.h"
#include "forGlue.h"

void addClone( NODE **, NODE ** );

int main(void)
{
  return 0;
}

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
