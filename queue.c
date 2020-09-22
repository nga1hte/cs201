#include <stdio.h>
#define MAXSIZE 10

typedef struct queue{
    int item[MAXSIZE];
    int front, rear;
}queue;

queue Q = {.front = -1, .rear = -1};

int isEmpty(){
    return (Q.front == -1 && Q.rear == -1);
}
int isFull(){
    return (Q.rear == MAXSIZE - 1);
}

void enqueue(int x){
    if(isFull()){
        printf("Overflow!\n");
        return;
    }else if(isEmpty()){
        Q.rear = 0;
        Q.front = 0;
        Q.item[Q.rear] = x;
    }else{
        Q.item[++Q.rear] = x;
    }
}
int dequeue(){
    int x;
    if(isEmpty()){
        printf("Underflow!\n");
    }else if(Q.front == Q.rear){
        x = Q.item[Q.front];
        Q.front = -1;
        Q.rear = -1;
    }else{
        x = Q.item[Q.front++];
    }
    return x;
}

void printQ(){
    for(int i = Q.front; i <= Q.rear; i++){
        printf("%d ", Q.item[i]);
    }
    printf("\n");
}


int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printQ();
    printf("%d\n",dequeue());
    printQ();
}
