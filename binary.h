//
//  binary.h
//  assgn3
//
//  Created by Jason Eddy on 2019-10-31.
//  Copyright © 2019 Jason Eddy. All rights reserved.
//

#ifndef binary_h
#define binary_h
#include "title.h"
#include <stdio.h>

//xI will create a standard structure for all my binary trees.  That structure will have a char *key pointer, and void *data pointer, and two child pointers

struct node {
    //e.g Primaryname
    char *key;
    //address
    void *address;
    //traversing left or right
    struct node *left;
    struct node *right;
};
void build_Tindex(struct title_basics tree);
void insert(struct node **root, char *key, void *addressOf);
 char *reverse(char *key);
void printInorder(struct node* node);

#endif /* binary_h */
