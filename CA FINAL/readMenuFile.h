#ifndef __READMENUFILE_H
#define __READMENUFILE_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*****************************************************************************/
/* This structure stores one node in the linked list.                        */
/*****************************************************************************/

struct anode
   { char           menuItem[51];
     int            id;
     struct anode  *nextSibling;
     struct anode  *prevSibling;
     struct anode  *parent;
     struct anode  *children;
     struct anode  *next;
     struct anode  *prev;
   };
typedef struct anode NODE;

/*****************************************************************************/
/* Function prototypes                                                       */
/*****************************************************************************/

NODE *processFile (FILE **,char *, int);
NODE *newNode     (char *,int, FILE **);
NODE *findNode    (NODE *, int);
void  printList   (NODE *, int, int, char *, FILE **);
void  deleteList  (NODE *);
void insertCorrect(NODE **, NODE *);
void linkTree     (NODE **, NODE **);
void glue         (NODE *, int, int, char *, FILE **);
void linkTopLevel (NODE **, NODE **); 
void addClone( NODE **, NODE ** );
char *getLabel    (char *, FILE **);
char *makeLabelTop(char *, int, FILE **);
char *makeLabelNormal(char *, int, char *, FILE **);
char *makeLabel(char *, int, int, char *, FILE **);

#endif
