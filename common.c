/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#include <string.h>
#include <stdlib.h>

#include "common.h"
#include "binary.h"

int totalRows(FILE *fp)
{
    int i = 0;
    char buff[256];
    while (fgets(buff, 256, fp) != NULL)
    {
        i++;
    }
    fseek(fp, 0, SEEK_SET);
    return i - 1;
}
char *get_column(char *src, int colNum)
{
    char *dst = malloc(strlen(src));
    const char delimiter[] = "\t";
    char *tmp;
    int num;
    tmp = strtok(src, delimiter);
    num = 0;
    while (tmp != NULL)
    {

        if (num == colNum)
        {
            strcat(tmp, "\0");

            strcpy(dst, tmp);
            break;
        }

        tmp = strtok(NULL, delimiter);
        if (tmp == NULL)
        {
            break;
        }

        num++;
    }

    return dst;
}
