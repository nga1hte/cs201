#include <stdio.h>

void print_arr(int[], int);
int partition(int[], int, int);
void swap(int*, int*);
void quicksort(int *, int, int);

int main(){
    int arr[] = { 9 , 8, 7, 2, 5, 4, 3, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, size);
    quicksort(arr, 0, size - 1);
    print_arr(arr, size);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int arr[], int size){
    printf("Values: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int pIndex = start;
    for(int i = start; i < end; i++){
        if(arr[i] <= pivot)
            swap(&arr[i], &arr[pIndex++]);
    }
    swap(&arr[pIndex], &arr[end]);
    return pIndex;
}

void quicksort(int *arr, int start, int end){
    if(start < end){
        int partitionIndex = partition(arr, start, end);
        quicksort(arr, start, partitionIndex - 1);
        quicksort(arr, partitionIndex+1, end);

    }
}


