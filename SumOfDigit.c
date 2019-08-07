#include <stdio.h>
#include <stdlib.h>

int sumDigit(int n);
int main(){
    
        int number = 345;
         printf("sum of digit %d is %d", number, sumDigit(number));
    
    
    return 0;
    }

int sumDigit(int n) {
    int y = 0;
    int originalN = 0;
    if (n == -1){
        return y;
    }
    else {
        
        //exit if our sum == 0;
        originalN = n;
        printf("%d\n", originalN);
        
        do {
            //This gets the Remainder - [Dividend-{(Dividend/Divisor)*Divisor}]
            n = originalN % 10;
            //This checks if we have anymore numbers left
            originalN = originalN / 10;
            
            y += n;
            
            //Remove if you'd like
            printf("%d and n is %d \n", originalN, n);
            
        } while (originalN != 0);
        
        
        return y;
    }
}
