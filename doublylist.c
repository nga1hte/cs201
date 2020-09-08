#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *list = NULL;

node *get_node(int data){
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtB(int data){
    node *temp = get_node(data);
    if(list == NULL){
       list = temp;
       return;
    }
    list->prev = temp;
    temp->next = list;
    list = temp;
}

void insertAtE(int data){
    node *head = list;
    node *temp = get_node(data);
    if(list == NULL){
        list = temp;
        return;
    }
    while(head->next != NULL)
        head = head->next;
    head->next = temp;
    temp->prev = head;
}

void insertAfter(node *p, int data){
    if(p == NULL){
        printf("Void Insertion!\n");
        exit(1);
    }
    node *temp = get_node(data);
    temp->data = data;
    temp->next = p->next;
    p->next->prev = temp;
    temp->prev = p;
    p->next = temp;
}

int delAtB(){
    if(list == NULL){
        printf("Void Deletion\n");
        exit (1);
    }
    int data = list->data;
    node *temp = list;
    list = list->next;
    list->prev = NULL;
    free(temp);
    return data;
}

int delAtE(){
    if(list == NULL){
        printf("Void Deletion\n");
        exit (1);
    }
    int data;
    node *temp = list;
    while(temp->next != NULL)
        temp = temp->next;

    data = temp->data;
    temp->prev->next = NULL;
    free(temp);
    return data;
}

int delAfter(node *p){
    if(list == NULL){
        printf("Void Deletion\n");
        exit (1);
    }else if(p->next->next == NULL){
        return delAtE(p->next);
    }else{
        int data;
        node *temp = p->next;
        data = temp->data;
        p->next = temp->next;
        p->next->prev = p;
        free(temp);
        return data;
    }
}


void print_list(node *p){
    if(p == NULL)
        return;
    printf("%d ", p->data);
    print_list(p->next);
}

void printr(){
    node *temp = list;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}



int main(){
    insertAtB(1);
    insertAtE(2);
    insertAtB(0);
    insertAtE(3);
    insertAfter(list->next, 4);
    print_list(list);
    printf("\n");
    printr();
    printf("%d \n", delAtB());
    print_list(list);
    printf("\n");
    printr();
    printf("%d \n", delAtE());
    print_list(list);
    printf("\n");
    printr();
    printf("%d \n", delAfter(list->next));
    print_list(list);
    printf("\n");
    printr();

}
