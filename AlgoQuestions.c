//
//  a2.c
//  A23490
//
//  Created by Jason Eddy on 2020-02-02.
//  Copyright © 2020 Jason Eddy. All rights reserved.
//

#include "a2.h"

//2
void p2InsertArray(char *filename, char* arr[]){
     char buff[30];

    
        
                int i = 0;
        FILE *fp  = fopen(filename, "r");

    
        while (fgets(buff, sizeof(buff), fp)) {
            arr[i] = malloc(strlen(buff) * 2);
            strcpy(arr[i], buff);
            i++;
        }
      
    fclose(fp);

}




//1
void swap(long *i, long *i2){
    long temp = *i;
              *i = *i2;
             *i2 = temp;
}
void question3(char *fileName){
    printf("1.1 Brute force algorithm to count number of inversions: O(n^2)\n");

    struct timeb firstStart, firstEnd;
    int elapsedTime = 0;
    long length = getLength(fileName);
    long arr[length];
          long inversion = 0;
          long numOperations = 0;
    insertToArray(fileName, arr);
    ftime(&firstStart);

   question1(length, arr);
    ftime(&firstEnd);
    elapsedTime = firstEnd.millitm - firstStart.millitm;
    printf("\nTime: %dms ", elapsedTime);

    printf("\n\n");
    

    
    printf("1.2 Begin QuickSort Algorithm using Divide & Conquer: O(nlogn)\n");
      struct timeb start, end;
        
        elapsedTime = 0;
      ftime(&start);
       inversion = 0;
       numOperations = 0;
      
      question2(length, 0, arr, &inversion, &numOperations);
       printf("Inversion: %ld\nnumOperations: %ld", inversion, numOperations);
      printf("\n The n/2 is based on always splitting the array, whereas the O(n) consits of the number of times the partition is occuring\n");
       printf("\nThus, the Masters Thereom: T (n) = 2T ( n/2 ) + Θ(n)\n");
      free(fileName);
      ftime(&end);
      elapsedTime =  end.millitm-start.millitm;
      printf("\nTime: %dms ", elapsedTime);
     
    

}
//Source from slides
void question1( long length, long arr[]){
    int j = 0;
    int i = 0;
    int min = 0;
    int inversion = 0;
    if(arr == NULL){
        printf("empty");
        return;
    }
    else{
        for ( i = 0; i <= length-2; i++) {
            min = i;
            for (j = i + 1; j <= length-1; j++) {
                //if the next element is greater than our min, store
                if(arr[j] > arr[min]){
                    min = j;
                }
                //keep going untill get last min
            }
            inversion++;
            swap(&arr[i], &arr[min]);
       
        }
        printf("Inversions: %d\nNumOperations: %d\n", inversion, j + i );
        
    }
}




/*
 1.2 Design a recursive divide-and-conquer algorithm of Θ(nlogn) to count the number of inversions in an array, set up a recurrence to analyze the number of executions of its basic operation of the best case, and determine the efficiency class. Use the Master Theorem to verify the efficiency class in your analysis result
 */
//Source from book
void question2(long length, int start, long arr[], long *inversion, long *numOperations){
    if(start < length){
        int s = partition(length, start, arr, inversion, numOperations);
        question2(s-1, start, arr, inversion,  numOperations);
        question2(length, s+1, arr, inversion,  numOperations);
         }
    
    
}
//length - 1 for end of indices
int partition(long length, int start, long arr[], long *inversion, long *numOperations){

    long selected_element = arr[length - 1];

    int index = start - 1;
    //length - 2 because we'll be changing the last indices at the end
    for (int j = start; j <= length-2; j++) {
        (*numOperations)++;

        if(arr[j] < selected_element){
            //convert from point to int, to increment
            (*inversion)++;
            index++;
            //consider creating function
            swap(&arr[index], &arr[j]);
        }
    }

    (*inversion)++;

    swap(&arr[index + 1], &arr[length-1]);

    return (index + 1);
}

void insertToArray(char *filename, long arr[]){
    long length = getLength(filename);
    long data = 0;
    int i = 0;
    if(length != -1){
        FILE *fp = fopen(filename, "r");
            fscanf (fp, "%ld", &data);
                  while (!feof (fp))
                    {
                        arr[i] = data;
                        fscanf (fp, "%ld", &data);
                        i++;

                    }
        
        
    }
    
}
long getLength(char *filename){
    int length = 0;
     long data = 0;
     FILE *fp = fopen(filename, "r");
        if(fp == NULL){
            printf("null");
            return -1;
        }
     fscanf (fp, "%ld", &data);
        while (!feof (fp))
          {
             length++;
              fscanf (fp, "%ld", &data);

          }
    return length;
}





int main(int argc, const char * argv[]) {
    char *fileName = malloc(30);
    strcpy(fileName, "data_2.txt");
    char *array[30000];
    p2InsertArray(fileName, array);
    int i = 0;
    int j = 0;
    char *val;
    float c, x = 0, y = 0;
    while (i != 29999) {
        val =  strtok(array[i], "    ");
        while (val != NULL) {
            if(j == 0){
                x = atof(val);
                printf("X:%f\n", x);

            }
            else{
                if(y == 0){
                    y = atof(val);
                    printf("Y:%f\n", y);
                    c = y + x;
                }
                
                
            }
        
            
            j++;

            val = strtok(NULL, "    ");
            

        }
        
        x = 0;
        y = 0;
        j = 0;
        i++;
    }


     
    free(fileName);
 //   p2InsertArray(fileName, <#char **arr#>)
    return 0;

  
}
