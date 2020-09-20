#include <stdio.h>
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

int main(){
    push(1);
    push(2);
    push(3);
    printStack();
    printf("Top: %d\n", top());
    pop();
    printStack();
    printf("Top: %d\n", top());
    pop();
    push(4);
    push(5);
    pop();
    printStack();

    return 0;
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
