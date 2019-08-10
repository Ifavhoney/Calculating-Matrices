#include <stdio.h>

int power(int n, int pow);

int main(){

  int n, e, i = 0, result = 0;;
         printf("Enter the number you wish to exponent ");
         scanf("%d", &n); //e.g 3
         printf("\nTo the power of? ");
         scanf("%d", &e); // e.g 3
    
         result = n;
         while (i < e - 1) {
         i++; //1; 2
         result = n * result ; //3 * 3 = 9; 3 * 9 = 27 (e == 3);
    
         }
         printf("power of %d = %d", n, result);

}


int power(int n, int pow){
    //2 ^ 4 -> 2*2*2*2
    int counter = 0;
    int result = 0;
    printf("result\n");
    while(counter < pow){

        if(counter == 0){
            result = 1;
            printf("%d ^ %d is = %d\n",n, counter, result );

        }
        else  if (counter == 1){
            result = n;
            printf("%d ^ %d is = %d\n",n, counter, result );

        }
        else {
            //2 * 2 = 4 -> 4 * 2 = 8 -> 8 * 2 -> 16 * 2 -> 32
            result = n * result;
            printf("%d ^ %d is = %d\n",n, counter, result );

        }
        counter++;


    }
    return result * n;

}
