
#include "name.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 9700000
//returns a pointer to an array of struct name basics
struct name_basics *
get_name(char *value)
{
    char *ptr = value;
    /* Using relative path holds the full path e.g  "./files/name.basics.tsv" */
    //strcat(ptr, "/name.basics.tsv");

    strcat(ptr, "/name.basics.tsv");
    //Got the length
    long length;
    length = strlen(ptr);

    //pointer array to return a pointer of type name basics
    struct name_basics *array;
    struct name_basics *test;
    // array = malloc(strlen(ptr) + 1);
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
            length += strlen(buff);

            char *result = get_column(buff, 4);

            if (strstr(result, "actor") != NULL || strstr(result, "actress") != NULL)
            {

                //1 for foundx
                hi[i] = 1;
            }
            else
            {

                hi[i] = 0;
            }
            i++;
        }
        array = malloc(length);
        //array = malloc(strlen(buff) + 1)
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

                char *result2 = get_column(buff, 1);
                if (hi[i - total - 1] == 0)
                {

                    //then ok
                    array[i - total - 1].primaryName = NULL;
                }
                else
                {
                    //   array = malloc(strlen(buff) + 1);

                    //switch 2
                    array[i - total - 1].primaryName = result2;
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
    //free(array);

    /*Because it reaches the end of the array that I cannot free */
    fclose(fp);
    return array;
}
//a string that contains entire line from the file, where contents will be copied to, a column number

/*


#include "name.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

//returns a pointer to an array of struct name basics
struct name_basics *get_name(char *value)
{
    char *ptr = value;
    //strcat(ptr, "/name.basics.tsv");

    strcat(ptr, "/name.basicss.tsv");
    //Got the length
    long length;
    length = strlen(ptr);

    //pointer array to return a pointer of type name basics
    struct name_basics *array;
    struct name_basics *array2;

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

        i = 0;
        fseek(fp, 0, SEEK_SET);
        while (fgets(buff, 256, fp) != NULL)
        {
            array = malloc(strlen(buff) + 1);

            //Use column to pull out the nconst and primary name

            array[i].nconst = "result1";

            //switch 2

            //switch 2
            array[i - total - 1].primaryName = "result2";
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
    else
    {
        printf("unable to open file");
    }

    //printf("array @ 1 is %s", array[4].primaryName);

    fclose(fp);
    return array;
}
*/
