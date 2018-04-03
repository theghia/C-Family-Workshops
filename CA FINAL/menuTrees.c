#include "readMenuFile.h"

/*****************************************************************************/
/* Function: main                                                            */
/*****************************************************************************/
int main (int argc, char **argv)
{
   FILE   *fp;     
   NODE   *root;   
   
   /* open the file for read access */
   
   printf("Read file contents ...\n");   fflush(stdout);
      
   root = processFile(&fp,*(argv + 1), argc);
   
   /* close the file */
   
   printf("Print list ...\n");           fflush(stdout);
      
   printList(root, 0, 0, NULL, &fp);
   
   printf("Delete list ...\n");          fflush(stdout);
   deleteList(root);
   
   printf("Finished\n");                 fflush(stdout);
     
   return 0;
}