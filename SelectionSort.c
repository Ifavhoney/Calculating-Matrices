
#include <stdio.h>
void swapNumber(int *x, int *y);
void selectionSort(int data[], int size);

int main(){
    
    int arr[] = {3, 9, 1, 44, 43};

    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
void selectionSort(int data[], int size){
    int last_index;
    for (int i = 0; i < size; i++) {
        //always comparing forward
        //0
        last_index = i;
        //0+1
        for (int j = i + 1; j < size; j++) {
            //64 > 25 > 12 > 22 > 11
            if (data[last_index] > data[j]){
                //get the j
                last_index = j;
                //keep iterating
            }
        }
        //passing by reference using array
        swapNumber(&data[last_index], &data[i]);
    }
}

void swapNumber(int *x, int *y){
  //  passing by reference
    int temp = *x;
 //   64 = 11
    *x = *y;
 //   11 = 64
    *y = temp;
}


