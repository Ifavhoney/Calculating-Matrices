#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>

//2.2 A program to implement the Horspool’s algorithm. (20%)
//Essentially turns file into an array
#define LENGTH 2045


void dataToArray(FILE *fp, char arr[LENGTH][256]){
      char buff[256];

        if (fp != NULL)
        {
            int length = 0;
            int i = 0;
            int t_Index = 0;;
            char temp[220];
            int ch;
            while ((ch=fgetc(fp)) != EOF)// skip whitespace)
            {
                if(ch != ' '){
                    temp[t_Index] = ch;
                    t_Index++;
                }
                else{
                    printf("%s\n", temp);

                    //done
                   // strcpy(arr[i], temp);
                    temp[0] = '\0';
                    t_Index = 0;


                    i++;

                }
        
             
                
            }
                     
          
        }
        else
        {
            printf("unable to open file");
        }

}
int main(int argc, const char * argv[]) {

//Neccessary structs to find time
     struct timeb firstStart, firstEnd;
       int elapsedTime = 0;
     ftime(&firstStart);

   FILE *fp = fopen("data_7.txt", "r");
   //Length-1 of data_4.txt (adjust according to length of file)
   char arr[2045][256];
   
   dataToArray(fp, arr);
    
    
   // printf("%s", array[203]);
    
    
    
    
    
    
    
    
    
    
    
    

       //Calculating the total time & if the time is less than 0ms, set to 0
       ftime(&firstEnd);
         elapsedTime =  firstEnd.millitm - firstStart.millitm;
         if(elapsedTime <=0){
             elapsedTime = 0;
         }
     // printf("\nelasedTime for Horspool's technique %dms\n", elapsedTime);
       return 0;
    
}
