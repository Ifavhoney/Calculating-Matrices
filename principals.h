/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#ifndef principals_h
#define principals_h
#include "common.h"

#include <stdio.h>

struct title_principals
{
    char *tconst;
    char *nconst;
    char *characters;
};

struct arrayStruct *get_title_principals(char *value);

#endif /* principals_h */
