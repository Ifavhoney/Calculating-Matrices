#include <stdio.h>
#include <stdlib.h>
typedef struct Tree_Node{
    int data;
   struct Tree_Node *right;
   struct  Tree_Node *left;
}Tree_Node;

Tree_Node* addNodes(int *p, int left, int right);

int main(){
    
    //Create an Array
    int data[10] = {1,2,3,4,5,6,7,8,9,10};
    
    //Turn Into Tree Node (treeNode has access to this pointer function's memory
    Tree_Node *treeNode = addNodes(data, 0, 9);
//    printf("Left Nodes");
//    while (treeNode ->left != NULL) {
//
//        treeNode = treeNode -> left;
//        printf("%d\t", treeNode -> data);
//
//    }
    
    return 0;
}

Tree_Node* addNodes(int *p, int left, int right){
    //Left cannot be greater than right
    if (left > right){
        return NULL;
    }
    else {
        //the formula for defining the root is left + right / 2 -> returns index
        int mid = (left + right)/2;
        
        //create a block of memory
        Tree_Node *temp = (Tree_Node *)malloc(sizeof(*p));
    
        // e.g p[4]
        temp -> data = *(p + mid);
        printf("Node: %d\n", temp -> data);

        //Recursion - calls mid multiple times e.g (4-1)/2 ... (1-1)/2 etc
        temp -> left = addNodes(p, left, mid-1);
        temp -> right = addNodes(p, mid + 1, right);
        
        
        
        return temp;
        //temp -> data =
    }
}
