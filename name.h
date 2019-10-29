
#ifndef name_h
#define name_h

#include <stdio.h>
struct name_basics
{
    char *nconst;
    char *primaryName;
};

struct name_basics *get_name(char *value);

#endif /* name_h */
