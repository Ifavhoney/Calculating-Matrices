//
//  main.c
//  A23490
//
//  Created by Jason Eddy on 2020-02-02.
//  Copyright © 2020 Jason Eddy. All rights reserved.
//


#include "a2.h"

int main(int argc, const char * argv[]) {
    char *fileName = malloc(30);
    strcpy(fileName, "data_2.txt");
    char *array[30000];
    float points[15000];
    p2InsertArray(fileName, array);
   // p2ArraytoPoints(array, points);
    int i = 0;
    int j = 0;
    int pointCounter = 0;
    char *val;
    float c = 0, x1 = 0, y1 = 0;
        

    while (i != 29999) {
        val =  strtok(array[i], "    ");
        while (val != NULL) {
            if(j == 0){
                x1 = atof(val);

            }
            else{
                if(y1 == 0){
                    //stores into y1
                    y1 = atof(val);
                    c = y1 + x1;
                    points[pointCounter] = c;
                    pointCounter++;
                }
              
         }
         
            j++;

            val = strtok(NULL, "    ");
            

        }
        
        x1 = 0;
        y1 = 0;
        j = 0;
        i++;
    }
    
    //while loop for array
    //while loop for val
    //for loop if they match


    free(fileName);
 //   p2InsertArray(fileName, <#char **arr#>)
    return 0;

  
}

/*
 char *fileName = malloc(30);
     strcpy(fileName, "data_1.txt" );
  question3(fileName);
  printf("\nDespite the lesser amount of insertions + operations, Brute force is slower O(n^2) due to being closer to n! on the efficiency class, all may be due to the fact that it loops through a lot of the same values many times\nWhereas QuickSort partitions the array into smaller bits  to re-ordering time which increases execution - however more insertions + operations are needed to perform re-ordering\n");
   */
  
