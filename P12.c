
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>

//Essentially turns file into an array (modified version of my A2 code)
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
//Swap function between one indices & the other
void swap(long *i, long *i2)
{
    long temp = *i;
    *i = *i2;
    *i2 = temp;
}
//sorts by signature
long sortOneNumber(long num){
    //Cloning number
        int j = 0;
       long clone = num;

       int length = 0;
       //Using number to dynamically find the length 
       while(clone != 0){
           clone = clone /10;
           length++;
       }
        //Storing the last digit inside the array
       long orderNum[length];
       for (int i = 0; i < length; i++) {
           orderNum[i] = num % 10;
           num = num / 10;
       }
       //Ordering the array in descending order
       for (int i = 0 ; i < length; i++) {
            int min = i;
           
            for (j = i + 1; j < length; j++) {
                if(orderNum[min] < orderNum[j]){
                    min = j;
                }
            }
            swap(&orderNum[min], &orderNum[i]);
        }

    //Turning our array into one string
    char buff[length + 1];
    for (int i =0; i<length; i++) {
        
           sprintf(&buff[i],"%ld",orderNum[i]);
       }
    //turning string into long number
    char *str;
  long  ret = strtol(buff, &str, 10);
    
    return ret;
}


int main(int argc, const char * argv[]) {
     //Neccessary structs to find time
      struct timeb firstStart, firstEnd;
        int elapsedTime = 0;
      ftime(&firstStart);

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
   

  //Calculating the total time & if the time is less than 0ms, set to 0
 ftime(&firstEnd);
      elapsedTime = firstEnd.millitm - firstStart.millitm;
      if(elapsedTime <=0){
          elapsedTime = 0;
      }

      printf("\nelasedTime for presorting technique %dms\n", elapsedTime);
    return 0;
 
}
*/
 
 
