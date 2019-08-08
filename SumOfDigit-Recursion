#include <stdio.h>
#include <stdlib.h>

int sumDigitR(int n);
int main(){
    
        int number = 345;
         printf("sum of digit %d is %d\n", number, sumDigitR(number));
    
    
    return 0;
    }

int sumDigitR(int n) {
    int y = 0;
    if (n == 0){
        return y;
    }
    else {
        
        //  3 + 5 + 7        Think of this as our checker
        y = (n%10) + sumDigitR(n/10);



        return y;
    }
}

