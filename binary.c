//how would you approach this?
//How to test on the socs server w/out bitwise
#include "binary.h"

//1) A tree based on the key nconst that references the structures in the name_basics array.
// (Since the nconst values are in ascending order in the input file, you will need to add
//items to the tree in a clever way so that you don’t end up with a really long linked list

//,

struct node *find_nconst(struct node *root, char *value)
{
    if (root != NULL)
    {
        int result = strcmp(value, root->key);

        if (result == 0)
        {
            return root;
        }
        else
        {

            if (result > 0)
            {
                find_nconst(root->right, value);
            }
            else
            {
                find_nconst(root->left, value);
            }
        }
    }
    else
    {
        return NULL;
    }
    return NULL;
}

char *reverse(char *key)
{
    long length = strlen(key);
    char result[length];
    char *submit = malloc(length);

    int i = 0;
    int j = 0;
    while (i <= length - 1)
    {
        printf(" %c \n", *key);
        key++;

        i++;
        if (i == length)
        {
            while (j < i)
            {
                key--;
                j++;
                result[j] = *key;
            }
            break;
        }
    }
    //add terminating character after
    result[j + 1] = '\0';
    strcpy(submit, result);
    return submit;
}

void insert(struct node **root, char *key, void *addressOf)
{
    struct node *temp;
    int result;
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = reverse(key);
    node->address = &addressOf;
    node->left = NULL;
    node->right = NULL;

    //malloc the node
    if (*root == NULL)
    {

        *root = node;
        return;
        //Set root = init;
    }
    //access root - accesses the header
    temp = *root;

    result = strcmp(key, reverse(temp->key));

    if (result > 0)
    {
        //similar to while temp -> right != null
        //   printf("right\t");

        insert(&temp->right, key, addressOf);
    }
    else
    {
        insert(&temp->left, key, addressOf);
    }

    //now find a way to add to tree depending on length

    //inserts
}
void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%s ", node->key);

    /* now recur on right child */
    printInorder(node->right);
}
