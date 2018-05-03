/* 
 * To implement the functions from "forkPipe.h"
 */
 
#include "forkPipe.h"


/******************************************************/
/*                                                    */
/*                   Main                             */
/*                                                    */
/******************************************************/
int main ()
{
   pid_t   pid;
   int     mypipe[2];

   if ( pipe(mypipe) )    /* Create the pipe. */
   {
      fprintf (stderr, "Pipe failed.\n");
      return EXIT_FAILURE;
   }

   pid = fork();          /* Create the child process. */

   if ( pid < (pid_t)0 )
   { /* The fork failed. */
      fprintf (stderr, "Fork failed.\n");
      return EXIT_FAILURE;
   }

   if ( pid == (pid_t)0 )
   {  /* This is the child process. */
      close(mypipe[1]);   /* Close other end first. */
      read_from_pipe(mypipe[0]);
   }
   else
   {  /* This is the parent process. */
      close(mypipe[0]);   /* Close other end first. */
      write_to_pipe(mypipe[1]);
   }

   return EXIT_SUCCESS;
}

/******************************************************/
/*                                                    */
/*   Implementation of the functions in forkPipe.h    */
/*                                                    */
/******************************************************/

/* Read characters from the pipe and echo them to stdout. */
void read_from_pipe (int file)
{
   FILE   *stream = fdopen(file, "r");
   int     c;
   while ( (c = fgetc(stream)) != EOF )
      putchar(c);
   fclose(stream);
}

/* Write some random text to the pipe. */
void write_to_pipe (int file)
{
   FILE   *stream = fdopen(file, "w");
   fprintf(stream,"Hello world!\n");
   fflush(stream);
   sleep(3);
   fprintf(stream,"Goodbye world!\n");
   fclose(stream);
}
