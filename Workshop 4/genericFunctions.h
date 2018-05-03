#ifndef __GENERICFUNCTIONS_H
#define __GENERICFUNCTIONS_H

/* Compiler Directives for file inclusion */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "macbeth.h"

/* Method Definitions */
int numberOfLines (FILE **, char *);
int words         (const char *);
int numberOfWords (FILE **, char *);
int indexOfSpace  (const char *);
void printList    (CHARAC *p_node);


#endif
