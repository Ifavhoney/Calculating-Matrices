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

void add_new_word(const char *w);
char *get_column(char *src, int colNum);
int totalRows(FILE *fp);
#endif /* common_h */
