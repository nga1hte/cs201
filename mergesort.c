#include <stdio.h>
#include <stdlib.h>

void print_arr(int[], int);
void sort(int[], int);
void merge(int[], int, int[], int, int[]);


int main(){
    int arr[] = {9, 4, 7, 1, 2, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    print_arr(arr, size);
    sort(arr, size);
    print_arr(arr, size);
}

void sort(int arr[], int size){
    if(size < 2) return;
    int mid = size/2;
    int *left = (int *) malloc(mid * sizeof(int));
    int *right = (int *) malloc((size - mid) * sizeof(int));
    for(int i = 0; i < mid; i++)
        left[i] = arr[i];
    for(int i = mid; i < size; i++)
        right[i - mid] = arr[i];
    sort(left, mid);
    sort(right, size - mid);
    merge(left, mid, right, size - mid, arr); 
    free(left);
    free(right);
}

void merge(int *left, int llen, int *right, int rlen, int *arr){
    int i = 0;
    int j = 0; 
    int k = 0;
    while(i < llen && j < rlen){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < llen){
        arr[k] = left[i];
        k++;
        i++;
    }

    while(j < rlen){
        arr[k] = right[j];
        k++;
        j++;
    }
}

void print_arr(int arr[], int size){
    printf("Values: ");
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
