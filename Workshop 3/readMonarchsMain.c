#include "readMonarchs.h"
#include "verify.h"
#include <string.h>

/*****************************************************************************/
/* Function: main                                                            */
/*****************************************************************************/
int main (int argc, char **argv)
{
   FILE   *fp;      /* the file pointer */
   NODE   *root;    /* a pointer to the first node in the list */

  
   
    /* open the file for read access */

    printf("Read file contents ...\n");   fflush(stdout);
    root = processFile(&fp,argv[1]);

    printf("Print list ...\n");           fflush(stdout);
    printList(root);

    printf("Delete list ...\n");          fflush(stdout);
    deleteList(root);

    printf("Finished\n");                 fflush(stdout);
    
	/* close the file */   
   
  
    return 0;
}


