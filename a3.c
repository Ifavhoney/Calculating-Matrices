#include <stdio.h>
#include "name.h"
int main(int argc, char **argv)
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage:  %s directory\n", argv[0]);
        return -1;
    }

    struct name_basics *ptr = get_name(argv[1]);
    printf("\n\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%s - %s\n", ptr[i].nconst, ptr[i].primaryName);
    }
    return 0;
}
