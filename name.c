
#include "name.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

//returns a pointer to an array of struct name basics
struct name_basics *get_name(char *value)
{
    char *ptr = value;
    /* Using relative path holds the full path e.g  "./files/name.basics.tsv" */

    strcat(ptr, "/name.basics.tsv");
    //Got the length
    long length;
    length = strlen(ptr);
    struct name_basics *size = (struct name_basics *)malloc(length + 1);

    char buff[256];
    FILE *fp;

    //"/files/txt"
    fp = fopen(ptr, "r");
    printf("ptr is %s\n", ptr);
    int i = 0;
    if (fp != NULL)
    {
        while (fgets(buff, 256, fp) != NULL)
        {
            struct name_basics *name = (struct name_basics *)malloc(strlen(buff) + 1);
            struct name_basics *src = (struct name_basics *)malloc(strlen(buff) + 1);

            //content scrolls and scrolls with the contents of the name.basics.tsv fgile
            name->primaryName = buff;
            char *result = get_column(name->primaryName, &src->primaryName, 4);

            if (strstr(result, "actor") != NULL || strstr(result, "actress") != NULL)
            {
                i++;
                printf("| %d |\n", i);
            }
        }
    }
    else
    {
        printf("unable to open file");
    }

    // free(name);
    fclose(fp);
    return NULL;
}

//a string that contains entire line from the file, where contents will be copied to, a column number
