
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

void swap(long *i, long *i2)
{
    long temp = *i;
    *i = *i2;
    *i2 = temp;
}
//sorts by signature
long sortOneNumber(long num){
    int j = 0;
       long clone = num;

       int length = 0;
       while(clone != 0){
           clone = clone /10;
           length++;
       }
       long orderNum[length];
       for (int i = 0; i < length; i++) {
           orderNum[i] = num % 10;
           num = num / 10;
       }
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
        
           sprintf(&buff[i],"%ld",orderNum[i]);
       }
    char *str;
  long  ret = strtol(buff, &str, 10);
    
    return ret;
}
//length - 1 for end of indices


int main(int argc, const char * argv[]) {
    char *fileName = malloc(30);
    strcpy(fileName, "data_4.txt");
    //Length of data_4.txt (adjust according to length of file)
    long length =30000;
    char *unsortedarray[length];
    long longArray[length];
    int j = 0;
    long temp = 0;
    printf("Which string are you looking to anagram  using pre-sorting \n");
     scanf("%ld", &temp);
    temp = sortOneNumber(temp);
    p2InsertArray(fileName, unsortedarray);
    
    //sorts signature numbers
    for (int i = 0; i < length; i++) {
        longArray[i] = sortOneNumber(atol(unsortedarray[i]));
    }

    //sorts array by indices
    for (int i = 0 ; i < length; i++) {
        int min = i;
        for (j = i + 1; j < length; j++) {
            if(longArray[min] > longArray[j]){
                min = j;
            }
        }
        swap(&longArray[min], &longArray[i]);
    }
    //printf("%ld\n @ i %d|||\n", unsortedarray[26209], 26209);
    
    int i = 0;
    int totalAnagram = 0;
    //Checking the frequency: Modified version of the book's presort function
        long runValue = temp;
        while(i < length){
            if(longArray[i] == runValue){
                totalAnagram++;
            }
                i++;
    }
    printf("Total Anagram: %d", totalAnagram);
    
    return 0;
 
}
 
 
