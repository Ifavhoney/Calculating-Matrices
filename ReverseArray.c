#include <stdio.h>
int main(){
    
         //Write an array in reverse order
    
         printf("Begin array\n");
         int num[] = {1,2,3,4,5};
         //get size
         int size = sizeof(num) / sizeof(num[0]);
         int i = size;
    
         while(i != -1){
         i--;
         printf("%d\t", num[i]);
         }
    return 0;
    
}
