

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/timeb.h>

//Essentially turns file into an array (modified version of my A2 code)
void p2InsertArray(char *filename, char* arr[]){
     char buff[10000];
    char num1[100];
    char num2[100];
    char num3[100];
    char num4[100];
    char num5[100];


    int count = 0;
        int i = 0;
        FILE *fp  = fopen(filename, "r");
    
        while (fgets(buff, sizeof(buff), fp)) {
            sscanf(buff, "%s %s %s %s %s", num1, num2, num3, num4, num5);
            count = 1;
            if(strcmp(buff, " ") != 0){
                
        
            while(count <= 5){
                if(count == 1){
                    arr[i] = calloc(1, strlen(num1) + 2);
                                      strcpy(arr[i], num1);
                    }
                else if(count == 2){
                    arr[i] = calloc(1, strlen(num2) + 2);
                                                    strcpy(arr[i], num2);
                }
                else if(count == 3 && strlen(num3) > 1){
                                  arr[i] = calloc(1, strlen(num3) + 2);
                                                                  strcpy(arr[i], num3);
                              }
                else if(count == 4 && strlen(num4) > 1){

                                               arr[i] = calloc(1, strlen(num4) + 2);
                                                                               strcpy(arr[i], num4);
                                           }
                else if(count == 5 && strlen(num5) > 1){

                        arr[i] = calloc(1, strlen(num5) + 2);
strcpy(arr[i], num5);
                                                         }
                count++;
               
                i++;
            }
                }
            
            
        }
      
    fclose(fp);

}
//Validates anagram by making sure all items are marked X
bool validateAnagram(char *temp){
    bool isValid = true;

    
                  //Validate
 for (int i  = 0; i < strlen(temp); i++) {
                         //  printf("%c,", temp[i]);
                           if(temp[i] != 'X'){
                               isValid = false;
                               break;
                           }
                         }
    return isValid;
}
//Returns >= 0
int totalAnagram(char *temp, char* array[], int length){
    long tempLength = strlen(temp);
    int countAnagram = 0;
    char *clonedTemp = malloc(1000);
    strcpy(clonedTemp, temp);

      
     int i = 0;

          int arrayIndex = 0;
          while(i != tempLength){
              //prevent out of bounds
              if(arrayIndex > length){
                  break;
              }
              else{
                  long tempLengthArray = strlen(array[arrayIndex]);
                  //skip those that are not the same length to improve time efficency

                  if(tempLengthArray != tempLength){
                               i = 0;
                               arrayIndex++;
                              
                               continue;
                           }
              }
           
              //user inputed variable in char
              char myTempChar = temp[i];
              int j = 0;
              while(j != tempLength){
                  //we are comparing each char to char & marking X when found
                  char myArrayChar = array[arrayIndex][j];
                  if(myTempChar == myArrayChar){
                      temp[i] = 'X';
                      array[arrayIndex][j] = 'X';
                      break;
                  }
                  j++;
              }
              i++;
              if(i == tempLength){
                  //If all content is X then it is valid anagram
               bool isValid = validateAnagram(temp);
                  
                  if(isValid == true){
                      countAnagram++;
                  }
                  //Reseting the i to iterate for the next index
                  //Reseting the temp by cpying a cloned version to reset all Xs
                  if(arrayIndex < length+1){
                      i = 0;
                      arrayIndex++;
                      strcpy(temp, clonedTemp);
                      continue;
                  }
              }

       
      }
      //Returns >= 0
       return countAnagram;


}
int main(int argc, const char * argv[]) {
     //Neccessary structs to find time
      struct timeb firstStart, firstEnd;
        int elapsedTime = 0;
      ftime(&firstStart);

    char *fileName = malloc(30);
    strcpy(fileName, "data_4.txt");
    //Length-1 of data_4.txt (adjust according to length of file)
    int length = 29999;
    char *array[length];
    
    char *temp = malloc(1000);

    p2InsertArray(fileName, array);

    printf("Which string are you looking to anagram  \n");
    scanf("%s", temp);
    int _totalAnagram = totalAnagram(temp,array, length);
    printf("\ntotal anagram: %d\n",_totalAnagram );
    
    //Calculating the total time & if the time is less than 0ms, set to 0
 ftime(&firstEnd);
      elapsedTime = firstEnd.millitm - firstStart.millitm;
      if(elapsedTime <=0){
          elapsedTime = 0;
      }
      printf("\nelasedTime for bruteforce technique %dms\n", elapsedTime);  
    return 0;
 
}
