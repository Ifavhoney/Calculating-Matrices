
#include <stdio.h>
void BubbleSort(int data[], int size);

int main(){
    
    int arr[] = {3, 9, 1, 44, 43};

    int size = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, size);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

//Swaping numbers inside j loop/realtime whereas selection sort - after j loop
void BubbleSort(int data[], int size){
   // int last_index;
    for (int i = 0; i < size-1; i++) {
     
        for (int j = 0; j < size-1-i; j++) {
            //64 > 25 > 12 > 22 > 11
            if (data[j] > data[j + 1] ){
                
                //64
                int temp = data[j];
                //64 = 25
                data[j] = data[j + 1];
                //25 = 64
                data[j + 1] = temp;
                
            }
        }
    }
}
