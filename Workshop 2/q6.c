/* Question 6 */

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv )
{
     int *intArray = NULL;
     int fromArg = atoi( argv[1] );
     
     /* An array of the size of the integer will be made */
     intArray = ( int * )malloc( fromArg * sizeof(char) );
       
     /* Then we will populate it with the numbers from 1 to that number */
     int i;
     for( i = 0; i < fromArg; i++ )
     {
          *(intArray + i) = i + 1;
     }
        
     /* Print out the Array */
     printf("%s", "The Array is:");
     for( i = 0; i < fromArg; i++ )
     {
          printf( " %d", *(intArray + i) );
     }
     printf("\n");
       
     return 0;
     
}
