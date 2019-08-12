
#include <stdio.h>
void swapNum(int *p, int current, int prev);

int main(){
    
         printf("Enter 10 numbers: \n ");
         int array[10];
         int size = sizeof(array) / sizeof(array[0]);
    
         for (int i = 0; i <= size-1; i++) {
         printf("Number [%d]: ", i+1 );
         scanf("%d", &array[i]);
    
         }
    
    
         printf("\nNumber in order: \n");
         for (int i = 0; i <= size-1; i++) {
         if(i == 0){
             //we require another number to compare
         continue;
         }

         //5 > 1
         if (array[i-1] > array[i]){
         //pass by reference - get array value, get current num loop, and previous
         swapNum(array, i, i-1);
    
         i = 0;
         }
             
         }
         
    
         for (int i = 0; i <= size-1; i++) {
         printf("%d\t", *(array+i));
         }
}

void swapNum(int *p, int current, int prev){
    int temp = p[prev];
    *(p + prev) = *(p + current);
    *(p + current) = temp;
    
}
