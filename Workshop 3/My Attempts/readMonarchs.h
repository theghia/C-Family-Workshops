#ifndef __READMONARCHS_H
#define __READMONARCHS_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************/
/* This structure stores one node in the linked list.                        */
/*****************************************************************************/

struct anode
   { char           monarchName[51];
     int            startYear;
     struct anode  *next;
   };
typedef struct anode NODE;

/*****************************************************************************/
/* Function prototypes                                                       */
/*****************************************************************************/

NODE *processFile (FILE **,char *);
NODE *newNode     (char *,int /*,FILE ** */);
void  printList   (NODE *);
void  deleteList  (NODE *);

#endif
