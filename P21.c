#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>


//2.1 A program to implement a brute force algorithm. (10%)
//Essentially turns file into an array
/*
int dataToArray(FILE *fp, char *arr[]){
      char buff[256];
            int i = 0;

        if (fp != NULL)
        {
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

        return i;


}
//From book, as stated in a3 guide
int BruteForceStringMatch(char *line, char *pattern){
    int matches = 0;
    for (int i = 0; i < strlen(line) + 1; i++) {
        int j = 0;
        //always begins at the beginning of the pattern
        //compares the current letter with the the next one (may run once)
        while(j < strlen(pattern) && pattern[j] == line[j + i]){
            j++;
        
        }
        //if at one point the pattern is good, 
        if(j == strlen(pattern)){
            matches++;
            
        }
      
    }
      //returns the number of times it appears on line
    return matches;
    
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
    //Turn data into an array
    dataToArray(fp, array);
  
    int i =0;
     int counter = 0;
    while(i < length){
    //Find matches per line
   int j = BruteForceStringMatch(array[i], "Undergraduate");
   if(j > 0){
     counter += j;
   }
   
   i++;
    }
   printf("matches: %d", counter);
    
    
    ftime(&firstEnd);
      elapsedTime = firstEnd.millitm - firstStart.millitm;
      if(elapsedTime <=0){
          elapsedTime = 0;
      }
     printf("\nelasedTime for bruteforce technique %dms\n", elapsedTime);
    return 0;
 
}

*/