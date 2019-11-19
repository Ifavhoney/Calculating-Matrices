/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#ifndef binary_h
#define binary_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *key;
    void *address;
    struct node *left;
    struct node *right;
};

int count(struct node *tree);
void insert(struct node **root, char *key, void *addressOf);
struct node *findTitles(struct node *root, char *value);

struct node *find_nconst(struct node *root, char *value);

char *reverse(char *key);
void printInorder(struct node *node);

#endif /* binary_h */
