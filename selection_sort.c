#include <stdio.h>

//function declarations
void swap(int*, int*);
void selection_sort(int [], int);
void print_arr(int [], int);

int main(){
    int arr[] = { 9, 8, 5, 6, 4};

    //sizeof whole array divided by size of first element
    //number of elements
    int size = sizeof(arr)/sizeof(arr[0]); 

    print_arr(arr, size);
    selection_sort(arr, size);
    print_arr(arr, size);
}

//function definitions
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int size){
    int min; //variable for storing minimum index
    for(int i = 0; i < size - 1; i++){ // n-1 times
        min = i;                       //set i as minimum
        for(int j = i+1; j < size; j++){ //n-1 + n-2 + n-3
            if(arr[min] > arr[j])
                min = j;
        }
        swap(&arr[min], &arr[i]); //swap i index with minimum
    }
}

//function to print array
void print_arr(int arr[], int size){
    printf("Values: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
