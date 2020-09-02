#include <stdio.h>

//function declarations
void swap(int*, int*);
void bubble_sort(int [], int);
void print_arr(int [], int);

int main(){
    int arr[] = { 9, 8, 5, 6, 4};

    //sizeof whole array divided by size of first element
    //number of elements
    int size = sizeof(arr)/sizeof(arr[0]); 

    print_arr(arr, size);
    bubble_sort(arr, size);
    print_arr(arr, size);
}


//function definitions
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size){
    for(int i = 1; i < size; i++){ //looping n-1 times
        for(int j = 0; j < size - i; j++){ //looping n-1 + n-2 + n-3 .... 
            if(arr[j] > arr[j+1])
               swap(&arr[j], &arr[j+1]);
        }
    }
}

//function to print array
void print_arr(int arr[], int size){
    printf("Values: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
