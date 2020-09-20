#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

node *getNode();
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
    printStack();
    printf("Top: %d\n", top());
    push(4);
    push(5);
    pop();
    printStack();
    printf("Top: %d\n", top());
}

node *getNode(int x){
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(int x){
    node *newNode = getNode(x);
    newNode->next = head;
    head = newNode;
}

int isEmpty(){
    if(head == NULL) 
        return 1;
    return 0;
}

int top(){
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return -1;
    }
    return head->data;
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return -1;
    }
    int x = head->data;
    node *temp = head;
    head = head->next;
    free(temp);
    return x;
}

void printStack(){
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
