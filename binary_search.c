#include <stdio.h>

int binary_search(int arr[], int s, int e, int val){
    if(s > e) return -1;
    int mid = (s+e)/2;
    if(arr[mid] == val) return mid;
    else if(arr[mid] > val) return binary_search(arr, s, mid-1, val);
    else if(arr[mid] < val) return binary_search(arr, mid+1, e, val);
}

int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8}; //already sorted array
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = binary_search(arr, 0, size-1, 5);
    if(result > -1) printf("Value found at index %d\n", result);
    else printf("Value not found in elements\n");
    return 0;
}
