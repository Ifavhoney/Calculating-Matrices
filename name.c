
#include "name.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

//returns a pointer to an array of struct name basics
struct name_basics *get_name(char *value)
{
    char *ptr = value;
    /* Using relative path holds the full path e.g  "./files/name.basics.tsv" */
    //strcat(ptr, "/name.basics.tsv");

    strcat(ptr, "/name.basicss.tsv");
    //Got the length
    long length;
    length = strlen(ptr);

    //pointer array to return a pointer of type name basics
    struct name_basics *array;
    struct name_basics *array2;
    array = malloc(length + 2);

    array = malloc(length + 2);

    array2 = NULL;
    long hi[250];
    char buff[256];
    FILE *fp;

    //"/files/txt"
    fp = fopen(ptr, "r");
    printf("ptr is %s\n", ptr);
    int i = 0;

    int total = totalRows(fp); // 4
    struct name_basics *name;

    if (fp != NULL)
    {
        while (fgets(buff, 256, fp) != NULL)
        {
            struct name_basics *src = (struct name_basics *)malloc(strlen(buff) + 1);
            char *result = get_column(buff, &src->primaryName, 4);

            if (strstr(result, "actor") != NULL || strstr(result, "actress") != NULL)
            {

                //1 for found
                hi[i] = 1;
            }
            else
            {

                printf("%d IS MISSING\n", i);
                hi[i] = 0;
            }

            i++;
        }

        i = 0;
        fseek(fp, 0, SEEK_SET);
        while (fgets(buff, 256, fp) != NULL)
        {
            name = (struct name_basics *)malloc(strlen(buff) + 1);
            struct name_basics *src = (struct name_basics *)malloc(strlen(buff) + 1);

            name->primaryName = buff;

            //Use column to pull out the nconst and primary name

            if (i <= total)
            {
                char *result1 = get_column(name->primaryName, &src->primaryName, 0);
                if (hi[i] == 0)
                {
                    //then ok
                    array[i].nconst = NULL;
                }
                else
                {

                    array[i].nconst = result1;

                    //switch 2
                }
            }

            else
            {

                char *result2 = get_column(name->primaryName, &src->primaryName, 1);
                if (hi[i - total - 1] == 0)
                {
                    //then ok
                    array[i - total - 1].primaryName = NULL;
                }
                else
                {

                    //switch 2
                    array[i - total - 1].primaryName = result2;

                    printf("I IS %d", i);
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
