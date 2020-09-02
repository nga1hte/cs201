#include <stdio.h>

//function declarations
void insertion_sort(int [], int);
void print_arr(int [], int);

int main(){
    int arr[] = { 9, 8, 5, 6, 4};

    //sizeof whole array divided by size of first element
    //number of elements
    int size = sizeof(arr)/sizeof(arr[0]); 

    print_arr(arr, size);
    insertion_sort(arr, size);
    print_arr(arr, size);
}

//function definitions
void insertion_sort(int arr[], int size){
    int j, val;
    for(int i = 1; i < size; i++){ // n-1
        j = i-1;
        val = arr[i];
        while(arr[j] > val && j >= 0){ // 1 + 2 + 3 +.. n-1
            arr[j+1] = arr[j]; //shift all values by +1 index
            j--;
        }
        arr[j+1] = val; // add +1 since j-- will have decreased the value by 1 index
    }
}

//function to print array
void print_arr(int arr[], int size){
    printf("Values: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
