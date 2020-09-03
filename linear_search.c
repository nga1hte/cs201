#include <stdio.h>

int search(int arr[], int size, int val){
    for(int i = 0; i < size; i++){
        if(arr[i] == val) return i;
    }
    return -1;
}

int main(){
    int arr[] = {10, 11, 14, 13, 12, 9};
    int size =  sizeof(arr)/sizeof(arr[0]);
    int result = search(arr, size, 133);
    if(result > -1) printf("Value found at index %d\n", result);
    else printf("Value not found in elements\n");
}
