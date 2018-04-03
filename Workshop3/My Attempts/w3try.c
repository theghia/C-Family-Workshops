#include "readMonarchs.h"

int main()
{
 printf("What\n");
 char name[11] = "Elizabeth";
 char *p = name;
 int year = 1995;
 newNode(p, year);
return 0;
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
                int      p_year /*,
                FILE   **p_fp */)
{
   NODE   *node;

   /* - check that the memory was successfully allocated */
   if ( !(node = (NODE *)malloc(sizeof(NODE))))
   {
    printf("Out of memory\n");
    /*fclose(*p_fp);*/
    exit(1);
   }
   
   /* - populate the node's fields */
   strcpy(node->monarchName, p_name);
   node->startYear = p_year;
   node->next = NULL;

   /* return the node */
   return node;
}
