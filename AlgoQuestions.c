//
//  a2.c
//  A23490
//
//  Created by Jason Eddy on 2020-02-02.
//  Copyright © 2020 Jason Eddy. All rights reserved.
//

#include "a2.h"

void swap(long *i, long *i2){
    long temp = *i;
              *i = *i2;
             *i2 = temp;
}
void question1( int length, long arr[]){
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
                    inversion++;
                }
                //keep going untill get last min
            }
            
            swap(&arr[i], &arr[min]);
       
        }
        
        int t = 0;
        for ( t = 0; t <= length-1; t++) {
            printf("%d = %d\n", t, arr[t]);
        }
        printf("Inversions: %d\nNumOperations(Without inversions): %d\nEfficiency class: O(n^2) \n", inversion, j + i );
        
    }
}




/*
 1.2 Design a recursive divide-and-conquer algorithm of Θ(nlogn) to count the number of inversions in an array, set up a recurrence to analyze the number of executions of its basic operation of the best case, and determine the efficiency class. Use the Master Theorem to verify the efficiency class in your analysis result
 */

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



