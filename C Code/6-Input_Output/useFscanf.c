#include  <stdlib.h>
#include  <stdio.h>
#include  <errno.h>
#include  <string.h>

int  main()
{
  FILE    *fp;
  char     ch;
  
  if ( (fp = fopen ("monarchs.txt", "r")) == NULL )
  {
  printf (" Unable  to open  file  for  read  access .\n");
  fprintf(stderr , "error %d: %s\n", errno , strerror(errno ));
  exit (1);
  }
  
  while ( !feof(fp) )
  {
  
 /* ch = fgetc(fp);
  printf ("%3d: %c\n",ch,ch);*/
  
  char name[81];
  int year;
  
  /*Change %d to %3d and this will read the first 3 digits in the date !!*/
  if ( fscanf(fp, "%80s %d", name, &year) == 2)
  {
    printf("Name of the royalty is: %s\n", name);
    printf("The year they were born is: %d\n", year);
  }
  
  }
  
  fclose(fp);
}
