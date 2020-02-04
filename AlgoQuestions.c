//
//  a2.c
//  A23490
//
//  Created by Jason Eddy on 2020-02-02.
//  Copyright © 2020 Jason Eddy. All rights reserved.
//

#include "a2.h"


//2
void p2ArraytoPoints(char *array[], struct Vertices points[]){
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
                    
                    points[pointCounter].x = x1;
                    points[pointCounter]. y = y1;
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
    p2InsertArray("data_2.txt",  array);
    i = 0;
 
}
int p2GetlengthSorted(char *filename,char *array[], struct Vertices points[]){
    
    int i = 0;
            int j = 0;
            float c2 = 0, x2 = 0, y2 = 0;
    int totalPoints = 0;
         char *val;
         p2InsertArray(filename, array);
         p2ArraytoPoints(array, points);
    float a = 0;
           float b = 0;
           while (i != 29999) {
               
               val =  strtok(array[i], "    ");
               while (val != NULL) {
                   if(x2 == 0){
                       x2 = atof(val);

                   }
                   else{
                       if(y2 == 0){
                           //stores into y2
                           y2 = atof(val);
                           c2 = y2 + x2;
                           /*a = y2 − y1, b = x1 − x2, c = x1y2 − y1x2. || ax + by = c, p.113*/
                           for (int k = 0; k < 15000; k++) {
                               a = y2 - points[k].y;
                               b = points[k].x - x2;
                               float c = a + b;
                              if( c == c2){
                                 
                                  totalPoints++;
                                  
                                //   printf("Line Match - i:%d @ ax+by = %f \n", k, c );
                               }
                           }
                           
                       }
                }
                   val = strtok(NULL, "    ");
                   
               }
               x2 = 0;
               y2 = 0;
               j = 0;
               i++;
           }
    for (int l = 0; l < 15000; l++) {
        free(array[l]);
    }
    return totalPoints;

}
void p2halfQ3(char *filename,char *array[], struct Vertices points[], struct Vertices sortedPoints[], int length){
    // float points[15000];
         int i = 0;

            int j = 0;
            float c2 = 0, x2 = 0, y2 = 0;
    int totalPoints = 0;
         char *val;
         p2InsertArray(filename, array);
         p2ArraytoPoints(array, points);
        
    float a = 0;
           float b = 0;
           while (i != 29999) {
               val =  strtok(array[i], "    ");
               while (val != NULL) {
                   if(x2 == 0){
                       x2 = atof(val);

                   }
                   else{
                       if(y2 == 0){
                           //stores into y2
                           y2 = atof(val);
                           c2 = y2 + x2;
                           /*a = y2 − y1, b = x1 − x2, c = x1y2 − y1x2. || ax + by = c, p.113*/
                           for (int k = 0; k < 15000; k++) {
                               a = y2 - points[k].y;
                               b = points[k].x - x2;
                               float c = a + b;
                              if( c == c2){
                                  
                                  sortedPoints[totalPoints].x = points[k].x;
                                  sortedPoints[totalPoints].y = points[k].y;
                                 // printf("\n%f\n", sortedPoints[i].x);

                                  totalPoints++;
                                  
                               }
                           }
                           
                       }
                }
                   val = strtok(NULL, "    ");
                   
               }
               x2 = 0;
               y2 = 0;
               j = 0;
               i++;
           }
    
    sortByX(length, 0, sortedPoints);
    
   
          
           
    
}



void p2Question1(char *filename, char *array[], struct Vertices points[]){
    
       // float points[15000];
        int i = 0;
           int j = 0;
           float c2 = 0, x2 = 0, y2 = 0;
        char *val;
        p2InsertArray(filename, array);
        p2ArraytoPoints(array, points);
        //Reduced code from N^4 to N^3, had to implement it this way in order to check all points

        float a = 0;
        float b = 0;
        while (i != 29999) {
            
            val =  strtok(array[i], "    ");
            while (val != NULL) {
                if(x2 == 0){
                    x2 = atof(val);

                }
                else{
                    if(y2 == 0){
                        //stores into y2
                        y2 = atof(val);
                        c2 = y2 + x2;
                        /*a = y2 − y1, b = x1 − x2, c = x1y2 − y1x2. || ax + by = c, p.113*/
                        for (int k = 0; k < 15000; k++) {
                            a = y2 - points[k].y;
                            b = points[k].x - x2;
                            float c = a + b;
                           if( c == c2){
                                printf("Line Match - i:%d @ ax+by = %f \n", k, c );
                            }
                        }
                        
                    }
             }
                val = strtok(NULL, "    ");
                
            }
            x2 = 0;
            y2 = 0;
            j = 0;
            i++;
        }
       
        for (int f = 0; f < 29999; f++) {
            free(array[f]);
        }
        printf("\n\nThe brute force algorithm consits of O(n^3) - all simply due to the triple nested loop\n\n");
        
}

   
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



void swapf(float *i, float *i2){
    float temp = *i;
              *i = *i2;
             *i2 = temp;
}//1
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
//consider remove the -1
    long selected_element = arr[length ];

    int counter = start - 1;
    //length - 2 because we'll be changing the last indices at the end
    int i = start;

    while(i != length-1){
        (*numOperations)++;

        if(arr[i] < selected_element){
            //convert from point to int, to increment
            (*inversion)++;
            counter++;
            //consider creating function
            swap(&arr[counter], &arr[i]);
        }
    }

    (*inversion)++;

    swap(&arr[counter + 1], &arr[length-1]);

    return (counter + 1);
}


//length - 1 for end of indices
int partitionByX(long length, int start, struct Vertices points[]){
    float selected_element = points[length].x;

    int counter = start - 1;
   int i = start;
    while(i != length){
        if(points[i].x < selected_element){
                   //convert from point to int, to increment
                   counter++;
                   //consider creating function
                   swapf(&points[counter].x, &points[i].x);
               }
        i++;
    }
   
    swapf(&points[counter + 1].x, &points[length].x);
    return (counter + 1);
}


void sortByX(long length, int start, struct Vertices points[]){
    if(start < length){
        int s = partitionByX(length, start, points);
        sortByX(s-1, start, points);
        sortByX(length, s+1, points);
         }
    
    
}
 

/*
int partition(long length, int start, long arr[], long *inversion, long *numOperations)
{
    long pivot = arr[length]; // pivot
    int i = (start - 1); // Index of smaller element
  
    for (int j = start; j <= length; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[length]);
    return (i + 1);
}
 */
  
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */

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



