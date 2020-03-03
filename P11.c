//
//  P11.c
//  a3490
//
//  Created by Jason Eddy on 2020-03-02.
//  Copyright © 2020 Jason Eddy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void p2InsertArray(char *filename, char* arr[]){
     char buff[10000];
    char num1[100];
    char num2[100];
    char num3[100];
    char num4[100];
    char num5[100];


    int count = 0;
        int i = 0;
        FILE *fp  = fopen(filename, "r");
    
        while (fgets(buff, sizeof(buff), fp)) {
            sscanf(buff, "%s %s %s %s %s", num1, num2, num3, num4, num5);
            count = 1;
            if(strcmp(buff, " ") != 0){
                
        
            while(count <= 5){
                if(count == 1){
                    arr[i] = calloc(1, strlen(num1) + 2);
                                      strcpy(arr[i], num1);
                    }
                else if(count == 2){
                    arr[i] = calloc(1, strlen(num2) + 2);
                                                    strcpy(arr[i], num2);
                }
                else if(count == 3 && strlen(num3) > 1){
                                  arr[i] = calloc(1, strlen(num3) + 2);
                                                                  strcpy(arr[i], num3);
                              }
                else if(count == 4 && strlen(num4) > 1){

                                               arr[i] = calloc(1, strlen(num4) + 2);
                                                                               strcpy(arr[i], num4);
                                           }
                else if(count == 5 && strlen(num5) > 1){

                        arr[i] = calloc(1, strlen(num5) + 2);
strcpy(arr[i], num5);
                                                         }
                count++;
               
                i++;
            }
                }
            
            
        }
      
    fclose(fp);

}

int main(int argc, const char * argv[]) {
    char *fileName = malloc(30);
    strcpy(fileName, "data_4.txt");
    char *array[30000];
    p2InsertArray(fileName, array);
 printf("%s", array[6]);
 int i = 0;

while (i <= sizeof(array)/sizeof(array[0])){
    //empty
    if(strlen(array[i]) < 3 || strstr(array[i], " ") != NULL){
break;
    }
    else{
           free(array[i]);
    }
    i++;
}
    return 0;
}

