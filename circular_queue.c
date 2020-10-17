#include <stdio.h>
#define MAXSIZE 5

typedef struct queue{
    int item[MAXSIZE];
    int front, rear;
}queue;

queue Q = {.front = -1, .rear = -1};

int isEmpty(){
    return (Q.front == -1 && Q.rear == -1);
}
int isFull(){
    return ((Q.front == 0 && Q.rear == MAXSIZE - 1) || (Q.rear == (Q.front-1)%(MAXSIZE-1)));
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
        Q.rear = (Q.rear+1)%MAXSIZE;
        Q.item[Q.rear] = x;
    }
}

//delete
int dequeue(){
    int x;
    if(isEmpty()){
        printf("Underflow!\n");
    }else if(Q.front == Q.rear){
        x = Q.item[Q.front];
        Q.front = -1;
        Q.rear = -1;
    }else{
        x = Q.item[Q.front];
        Q.front = (Q.front+1) % MAXSIZE;
    }
    return x;
}

void display(){
    if(isEmpty()) printf("Queue is EMPTY!\n");
    else{
        printf("Current Queue: ");
        if(Q.rear >= Q.front){
            for(int i = Q.front; i <= Q.rear; i++){
                printf("%d ", Q.item[i]);
            }
        }
        else{
            for(int i = Q.front; i < MAXSIZE; i++)
                printf("%d ", Q.item[i]);
            for(int i = 0; i <= Q.rear; i++)
                printf("%d ", Q.item[i]);
            
        }
        printf("\n");
        if(isFull()) printf("Queue is full\n");
    }
}

void createQ(){
    for(int i = 0; i < 5;)
        enqueue(++i);
}


int main(){
    createQ();
    display();
    printf("Dequeueing %d from the Queue\n", dequeue());
    display();
    printf("Dequeueing %d from the Queue\n", dequeue());
    display();
    printf("Dequeueing %d from the Queue\n", dequeue());
    display();
    printf("Dequeueing %d from the Queue\n", dequeue());
    display();
    enqueue(1);
    display();
    enqueue(2);
    display();
    printf("Dequeueing %d from the Queue\n", dequeue());
    display();
    printf("Dequeueing %d from the Queue\n", dequeue());
    display();
    printf("Dequeueing %d from the Queue\n", dequeue());
    display();
}
