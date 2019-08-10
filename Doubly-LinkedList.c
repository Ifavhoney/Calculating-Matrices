#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;
void add(node **root, int data);
void print(node *root);
void printRev(node *root);
void delete(node *root, int data);
void addAfter(node *root, int data, int target);
void addBefore(node *roo, int data, int target);
int main(){
    node *root = NULL;
    for (int i = 0; i < 10; i++) {
        add(&root, i);
    }
    
    print(root);
    printRev(root);
    
    addAfter(root, 55, 8);
    print(root);
    printRev(root);
    
    addBefore(root, 44, 7);
    print(root);
    printRev(root);
    
    delete(root, 3);
    print(root);
    printRev(root);

    return 0;
}

void delete(node *root, int data){
    node *temp = root;
    node *prev = root;
    
    while (temp -> next != NULL && temp -> data != data) {
        //One Node Before Target - Therefore Similar to addAfter
        prev = temp;
        temp = temp -> next;
    }
    if (temp -> data == data){
        printf("\nDeleting Node: %d\n\n", data);

        //Get its next
      //
        //Set the deleting node to point to the previous node
      
        
        prev -> next = temp -> next;
        //Let the next node's previous point the previous node (whatever it is) (e.g 5 points to 4) -printing in reverse
        temp -> next -> prev = prev;
        
        
        //temp -> prev -> next = temp -> prev ->;

        
        
        
        
        free(temp);
        
    }
    
    
}
void addBefore(node *root, int data, int target){
    node *temp = root;
    node *prev = root;
    while (temp -> next != NULL && temp -> data != target) {
        //One Node Before Target - Therefore Similar to addAfter
        prev = temp;
        temp = temp -> next;
    }
    if (temp -> data == target){
        printf("\nAdding Node: %d Before %d\n\n", data, temp -> data);
        //Create Block Of Memory
        node *ptr = (node *)malloc(sizeof(*root));
        ptr -> data = data;
        //Get its next
        ptr -> next = prev -> next;
        //Point new node's previous to the old node
        ptr -> prev = prev;
        //Old node points to next node
        prev -> next = ptr;
        
        //Letting know the next node about the our new node
        ptr -> next -> prev = ptr;
        

        
        

    }
}


void addAfter(node *root, int data, int target){
    node *temp = root;
    while (temp -> next != NULL && temp -> data != target) {
        temp = temp -> next;
    }
    
    if (temp -> data == target){
        printf("\nAdding Node: %d after %d\n\n", data, temp -> data);
        //Create Block Of Memory
        node *ptr = (node *)malloc(sizeof(*root));
        ptr -> data = data;
        //Get its next
        ptr -> next = temp -> next;
        //Point the old node to the new node
        temp -> next = ptr;
        //Point the new node's previous to the old node
        ptr -> prev = temp;
     
        
        //Letting know the next node about the our new node
        ptr -> next -> prev = ptr;
        
    }
    else {
        printf("\nUnable to Traverse\n\n");
    }
}
void add(node **root, int data){
    //CREATE A BLOCK OF MEMORY FOR NODE
    node *temp = (node *)malloc(sizeof(**root));
    
    temp -> data = data;
    temp -> next = NULL;
    temp -> prev = NULL;
    
    //Our pointer points to *root - however is null @ first
    if (*root == NULL ){
        //Our Root points to temp - Root points to a block of memory
        *root = temp;
        //Make sure to return & get the result
        return;
    }
    else {
    //list (another temp pointer) is needed to traverse root due to reference (accesses root's memory temporarily)
    node *list = *root;
    // null|0|null  null|1|null
    while (list -> next != NULL) {
        list = list -> next;
    }
    //Point temp's predeccessor(prev) to the number's successor(next)
    temp -> prev = list;
    //Point 0's successor to  temp's predeccessor
    list -> next = temp;
    }
}


void printRev(node *root){
    
    node *temp = root;
    while (temp -> next!= NULL) {
        temp = temp -> next;
    }
    printf("Reverse: ");
    printf("%d\t", temp -> data);
    while (temp -> prev != NULL) {
        temp = temp -> prev;
        printf("%d\t", temp -> data);
    }
    printf("\n");

}
void print(node *root){
    node *temp = root;
    printf("Order: \t");
    printf("%d\t", temp -> data);
    while (temp -> next != NULL) {
        temp = temp -> next;
        printf("%d\t", temp -> data);

    }
    printf("\n");
    
}




