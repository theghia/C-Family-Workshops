/* This bit should go in a separate file called forkPipe.h, and then be
 * included in this program using #include <forkPipe.h>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* function prototypes */
void read_from_pipe (int);
void write_to_pipe  (int);
