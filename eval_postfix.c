#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACKSIZE 100

typedef struct stack{
    int top;
    int data[STACKSIZE];
}stack;

stack S = {.top = -1};

void push(int);
int pop();
int top();
int isEmpty();
void printStack();
int isDigit(char);
double eval(char []);
double operate(char, double, double);

int main(){
    char str[] = "23*54*+9-";
    printf("value: %lf\n", eval(str));
    return 0;
}
double operate(char operator, double op1, double op2){
    switch(operator){
        case '+': 
            return (op1 + op2);
        case '*': 
            return (op1 * op2);
        case '-': 
            return (op1 - op2);
        case '/': 
            return (op1 / op2);
        case '^':
            return (pow(op1, op2));
        default:
            printf("Illegal operation\n");
            exit(1);
    }
}

double eval(char s[]){
    char c;
    double op1, op2, value;
    for(int i = 0; (c = s[i]) != '\0'; i++){
        if(isDigit(c))
            push((double)(c-'0'));
        else{
            op2 = pop();
            op1 = pop();
            value = operate(c, op1, op2);
            push(value);
        }
    }
    return pop();
}
int isDigit(char c){
    return (c >= '0' && c <= '9');
}

void push(int x){
    if(S.top == STACKSIZE) {
        printf("Stack Overflow!\n");
        return;
    }
    S.top += 1;
    S.data[S.top] = x;
}

int pop(){
    if(isEmpty()){
        printf("Stack underflow!\n");
        return -1;
    }
    int x = S.data[S.top];
    S.top -= 1;
    return x;
}

int top(){
    if(isEmpty()){
        printf("Stack underflow!\n");
        return -1;
    }
    return S.data[S.top];
}

int isEmpty(){
    if(S.top == - 1)
        return 1;
    return 0;
}

void printStack(){
    int size = S.top;
    for(int i = 0; i <= size; i++)
        printf("%d ", S.data[i]);
    printf("\n");
}
