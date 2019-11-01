#include "principals.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 1500000

struct title_principals *get_title_principals(char *value)
{
    char *ptr = value;
    /* Using relative path holds the full path e.g  "./files/name.basics.tsv" */
    //strcat(ptr, "/name.basics.tsv");

    strcat(ptr, "/title.principalss.tsv");
    //Got the length
    long length;
    length = strlen(ptr);

    //pointer array to return a pointer of type name basics
    struct title_principals *array;

    static int hi[ARRAY_SIZE];

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
            //why dpes it work over here? and segfaults?
            //memory not allocated in time, therefore best to allocaste BEFORE getting to isnertion
            array = malloc(strlen(buff) + 1);

            char *result = get_column(buff, 3);

            if (strstr(result, "actor") != NULL)
            {
                hi[i] = 1;
            }
            else
            {
                //SEE?? NOT ENOUGH SPACE
                hi[i] = 0;
            }
            i++;
        }

        i = 0;
        fseek(fp, 0, SEEK_SET);

        while (fgets(buff, 256, fp) != NULL)
        {

            char *result = get_column(buff, 5);

            if (hi[i] == 0)
            {
                //then ok
                array[i].characters = NULL;
            }
            else
            {

                array[i].characters = result;

                //switch 2
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
                if (hi[i] == 0)
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

                char *result2 = get_column(buff, 2);
                if (hi[i - total - 1] == 0)
                {
                    //then ok
                    array[i - total - 1].nconst = NULL;
                }
                else
                {

                    //switch 2
                    array[i - total - 1].nconst = result2;
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

    fclose(fp);
    return array;
}
//a string that contains entire line from the file, where contents will be copied to, a column number
