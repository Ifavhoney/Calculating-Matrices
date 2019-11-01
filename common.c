//
//  common.c
//  assignment3
//
//  Created by Jason Eddy on 2019-10-29.
//  Copyright © 2019 Jason Eddy. All rights reserved.
//

#include <string.h>
#include <stdlib.h>

#include "common.h"

//calculates #of rows based on file
int totalRows(FILE *fp){
    int i = 0;
    char buff[256];
    while (fgets(buff, 256, fp) != NULL){
        i++;
    }
    fseek(fp, 0, SEEK_SET);
    return i-1;

}
/*prints the values of a given column - may have to change to single pointer*/
char *get_column(char *src, int colNum){
    char *dst = NULL;
    dst = malloc(256);
    const char delimiter[] = "\t";
    char *tmp;
    //takes the src, and looks for a space
    tmp = strtok(src, delimiter);
    int num = 0;
    while (tmp!= NULL) {
        //looks for next tab

        //0 shouldnt it stop at 0??
                 if(num == colNum){
                   strcat(tmp, "\0");
                     strcpy((char *)dst, tmp);
   
                   break;
               }
        
            tmp = strtok(NULL, delimiter);
                   if (tmp == NULL){
                       break;

                   }
       
        num++;

    }

    //loops through input string

    return dst;
}

