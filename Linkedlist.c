#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

void print(node *root);
void addAfter(node *root, int data, int target);
void addBefore(node *root, int data, int target);
void add(node **root, int data);
void delete(node *root, int data);
int main(){
    
    node *root = NULL;
    
    for (int i = 0; i < 10; i++) {
        add(&root, i);
    }
    print(root);
    addAfter(root, 100, 3);
    printf("\n");
    print(root);
    addBefore(root, 9, 100);
    printf("\n");
    print(root);
    delete(root,100);
    printf("\n");
    print(root);
    return 0;
}


void delete(node *root, int data){
    if(root == NULL){
        return;
    }
    node *temp = root;
    node *prev = root;

    while (temp -> next != NULL && temp -> data != data) {
        prev = temp;
        temp = temp -> next;
        
    }
    if(temp -> data == data){
        //  5|6 >>6|7<<
        prev -> next = temp -> next;
        free(temp);
    }

}
void addBefore(node *root, int data, int target){
    if (root == NULL){
        return;
    }
  node  *temp = root;
    node *prev = root;
    
    while (temp -> next != NULL && temp -> data != target) {
        prev = temp;
        temp = temp -> next;
        // printf("%d", temp -> data);
        //   printf("access");
        
    }
    if(temp -> data == target){
        
        node *ptr = (node *)malloc(sizeof(root));
        ptr -> data = data;
        // 3|4 >7:null<  4:5
        ptr -> next = prev ->next;
        prev -> next = ptr;
        
    }
    
}

void addAfter(node *root, int data, int target){
    if (root == NULL){
        return;
    }
   node *temp = root;
    while (temp -> next != NULL && temp -> data != target) {
        temp = temp -> next;
       // printf("%d", temp -> data);
     //   printf("access");

    }
    
    if(temp -> data == target){
        node *ptr = (node *)malloc(sizeof(root));
        ptr -> data = data;
        // 100|4 3|4
        ptr -> next = temp -> next;
        temp -> next = ptr;
    }
}

void add(node **root, int data){
    //allocate memory block
    node *temp = (node *)malloc(sizeof(*root));
    temp -> data = data;
    temp -> next = NULL;
    
    if(*root == NULL){
        *root = temp;
        return;
    }
    //0|null 1|null
    else{
        //list points to root for temp memory access access
        node *list = *root;
        while (list -> next != NULL) {
            list = list -> next;
        }
        //root -> next points to temp
        list -> next = temp;
        
        //how did root remember? because list -> next is essentially root -> next
        
    }
    
}


void print(node *root){
    if (root == NULL){
        return;
    }
    
    //temp points to root
    node *temp = root;
    
    while (temp != NULL) {
        printf("%d\t", temp -> data);

        temp = temp -> next;
    }
    
    
    
}
