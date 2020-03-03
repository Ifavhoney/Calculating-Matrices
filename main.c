/*
Name: Jason N'Guessan
ID: 1079936
Date: March 2 2020
Assignment: Assignment3
*/


#include "a2.h"

int main(int argc, const char * argv[]) {
 
 //Question 2.3
 char *fileName = malloc(30);
          strcpy(fileName, "data_2.txt");
         char *array[30000];

   struct timeb elapsedTime;
            struct Vertices points[15000];
    int length = p2GetlengthSorted(fileName, array, points);
        printf("\nlength: %d\n", length);
        struct Vertices sortedPoint[length];
 
        p2halfQ3(fileName, array, points, sortedPoint, length);
   printf("Sorted Points found in the Convex Hull\n");
        for (int i = 0 ; i <= length; i++) {
         // printf("i:%d\tX:%f\tY:%f \n",i, sortedPoint[i].x, sortedPoint[i].y );
        }
        
   printf("\nelasedTime for bruteforce %dms\n", elapsedTime.millitm);
   printf("\nAlthough there is no recurisve means implemented here, it's expected that the convex Hull will finish faster due to being able of leveraging divide & conquer\n");

     free(fileName);
     return 0;

  
}


/*
 
 //Question 1.1
 char *fileName = malloc(30);
  strcpy(fileName, "data_1.txt");
  long length = getLength(fileName);
     long arr[length];
     insertToArray(fileName, arr);

    question1(length, arr);
 
 //end
 
 //Question 1.2
 char *fileName = malloc(30);
   strcpy(fileName, "data_1.txt");
   long length = getLength(fileName);
      long arr[length];
      insertToArray(fileName, arr);

        long inversion = 0;
       long  numOperations = 0;
        
        question2(length, 0, arr, &inversion, &numOperations);
         printf("Inversion: %ld\nnumOperations: %ld\n", inversion, numOperations);
 
 //end
 
 
 //Question 1.3
 char *fileName = malloc(30);
     strcpy(fileName, "data_1.txt" );
  question3(fileName);
  printf("\nDespite the lesser amount of insertions + operations, Brute force is slower O(n^2) due to being closer to n! on the efficiency class, all may be due to the fact that it loops through a lot of the same values many times\nWhereas QuickSort partitions the array into smaller bits  to re-ordering time which increases execution - however more insertions + operations are needed to perform re-ordering\n");
 
 //end
 //Question 2.1
  char *fileName = malloc(30);
           strcpy(fileName, "data_2.txt");
          char *array[30000];
 struct Vertices points[30000];
  p2Question1(fileName, array, points);
 //end
 
 //Question 2.3
 char *fileName = malloc(30);
          strcpy(fileName, "data_2.txt");
         char *array[30000];

   struct timeb elapsedTime;
            struct Vertices points[15000];
    int length = p2GetlengthSorted(fileName, array, points);
        printf("\nlength: %d\n", length);
        struct Vertices sortedPoint[length];
 
        p2halfQ3(fileName, array, points, sortedPoint, length);
   printf("Sorted Points found in the Convex Hull\n");
        for (int i = 0 ; i <= length; i++) {
          printf("X:%f\tY:%f \n", sortedPoint[i].x, sortedPoint[i].y );
        }
        
   printf("\nelasedTime for bruteforce %dms\n", elapsedTime.millitm);
   printf("\nAlthough there is no recurisve means implemented here, it's expected that the convex Hull will finish faster due to being able of leveraging divide & conquer\n");

     free(fileName);
  //end

 
   */
  
  
