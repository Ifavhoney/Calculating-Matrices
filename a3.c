#include <stdio.h>
#include "title.h"
int main(int argc, char **argv)
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage:  %s directory\n", argv[0]);
        return -1;
    }

    struct title_basics *ptr = get_title(argv[1]);
    printf("\n\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%s - %s\n", ptr[i].tconst, ptr[i].primaryTitle);
    }

    /*
    struct name_basics *ptr = get_name(argv[1]);
    printf("\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s - %s\n", ptr[i].nconst, ptr[i].primaryName);
    }
    */
    return 0;
}
