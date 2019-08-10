#include<stdio.h>


int powerR(int n, int pow);
int main(){
    // Find Power using Recursion
     int number = 2;
     int pow = 3;
     printf("result of %d ^ %d is = %d", number, pow, powerR(number, pow));

return 0;
}

//Write a funnction to find m^n using recursion;
int powerR(int n, int pow){
    int y = 0;
    if(pow == 0){
        y = 1;
        printf("%d ^ %d is = %d\n",n, pow, y );

        return y;
    }
    else if (pow == 1){
        y = n;
        printf("%d ^ %d is = %d\n",n, pow, y );

        return y;
    }
    else {
        //Turn pow into smaller bits -> begins 0 upwards -> calls function -> n multiplies by itself

        y = n * powerR(n,pow - 1);
        printf("%d ^ %d is = %d\n",n, pow, y );
        return y;
    }

}
