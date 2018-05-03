/* Header file for Macbeth */
#ifndef __MACBETH_H
#define __MACBETH_H

/* Compiler Directives for file inclusion */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* This structure will hold information of the unique */
/* characters in the play */
struct character
{
    char name[51];
    int numberOfAppearances;
    struct character *next;
};
typedef struct character CHARAC;

/* Method Definitions */
int numberOfActs        (FILE **, char * );
void scenaryInformation (FILE **, char * );
CHARAC *newChar         (char *, FILE ** );
CHARAC *processFile     (FILE **, char * );
void addUniqueCharacter (CHARAC **, char*, FILE **);


#endif
