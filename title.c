
#include "title.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

struct title_basics *get_title(char *value)
{
    char *ptr = value;
    /* Using relative path holds the full path e.g  "./files/name.basics.tsv" */
    //strcat(ptr, "/name.basics.tsv");

    strcat(ptr, "/title.basicss.tsv");
    //Got the length
    long length;
    length = strlen(ptr);

    //pointer array to return a pointer of type name basics
    struct title_basics *array;
    struct title_basics *array2;
    array = malloc(10000);

    array2 = NULL;
    long hi[500000];

    long hi2[500000];

    char buff[256];
    FILE *fp;

    //"/files/txt"
    fp = fopen(ptr, "r");
    printf("ptr is %s\n", ptr);
    int i = 0;

    int total = totalRows(fp); // 4
    struct title_basics *name;

    if (fp != NULL)
    {

        while (fgets(buff, 256, fp) != NULL)
        {
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

    free(name);
    fclose(fp);
    return array;
}
//a string that contains entire line from the file, where contents will be copied to, a column number
