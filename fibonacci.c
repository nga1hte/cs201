//iterative and recursive functions to calculate fibonacci
#include <stdio.h>

int fibonacci(int);

int rfibonacci(int);

int main(){
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("iterative: %d\n", fibonacci(num));
    printf("recursive: %d\n", rfibonacci(num));
}

int fibonacci(int n){
    int num1 = 0;
    int num2 = 1;
    int next = 0;
    for(int i = 1; i < n; i++){
        next = num1+num2;
        num1 = num2;
        num2 = next;
    }
    return next;
}

int rfibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return rfibonacci(n-1) + rfibonacci(n-2);
}
