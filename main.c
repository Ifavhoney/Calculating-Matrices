//
//  main.c
//  assignment2
//
//  Created by Jason Eddy on 2019-10-09.
//  Copyright © 2019 Jason Eddy. All rights reserved.
//

#include "text.h"

int main(int argc, const char *argv[])
{
    FILE *fp;
    fp = fopen("1342-0.txt", "r");
    *txt2words(fp);

    char txt[] = "Hello Jason Eddy MK\nKaizer God";
    struct node_struct *list;
    list = (struct node_struct *)malloc(sizeof(struct node_struct));
    list->data = txt;
    free(list);

    fclose(fp);
    return 0;
}
