#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} BST;

void addNodeToBST( BST **ptr, int data);
int checkData(BST *ptr, int data);
void preOrder(BST *ptr);
void inOrder(BST *ptr);
void postOrder(BST *ptr);

int main(){
    
    BST *root = NULL;
    int arr[10] = {5,7,8,2,45,3,9,1,4,12};

    for (int i = 0; i < 10; i++) {
        addNodeToBST(&root, arr[i]);
        
    }
    
    int val = checkData(root, 7);
    (val == 0) ? printf("Does not exist"): printf("Value exists");
    
    postOrder(root);
    
    
    return 0;
}

void postOrder(BST *ptr){
    if (ptr == NULL){
        return;
    }
    postOrder(ptr -> left);
    postOrder(ptr -> right);
    printf("%d\t", ptr -> data);
    
}

void inOrder(BST *ptr){
    if (ptr == NULL){
        return;
    }
    inOrder(ptr -> left);
    printf("%d\t", ptr -> data);
    inOrder(ptr -> right);
}



void preOrder(BST *ptr){
    if (ptr == NULL){
        return;
    }
    
    printf("%d\t", ptr -> data);
    preOrder(ptr -> left);
    preOrder(ptr -> right);
}


int checkData(BST *ptr, int data){
    if (ptr == NULL){
        return 0;
    }
    
    if (data == ptr -> data){
        return 1;
    }
    //10 > 12
    else if (data > ptr -> data ){
      return 0 |  checkData(ptr -> right,  data);
        // ptr -> right check again... ptr -> right etc
        return 1;
    }
    else{
        return 0 | checkData(ptr -> left, data);
        return 1;
    }
}


void addNodeToBST(BST **ptr, int data){
    if (*ptr == NULL){
        BST *init = (BST*)malloc(sizeof(**ptr));
        init -> data = data;
        init -> left = NULL;
        init -> right = NULL;
        
        //ptr points to init (has access to memory)
        *ptr = init;
        //printf(" Temp: %d ||\t", init -> data);

        return;
    }
    BST *temp = *ptr;
    
    
    if (data > temp -> data){
        //  printf(" Right: %d", temp -> data);
        
        //essentially (starts from [0]) temp -> right = 5 |temp -> right -> right = null...  becomes right -> right = 7
        addNodeToBST(&temp -> right, data);
        
        //temp -> right  = 5... temp -> right NULL so we add it
    }
    else {
        //temp -> left = 5 ... temp -> left = NULL loop... temp -> left = 5
        addNodeToBST(&temp -> left, data);

    }
   
}
