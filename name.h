
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
