#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *getNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node *root, int data){
    if(root == NULL){
        root = getNode(data);
    }else if(data <= root->data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    return root;
}

int search(node *root, int data){
     if(root == NULL) 
         return 0;
     else if(root->data == data) 
         return 1;
     else if(data <= root->data) 
         return search(root->left, data);
     else 
         return search(root->right, data);
}

node *findMin(node *root){
    while(root->left != NULL) 
        root = root->left;
    return root;
}

node *findMax(node *root){
    while(root->right != NULL) 
        root = root->right;
    return root;
}

int max(int a, int b){
    return (a > b ? a : b);
}

int findHeight(node *root){
    if(root == NULL){
        return -1;
    }
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void preorder(node *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

node *delete(node *root, int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = delete(root->left, data);
    else if(data > root->data) root->right = delete(root->right, data);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }else if(root->left == NULL){
            node *temp = root;
            root = root->right;
            free(temp);
        }else if(root->right == NULL){
            node *temp = root;
            root = root->left;
            free(temp);
        }else{
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;

}

node *getSecondLargest(node *root){
    if(root->right == NULL && root->left != NULL){
        return findMax(root->left);
    }
    if(root->right != NULL && root->right->left == NULL && root->right->right == NULL)
        return root;
    return getSecondLargest(root->right);
}

node *getSecondSmallest(node *root){
    if(root->left == NULL && root->right != NULL)
        return findMin(root->right);
    if(root->left != NULL && root->left->right == NULL && root->left->left == NULL)
        return  root;
    return getSecondSmallest(root->left);
}



int main(){
    node *bstroot = NULL;
    bstroot = insert(bstroot, 5);
    bstroot = insert(bstroot, 2);
    bstroot = insert(bstroot, 7);
    bstroot = insert(bstroot, 1);
    bstroot = insert(bstroot, 6);
    bstroot = insert(bstroot, 3);
    bstroot = insert(bstroot, 8);
    printf("%s \n", (search(bstroot, 2)) ? "Found!" : "Not found!");
    printf("Max: %d\n", findMax(bstroot)->data);
    printf("Min: %d\n", findMin(bstroot)->data);
    printf("Height: %d\n", findHeight(bstroot));
    preorder(bstroot);
    printf("\n");
    inorder(bstroot);
    printf("\n");
    postorder(bstroot);
    printf("\n");
    printf("%d\n",getSecondLargest(bstroot)->data);
    printf("%d\n",getSecondSmallest(bstroot)->data);
    
    
}
