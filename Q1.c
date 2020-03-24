#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>

//2.2 A program to implement the Horspool’s algorithm. (20%)
//Essentially turns file into an array
#define LENGTH 2045

void dataToArray(FILE *fp, char arr[LENGTH][225]){
      char buff[256];

        if (fp != NULL)
        {
            int length = 0;
            int currLine = 0;
            int i = 0;
            int j=0; int index=0;
            char *word = malloc(245);
            char *temp[1000];
            while (fgets(buff, 256, fp) != NULL)
            {
            
                temp[i] = malloc(strlen(buff) + 5 );
        
                strcpy(temp[i], buff);
                i++;
                length++;
                
            }
            
            
           
                strcpy(word, "coding    informationn         published in this undergraduate calendar outlines the");
            
             for(i=0;i<(strlen(word));i++)
                                    {
                                        
                                        if(word[i]==' '||word[i]=='\n')
                                        {
                                
                                
                                            arr[index][j]='\0';
                                            j=0;
                                            index++;
                                            while (word[i] == ' ') {
                                                i++;
                                            }
                                            i--;
                                            
                                        }
                                        else
                                        {
                                          
                                           // printf("%c", word[i]);
                                            arr[index][j]=word[i];
                                            j++;
                                            
                                        }
                                    }
         
                //reset
            
          

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
   char array[LENGTH][225];
   
   dataToArray(fp, array);
    int i = 0;
    while (i != 9) {
        printf("-%s\n", array[i]);
        i++;
    }
    //printf("\n\n%ld\t", strlen(array));
    
    
    
    
    
    
    
    
    
    
    
    

       //Calculating the total time & if the time is less than 0ms, set to 0
       ftime(&firstEnd);
         elapsedTime =  firstEnd.millitm - firstStart.millitm;
         if(elapsedTime <=0){
             elapsedTime = 0;
         }
     // printf("\nelasedTime for Horspool's technique %dms\n", elapsedTime);
       return 0;
    
}
