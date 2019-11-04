#include "principals.h"
#include "common.h"

#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 197000000

struct arrayStruct
    *
    get_title_principals(char *value)
{

    char *ptr = malloc(strlen(value) + strlen("/title.principalss.tsv") + 1);

    strcat(ptr, value);
    strcat(ptr, "/title.principalss.tsv");

    long length;
    length = strlen(ptr);
    struct arrayStruct *test = NULL;

    struct title_principals *array;

    static int hi[ARRAY_SIZE];

    char buff[256];
    FILE *fp;

    fp = fopen(ptr, "r");
    printf("ptr is %s\n", ptr);
    int i = 0;

    int total = totalRows(fp);

    if (fp != NULL)
    {
        while (fgets(buff, 256, fp) != NULL)
        {

            length += strlen(buff);

            char *result = get_column(buff, 3);

            if (strstr(result, "actor") != NULL)
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

            char *result = get_column(buff, 5);

            if (hi[i] == 0)
            {
                array[i].characters = NULL;
            }
            else
            {

                array[i].characters = result;
            }
            i++;
        }

        i = 0;
        fseek(fp, 0, SEEK_SET);

        while (fgets(buff, 256, fp) != NULL)
        {

            if (i <= total)
            {
                char *result1 = get_column(buff, 0);
                if (hi[i] == 0)
                {
                    array[i].tconst = NULL;
                }
                else
                {

                    array[i].tconst = result1;
                }
            }

            else
            {

                char *result2 = get_column(buff, 2);
                if (hi[i - total - 1] == 0)
                {
                    array[i - total - 1].nconst = NULL;
                }
                else
                {

                    array[i - total - 1].nconst = result2;
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

    test = malloc(sizeof(array));

    test->size = i / 2;
    test->address = array;
    test->tree1 = 0;
    test->tree2 = 0;

    return test;
}
