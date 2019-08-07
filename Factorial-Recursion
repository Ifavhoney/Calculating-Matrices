//Factorial Using Recursion

#include <stdio.h>
#include <stdlib.h>

int fact(int n);

int main(){
    int n = 5;
    int result = fact(n);
    printf("Factor of %d is %d\n", n, result );
    
    
    return 0;
    }

int fact(int n){
    int y;
    //once fact(n-1) -> n reduces to smallest bit 0
    if (n == 0){
        y = 1;
        return y;
    }
    else {
        // 1 * 2 * 3 * 4
        y = n * fact(n-1);
        return y;
    }
    
}






