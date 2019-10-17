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
    //array is a pointer??
    fp = fopen("1342-0.txt", "r");
    struct node_struct *ptr;

    //& gets the address, but i just
    ptr = txt2words(fp);
    fclose(fp);

    fp = fopen("output.txt", "w");
    ftext(fp, ptr);

    /*
    char txt[] = "Hello Jason Eddy MK\nKaizer God";
    list = (struct node_struct *)malloc(sizeof(struct node_struct));
    list -> data = txt ;
    //how to reference the pointer - nneed a double pointer
   //  get_word(&list);
     */
    free(ptr);

    return 0;
}
