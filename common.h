
#ifndef common_h
#define common_h

#include <stdio.h>

//a string that contains entire line from the file, where contents will be copied to, a column number
char *get_column(char *src, char **dst, int colNum);
//length
int totalRows(FILE *fp);
#endif /* common_h */
