#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
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
    temp->next = list;
    list = temp;
}

void insertAtE(int data){
    node *temp = list;
    if(list == NULL){
        insertAtB(data);
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = get_node(data);
}

//insert after
void insertAfter(node *p, int data){
    if(p == NULL){
        printf("Void Insertion!\n");
        exit(1);
    }
    node *temp = (node *) malloc(sizeof(node));
    temp->data = data;
    temp->next = p->next;
    p->next = temp;
    return;
}

//Another implementation of insert at end using insert after
void insertAtE2(int data){
    node *temp = list;
    if(list == NULL){
        insertAtB(data);
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    insertAfter(temp, data);
}

int delAtB(void){
    if(list == NULL){
        printf("Void Deletion\n");
        exit (1);
    }
    
    int data = list->data;
    node *temp = list;
    list = list->next;
    free(temp);
    return data;
}

int delAtE(void){
    if(list == NULL){
        printf("Void Deletion\n");
        exit (1);
    }
    int data;
    node *temp = list;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    data = temp->next->data;
    temp->next = NULL;
    free(temp->next);
    return data;
}

//delete after
int delAfter(node *p){
    if(p == NULL){
        printf("Void Deletion\n");
        exit(1);
    }
    int data;
    node *temp = p->next;
    p->next = temp->next;
    data = temp->data;
    free(temp);
    return data;
}

//Another implementation of delete at end
int delAtE2(void){
    if(list == NULL){
        printf("Void Deletion\n");
        exit(1);
    }
    node *temp = list;
    while(temp->next->next != NULL)
        temp = temp->next;
    return delAfter(temp);
}

int search(int data){
    node *temp = list;
    int x = 0;
    while(temp != NULL){
        if(temp->data == data) 
            return x;
        x++;
        temp = temp->next;
    }
    return -1;
}

void reverse_list(){
    node *cur = list;
    node *next = NULL;
    node *prev = NULL;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    list = prev;
}

//recursive implementation
void reverse_list2(node *p){
    if(p->next == NULL){
        list = p;
        return;
    }
    reverse_list2(p->next);
    node *temp = p->next;
    temp->next = p;
    p->next = NULL;
}

void print_list(node *list){
    if(list == NULL)
        return;
    printf("%d ", list->data);
    print_list(list->next);
}


int main(){
    insertAtB(1);
    insertAtE(2);
    insertAtB(0);
    insertAtE2(3);
    print_list(list);
    printf("\n");
    int serch = search(3);
    if(serch > -1)
        printf("It is found at %d\n", serch);
    else
        printf("It is not found\n");
    reverse_list2(list);
    print_list(list);
    printf("\n");

}
