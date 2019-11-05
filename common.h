/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#ifndef common_h
#define common_h

#include <stdio.h>

struct arrayStruct
{
    long size;
    void *address;
    /*maybe double pointers*/
    struct node **tree1;
    struct node **tree2;
};

char *get_column(char *src, int colNum);
int totalRows(FILE *fp);

#endif /* common_h */
