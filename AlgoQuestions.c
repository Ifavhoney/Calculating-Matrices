//
//  a2.c
//  A23490
//
//  Created by Jason Eddy on 2020-02-02.
//  Copyright © 2020 Jason Eddy. All rights reserved.
//

#include "a2.h"

void question1(int length, int arr[]){
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
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        
        int t = 0;
        for ( t = 0; t <= length-1; t++) {
            printf("%d = %d\n", t, arr[t]);
        }
        printf("Inversions: %d\nNumOperations: %d\nEfficiency class: O(n^2) \n", inversion, j + i + inversion );
        
    }
}

//length - 1 for end of indices
int partition(int length, int start, int arr[], int *inversion){

    int selected_element = arr[length - 1];
    int index = start - 1;
    //length - 2 because we'll be changing the last indices at the end
    for (int j = start; j <= length-2; j++) {
        if(arr[j] < selected_element){
            (*inversion)++;
            index++;
            //consider creating function
            swap(&arr[index], &arr[j]);
        }
    }


    swap(&arr[index + 1], &arr[length-1]);

    return (index + 1);
}




/*
 1.2 Design a recursive divide-and-conquer algorithm of Θ(nlogn) to count the number of inversions in an array, set up a recurrence to analyze the number of executions of its basic operation of the best case, and determine the efficiency class. Use the Master Theorem to verify the efficiency class in your analysis result
 */


