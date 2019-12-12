/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#include "title.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>
#define ARRAY_SIZE 6467470

struct arrayStruct *
get_title(char *value)
{
    long length;
    char *result;
    char *result1;
    char *result2;
    struct arrayStruct *test = NULL;
    char buff[256];
    struct title_basics *array = NULL;
    FILE *fp;
    int i;
    int total;
    static int hi[ARRAY_SIZE];

    static int hi2[ARRAY_SIZE];
    /* Using relative path holds the full path e.g  "./files/name.basics.tsv" */

    char *ptr = malloc(strlen(value) + strlen("/title.basicss.tsv") + 1);

    strcat(ptr, value);
    strcat(ptr, "/title.basics.tsv");

    length = strlen(value);

    fp = fopen(ptr, "r");
    i = 0;

    total = totalRows(fp);

    if (fp != NULL)
    {
        printf("ptr is %s\n", ptr);

        free(ptr);
        while (fgets(buff, 256, fp) != NULL && i <= ARRAY_SIZE)
        {
            length += strlen(buff);
            result = get_column(buff, 4);

            if (strstr(result, "0") != NULL)
            {

                hi2[i] = 1;
            }
            else
            {

                hi2[i] = 0;
            }
            i++;
        }
        array = malloc(sizeof(struct title_basics) * i);

        i = 0;
        fseek(fp, 0, SEEK_SET);

        while (fgets(buff, 256, fp) != NULL)
        {

            result = get_column(buff, 1);

            if (strstr(result, "movie") != NULL)
            {

                hi[i] = 1;
            }
            else
            {

                hi[i] = 0;
            }
            i++;
        }

        i = 0;
        fseek(fp, 0, SEEK_SET);
        while (fgets(buff, 256, fp) != NULL)
        {

            if (i <= total)
            {
                result1 = get_column(buff, 0);
                if (hi[i] == 0 || hi2[i] == 0)
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

                result2 = get_column(buff, 2);
                if (hi[i - total - 1] == 0 || hi2[i - total - 1] == 0)
                {
                    array[i - total - 1].primaryTitle = NULL;
                }
                else
                {

                    array[i - total - 1].primaryTitle = result2;
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

    test = (struct arrayStruct *)malloc(sizeof(struct arrayStruct)); /*malloc(sizeof(array));*/

    test->size = i / 2;
    test->address = array;
    test->tree1 = 0;
    test->tree2 = 0;
    return test;
}
