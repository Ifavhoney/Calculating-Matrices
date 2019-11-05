/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#include "binary.h"
struct node *find_nconst(struct node *root, char *value)
{

    value = reverse(value);
    if (root != NULL)
    {
        int result = strcmp(value, root->key);

        if (result == 0 || root->key)
        {

            return root;
        }
        else
        {

            int result = strcmp(value, root->key);
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
    char *submit = malloc(length);

    int i = 0;
    int j = 0;
    while (i <= length - 1)
    {
        key++;

        i++;
        if (i == length)
        {
            while (j < i)
            {
                key--;
                j++;

                strncat(submit, key, 1);
            }
            break;
        }
    }
    strncat(submit, "\0", 1);

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

    if (*root == NULL)
    {
        *root = node;
        return;
    }
    temp = *root;

    result = strcmp(key, reverse(temp->key));

    if (result > 0)
    {

        insert(&temp->right, key, addressOf);
    }
    else
    {
        insert(&temp->left, key, addressOf);
    }
}

void printInorder(struct node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);

    printf("%s ", node->key);

    printInorder(node->right);
}
