//Code for both recursive and iterative solution
//to find factorial

#include <stdio.h>

int factorial(int);

int rfactorial(int);


int main(){
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    //using recursive method
    printf("The factorial of %d is %d\n", num, rfactorial(num));
}

int factorial(int n){
    int fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int rfactorial(int n){
    if(n == 1 || n == 0) return 1;
    return n * rfactorial(n-1);
}

