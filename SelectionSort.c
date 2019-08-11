#include <stdio.h>
void swapNumber(int arr[], int x, int y);
void selectionSort(int data[], int size);

int main(){
    
    int arr[5] = {5, 1, 9, 30, 11};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
void selectionSort(int data[], int size){
    
    for (int i = 0; i < size; i++) {
        //use variable to variable to get index;
        if (i == 0 ){
            continue;
        }
        // 64 (i-1) > 25 (i)
        if (data[i-1] > data[i]){
            swapNumber(data, i - 1 , i);
            i = 0;
        }
        
    }
    
    
}

void swapNumber(int arr[], int x, int y){
    //passing by reference
    int temp = *(arr + x);
    //64 = 25
    *( arr+x ) = *(arr+y);
    //25 = 64
    *(arr + y) = temp;
}
