
#include "title.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>
#define ARRAY_SIZE 6467470

struct arrayStruct *
get_title(char *value)
{
    char *ptr = value;
    /* Using relative path holds the full path e.g  "./files/name.basics.tsv" */
    //strcat(ptr, "/name.basics.tsv");

    strcat(ptr, "/title.basics.tsv");
    //Got the length
    long length;
    length = strlen(ptr);
    struct arrayStruct *test = NULL;

    //pointer array to return a pointer of type name basics
    struct title_basics *array;

    static int hi[ARRAY_SIZE];

    static int hi2[ARRAY_SIZE];

    char buff[256];
    FILE *fp;

    //"/files/txt"
    fp = fopen(ptr, "r");
    printf("ptr is %s\n", ptr);
    int i = 0;

    int total = totalRows(fp); // 4

    if (fp != NULL)
    {

        while (fgets(buff, 256, fp) != NULL)
        {
            length += strlen(buff);
            char *result = get_column(buff, 4);

            if (strstr(result, "0") != NULL)
            {

                //1 for found
                hi2[i] = 1;
            }
            else
            {

                hi2[i] = 0;
            }
            i++;
        }
        array = malloc(length);

        i = 0;
        fseek(fp, 0, SEEK_SET);

        while (fgets(buff, 256, fp) != NULL)
        {

            char *result = get_column(buff, 1);

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

            //Use column to pull out the nconst and primary name

            if (i <= total)
            {
                char *result1 = get_column(buff, 0);
                if (hi[i] == 0 || hi2[i] == 0)
                {
                    //then ok
                    array[i].tconst = NULL;
                }
                else
                {

                    array[i].tconst = result1;

                    //switch 2
                }
            }

            else
            {

                char *result2 = get_column(buff, 1);
                if (hi[i - total - 1] == 0 || hi2[i - total - 1] == 0)
                {
                    //then ok
                    array[i - total - 1].primaryTitle = NULL;
                }
                else
                {

                    //switch 2
                    array[i - total - 1].primaryTitle = result2;
                }
            }

            if (i == total)
            {

                fseek(fp, 0, SEEK_SET);
            }

            //use strdup function to malloc memory

            //  array[0].nconst= strdup(result1);
            //increments to next
            //  array[1].primaryName = strdup(result2);
            //array++;
            i++;

            // break;
        }
    }
    else
    {
        printf("unable to open file");
    }

    //printf("array @ 1 is %s", array[4].primaryName);
    test = malloc(sizeof(array));

    test->size = i / 2;
    test->address = array;
    test->tree1 = 0;
    test->tree2 = 0;

    //printf("%s", *test);
    return test;
}
//a string that contains entire line from the file, where contents will be copied to, a column number
