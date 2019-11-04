
#include "name.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 9700000

struct arrayStruct *
get_name(char *value)
{
    char *ptr = malloc(strlen(value) + strlen("/name.basicss.tsv") + 1);

    strcat(ptr, value);
    strcat(ptr, "/name.basicss.tsv");

    //strcpy it

    long length;
    length = strlen(ptr);

    struct name_basics *array;
    struct arrayStruct *test;

    static int hi[ARRAY_SIZE];
    char buff[256];
    FILE *fp;

    fp = fopen(ptr, "r");

    int i = 0;

    int total = totalRows(fp);

    if (fp != NULL)
    {
        printf("ptr is %s\n", ptr);

        while (fgets(buff, 256, fp) != NULL)
        {
            length += strlen(buff);

            char *result = get_column(buff, 4);

            if (strstr(result, "actor") != NULL || strstr(result, "actress") != NULL)
            {

                hi[i] = 1;
            }
            else
            {

                hi[i] = 0;
            }
            i++;
        }
        array = malloc(length);

        i = 0;

        fseek(fp, 0, SEEK_SET);
        while (fgets(buff, 256, fp) != NULL)
        {

            if (i <= total)
            {
                char *result1 = get_column(buff, 0);
                if (hi[i] == 0)
                {

                    array[i].nconst = NULL;
                }
                else
                {

                    array[i].nconst = result1;
                }
            }

            else
            {

                char *result2 = get_column(buff, 1);
                if (hi[i - total - 1] == 0)
                {

                    array[i - total - 1].primaryName = NULL;
                }
                else
                {

                    array[i - total - 1].primaryName = result2;
                }
            }

            if (i == total)
            {
                fseek(fp, 0, SEEK_SET);
            }

            i++;
        }
    }
    else
    {
        printf("unable to open file");
    }

    fclose(fp);
    test = malloc(i / 2);
    test->size = i / 2;
    test->address = array;
    test->tree1 = 0;
    test->tree2 = 0;
    return test;
}
