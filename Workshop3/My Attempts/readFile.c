#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <stdlib.h>
#include "verify.h"

void processFile( FILE **ffp, char *ch);

int main(int argc, char **argv)
{
  int length = strlen(argv[1]);
  verifyFile(argc, length, argv);
  FILE *fp;
  processFile(&fp, argv[1]);

  return 0;
}

void processFile( FILE **p_fp, char *p_fileName )
{
 *p_fp = fopen(p_fileName, "r");
 
 if (*p_fp == NULL)
 {
  printf("Unable to open file for read access.\n");
  fprintf(stderr, "error %d: %s\n", errno, strerror(errno));
  exit(1);
 }
 
 
 char str[60];
 if( fgets(str,60,*p_fp)!=NULL){
  puts(str);
 }
 /*
 while ( !feof(*p_fp) )
 {
   char str[20];
   fgets(str, 20, *p_fp);
   printf("%s\n", str);
   printf("hi\n");
   
   
 }*/
 fclose(*p_fp);
}
