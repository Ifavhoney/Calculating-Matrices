
/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#ifndef name_h
#define name_h

#include <stdio.h>
#include "binary.h"
struct name_basics
{
    char *nconst;
    char *primaryName;
};

struct arrayStruct *get_name(char *value);
#endif /* name_h */
