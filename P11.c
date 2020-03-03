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
#include <stdbool.h>

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
bool validateAnagram(char *temp){
    bool isValid = true;

    
                  //Validate
                       for (int i  = 0; i < strlen(temp); i++) {
                           printf("%c,", temp[i]);
                           if(temp[i] != 'X'){
                               printf("not a valid anagaram" );
                               isValid = false;
                               break;
                           }
                         }
    return isValid;
}

int main(int argc, const char * argv[]) {
    char *fileName = malloc(30);
    strcpy(fileName, "data_4.txt");
    char *array[30000];
    char *temp = malloc(1000);
    int countAnagram;
    p2InsertArray(fileName, array);

    printf("Which string are you looking to anagram  \n");
    scanf("%s", temp);
    int i = 0;
    strcpy(temp, "1802938834");
    //ARRAY: 1804289383
   // printf("%s", array[0]);
    long tempLength = strlen(temp);
    long tempLengthArray = strlen(array[0]);
   
        int arrayIndex = 0;
        while(i != tempLength && arrayIndex != tempLengthArray){
            /*
            if(tempLength != tempLengthArray){
                printf("???");
                i = 0;
                arrayIndex++;
                continue;
                   //Means no good so we'll continue
               }
             */
            //e.g 1
            char myTempChar = temp[i];
            int j = 0;
            printf("\ncurrChar: %c\n", myTempChar);
            while(j != tempLength){
                char myArrayChar = array[arrayIndex][j];
                printf("%c\t", myArrayChar);
                if(myTempChar == myArrayChar){
                    printf("Found!%c @ index: %d \n", myTempChar, j);
                    temp[i] = 'X';
                    array[arrayIndex][j] = 'X';
                    break;
                }
                j++;
            }
            
            i++;
            if(i == tempLength){
              
               // tempLengthArray++;
             bool isValid = validateAnagram(temp);
                if(isValid == true){
                    
                }
               // printf("%s");
                
            }
        
        //printf("??%s\n", tempArray[sizeof);
        printf("\n");
     
         
          
    }
    //Retain array
  p2InsertArray(fileName, array);

    i = 0;
    free(temp);
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

