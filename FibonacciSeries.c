#include <stdio.h>
#include <stdlib.h>

void displayFibonacci(int num);

int main(){
    
    
    displayFibonacci(5);
    
    return 0;
    }

void displayFibonacci(int num){
    
    int fib = 0, first = 0, second = 1, i = 0;
    while (i <= num) {
        if(i <= 1){
            fib = i;
            //    printf("%d \t", fib);
        }
        else {
            fib = first + second; // 0 + 1 -> 2 + 1
            first = second;
            second = fib;
        }
        printf("%d \t", fib);
        i++;
    }
}




