//
//  P22.c
//  a3490
//
//  Created by Jason Eddy on 2020-03-08.
//  Copyright © 2020 Jason Eddy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>

//2.2 A program to implement the Horspool’s algorithm. (20%)
//Essentially turns file into an array

typedef struct Map {
     char key;
     int value;
} Map;

typedef struct Results {
     int shifts;
     int matches;
} Results;

void dataToArray(FILE *fp, char *arr[]){
      char buff[256];

        if (fp != NULL)
        {
            int i = 0;
            while (fgets(buff, 256, fp) != NULL)
            {
                
                arr[i] = malloc(strlen(buff) + 5 );
                strcpy(arr[i], buff);
                i++;
            }

            
        }
        else
        {
            printf("unable to open file");
        }

}
//Swap function between one indices & the other
void swap(long *i, long *i2)
{
    long temp = *i;
    *i = *i2;
    *i2 = temp;
}

Map* shiftTable(char *word){
    //Initializing our key variables, size, shift, array
    int size = (int)strlen(word)-1;
    int shift[strlen(word)];
    char arr[strlen(word)];
    //Cloning and setting to 0 to ensure that there are no duplicates
    for (int i  = 0; i < strlen(word); i++) {
        arr[i] = word[i];
        shift[i] = 0;
        //Duplicates are set to -1
        for (int j = i + 1; j < strlen(word); j++) {
            if(word[j] == arr[i] && arr[i] != word[strlen(word)-1]){
                shift[i] = -1;
            }
        }
    }
       
    
    
    int j = 0;
    
    for (int i = size; i > -1; i--) {
      //Counting our shifts
        j++;
        //and accepting only 0s
        if(shift[i] == 0){
            shift[i] = j-1;
        }
        int cloneK= i + 1;
    //For duplicates that is the first index
    if(arr[0] == arr[i] && shift[0] == -1){
                                                        shift[0] = shift[i];
                                                                    }
       for (int k = i+1; k < size; k++) {
        //-1s are duplicates
           if( shift[k] == -1){
               //Get the ID/Index of the value to be shifted
               int dupIndex = k;
               //skip the curIndex
               for (int l = k + 1 ; l < size; l++) {
                   //If they match, and the shift is > 0, set the old shift number to the duplicate
              
              
                   if(arr[k] == arr[l] && shift[l] > 0 ){
                       printf("l: %d, K: %d, j-1: %d, %c, cloneK:%d \n ", l,k,shift[k], arr[k], cloneK);
                       shift[dupIndex] = shift[l];
                       //setting index 0 to shift since the loop ignores duplicate -1, with index = 0  && more than 2 duplicates
                       if(arr[0] == arr[l] && shift[0] == -1){
                           printf("here");
                           shift[0] = shift[l];
                                       }
                       break;

                }
               }
                     
                       printf("done\n");
               break;

                   }
                   

        
        
    }

    
    }
    //At this point, the shifting is correct;
    Map *map;
    map   = malloc(4496);

    shift[size] = (int)strlen(word);
    int *s = shift;
    //Send it as a struct to ease shifting
    for (int i = (int)size; i >= 0; i--) {
        
        map[i].key = word[i];
        map[i].value = s[i];

    }


    return map;
}

int Table(char a, Map *map ){
    int length =0;
    
    while (map[length].key > 64 && map[length].key < 122) {
        length++;
    }
    for (int i = 0; i <= length-1; i++) {
        if(map[i].key == a){
            return map[i].value;
        }
    }

    return length;
}
//Credits to the book
Results HorspoolMatching(char *test, char *prompt){
     int size = (int)strlen(prompt)-1;

       Map *map = shiftTable(prompt);
    Results result;
        //starts at the initial length
       int i = size; //m-1
    result.matches = 0;
    //-1 shifts means not found
    result.shifts = -1;
       int i2 = (int)strlen(test)-1; //n-1
       do {
        
           int k = 0;
           //verifies when matched
           while (k <= size && (prompt[size-k] ) == (test[i-k]) ) {
               k = k+1;

           }
           //our size is one less than the length & so if equal size, our match is found
           if(k == size+1){
               printf("found!");
                result.shifts += i - size+2;
               //goes to the next index (only way to return multiple data from one buffer)
               result.matches++;
               i++;
              // result += i - size+2;

           }
           else{
            
               //uses our table to shfit accordingly
               
               i = i + Table(test[i], map);
           }
           if(k >= size){
               
           }
       } while (i <= i2);
       return result;
    
       
}

int main(int argc, const char * argv[]) {
     //Neccessary structs to find time
      struct timeb firstStart, firstEnd;
        int elapsedTime = 0;
      ftime(&firstStart);

    FILE *fp = fopen("data_5.txt", "r");
    //Length-1 of data_4.txt (adjust according to length of file)
    int length = 44049;
    char *array[length];
    
    dataToArray(fp, array);
    //Test
   // char *test = calloc(1, 100);
   // strcpy(test,"JIM SAW ME IN A BARBERSHOP");

    //Prompt
    char *prompt = calloc(1, 100);
    strcpy(prompt, "University");

    int i =0;
      int matches = 0;
    int shifts = 0;

    //Finds total matches in the given array
     while(i < length){
     //Find matches per line
         Results j = HorspoolMatching(array[i], prompt);
     
    if(j.shifts > 0 && j.shifts != -1){
        matches+= j.matches;
      shifts += j.shifts;
        
    }
    
    i++;
     }
    printf("matches: %d", matches);
    printf("shifts: %d", shifts);

    
    //Calculating the total time & if the time is less than 0ms, set to 0

    ftime(&firstEnd);
      elapsedTime = firstEnd.millitm - firstStart.millitm;
      if(elapsedTime <=0){
          elapsedTime = 0;
      }
   printf("\nelasedTime for bruteforce technique %dms\n", elapsedTime);
    return 0;
 
}
