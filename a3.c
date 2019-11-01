#include <stdio.h>
#include "title.h"
#include "principals.h"
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

    for (int i = 9660364; i < 9660380; i++)
    {
        printf("%d - %s - %s\n", i, ptr[i].nconst, ptr[i].primaryName);
    }

    //before ending, need to find a way to find total number of constantly?

    /*
      struct title_basics *ptr = get_title(argv[1]);
    printf("\n\n");
    for (int i = 600000; i < 6267470; i++)
    {

        printf("%d - %s - %s\n", i, ptr[i].tconst, ptr[i].primaryTitle);
    }
        struct title_principals *ptr = get_title_principals(argv[1]);
    printf("\n\n");
    for (int i = 0; i < 1000000; i++)
    {
        printf("%d - %s - %s - %s\n", i, ptr[i].tconst, ptr[i].nconst, ptr[i].characters);
    }

  

    

  
    */
    return 0;
}
