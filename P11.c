//
//  P21.c
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
                         //  printf("%c,", temp[i]);
                           if(temp[i] != 'X'){
                               isValid = false;
                               break;
                           }
                         }
    return isValid;
}
int totalAnagram(char *temp, char* array[]){
    long tempLength = strlen(temp);
    int countAnagram = 0;
    char *clonedTemp = malloc(1000);
    strcpy(clonedTemp, temp);

      
     int i = 0;

          int arrayIndex = 0;
          while(i != tempLength){
              //invalid
              if(arrayIndex > 29999){
                  
                  break;
              }
              else{
                  //skip those that are not the same length
                  long tempLengthArray = strlen(array[arrayIndex]);
                  
                  if(tempLengthArray != tempLength){
                         //      printf("HHHHHERE %s, %s\n", temp, array[arrayIndex] );
                               i = 0;
                               arrayIndex++;
                              
                               continue;
                           }
              }
           
              //user inputed variable in char
              char myTempChar = temp[i];
              int j = 0;
            //  printf("\ncurrChar: %c\n", myTempChar);
              while(j != tempLength){
                  //
                  char myArrayChar = array[arrayIndex][j];
                //  printf("%c\t", myArrayChar);
                  if(myTempChar == myArrayChar){
                   //   printf("Found!%c @ index: %d \n", myTempChar, j);
                      temp[i] = 'X';
                      array[arrayIndex][j] = 'X';
                      break;
                  }
                  j++;
              }
              //1802938834
              i++;
              if(i == tempLength){
               bool isValid = validateAnagram(temp);
                  
                  if(isValid == true){
                      countAnagram++;
                   //   printf("\nvalid anagram: %s @ arrayIndex %d", temp, arrayIndex);
                  }
                  if(arrayIndex < 30000){
                      i = 0;
                      arrayIndex++;
                      strcpy(temp, clonedTemp);
                      continue;
                  }
              }
          
          //printf("??%s\n", tempArray[sizeof);
         // printf("\n");
       
      }
       return countAnagram;


}
void swap(int *i, int *i2)
{
    int temp = *i;
    *i = *i2;
    *i2 = temp;
}
long sortOneNumber(int num){
    int j = 0;
       int clone = num;

       int length = 0;
       while(clone != 0){
           clone = clone /10;
           length++;
       }
       printf("%d, length\n", length);
       int orderNum[length];
       for (int i = 0; i < length; i++) {
           orderNum[i] = num % 10;
           num = num / 10;
       }
    printf("\n\n");
       for (int i = 0 ; i < length; i++) {
            int min = i;
           
            for (j = i + 1; j < length; j++) {
                if(orderNum[min] < orderNum[j]){
                    min = j;
                }
            }
            swap(&orderNum[min], &orderNum[i]);
        }

 

    //turn into a number
    char buff[length + 1];
    for (int i =0; i<length; i++) {
        
           sprintf(&buff[i],"%d",orderNum[i]);
       }
    char *str;
  long  ret = strtol(buff, &str, 10);
    
    return ret;
}
//length - 1 for end of indices


int main(int argc, const char * argv[]) {
    char *fileName = malloc(30);
    strcpy(fileName, "data_4.txt");
    char *unsortedarray[30000];
    char *sortedarray[30000];
    int intArray[30000];
    int intArray2[30000];
    int j = 0;
    //turns into an int
    p2InsertArray(fileName, unsortedarray);
    for (int i = 0; i < 30000; i++) {
        intArray[i] = atoi(unsortedarray[i]);
    }
    
  printf("\n%ld\n",sortOneNumber(1804289383));
    
    for (int i = 0 ; i < 30000; i++) {
        int min = i;
        for (j = i + 1; j < 30000; j++) {
            if(intArray[min] > intArray[j]){
                min = j;
            }
        }
        swap(&intArray[min], &intArray[i]);
    }
    //Re-sort
    

    
    
    
    return 0;
 
}
