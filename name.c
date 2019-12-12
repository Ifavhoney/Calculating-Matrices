/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#include "name.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 9700000

struct arrayStruct *
get_name(char *value)
{
    char *result = NULL;
    FILE *fp = NULL;
    char buff[256];
    long length;
    int i;
    int total;
    char *ptr;
    struct name_basics *array = NULL;
    struct arrayStruct *test = NULL;

    static int hi[ARRAY_SIZE];

    ptr = malloc(strlen(value) + strlen("/name.basicsss.tsv") + 1);
    strcat(ptr, value);
    strcat(ptr, "/name.basics.tsv");
    length = strlen(ptr);
    printf("PTR: %s\n", ptr);
    fp = fopen(ptr, "r");
    free(ptr);
    i = 0;
    total = totalRows(fp);

    if (fp != NULL)
    {
        while (fgets(buff, 256, fp) != NULL && i <= ARRAY_SIZE)
        {
            length += strlen(buff);

            result = get_column(buff, 4);

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
    test = (struct arrayStruct *)malloc(sizeof(struct arrayStruct)); /*malloc(i / 2);*/
    test->size = i / 2;
    test->address = array;
    test->tree1 = 0;
    test->tree2 = 0;
    return test;
}
