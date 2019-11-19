/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#include "principals.h"
#include "common.h"

#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 197000000

struct arrayStruct
    *
    get_title_principals(char *value)
{
    long length;
    char *result;
    char *result1;
    char *result2;
    struct arrayStruct *test = NULL;
    FILE *fp = NULL;
    char buff[256];
    int i;
    int total;

    struct title_principals *array = NULL;
    static int hi[ARRAY_SIZE];

    char *ptr = malloc(strlen(value) + strlen("/title.principals.tsv") + 1);

    strcat(ptr, value);
    strcat(ptr, "/title.principals.tsv");

    length = strlen(ptr);

    i = 0;
    fp = fopen(ptr, "r");
    printf("ptr is %s\n", ptr);

    free(ptr);
    total = totalRows(fp);

    if (fp != NULL)
    {
        while (fgets(buff, 256, fp) != NULL && i < ARRAY_SIZE)
        {

            length += strlen(buff);

            result = get_column(buff, 3);

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
        array = malloc(sizeof(struct title_principals) * i);

        i = 0;
        fseek(fp, 0, SEEK_SET);

        while (fgets(buff, 256, fp) != NULL)
        {

            if (i <= total)
            {
                result1 = get_column(buff, 0);
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

                result2 = get_column(buff, 2);
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

    test = (struct arrayStruct *)malloc(sizeof(struct arrayStruct)); /*malloc(sizeof(array));*/

    test->size = i / 2;
    test->address = array;
    test->tree1 = 0;
    test->tree2 = 0;
    return test;
}
