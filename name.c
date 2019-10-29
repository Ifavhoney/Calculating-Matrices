
#include "name.h"
#include <string.h>
#include <stdlib.h>

//returns a pointer to an array of struct name basics
struct name_basics *get_name(char *value)
{
    char *ptr = value;
    /* Using relative path holds the full path e.g  "./files/name.basics.tsv" */
    strcat(ptr, "/name.basics.tsv");
    //Got the length
    long length = strlen(ptr);
    struct name_basics *size = (struct name_basics *)malloc(length + 1);

    char buff[256];
    FILE *fp;

    fp = fopen(ptr, "r");
    printf("ptr is %s\n", ptr);

    if (fp != NULL)
    {
        while (fgets(buff, 256, fp) != NULL)
        {
            struct name_basics *name = (struct name_basics *)malloc(strlen(buff) + 1);
            //content scrolls and scrolls with the contents of the name.basics.tsv fgile
            name->primaryName = buff;
            printf("name: %s", name->primaryName);
        }
    }
    else
    {
        printf("unable to open file");
    }

    fclose(fp);
    return NULL;
}
