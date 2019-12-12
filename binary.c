/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#include "binary.h"

int count(struct node *tree)
{
    int c = 1;
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        c += count(tree->left);

        c += count(tree->right);
        return c;
    }
}

struct node *find_nconst(struct node *root, char *value)
{
    struct node *array = malloc(sizeof(struct node *));
    struct node *newroot = root;
    while (newroot != NULL)
    {

        if (strcmp(newroot->key, value) > 0)
        {
            /* printf("left %s %s\n", newroot->key, value); */
            newroot = newroot->left;
        }
        else if (strcmp(newroot->key, value) < 0)
        {
            /*    printf("right %s %s\n", newroot->key, value); */

            newroot = newroot->right;
        }
        else
        {

            /*  printf("found"); */

            return newroot;
        }
    }
    free(array);
    return NULL;
}

/*
       
        */
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

    if (*root == NULL)
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->key = key;
        node->address = addressOf; /*&*/
        node->left = NULL;
        node->right = NULL;
        *root = node;
        return;
    }
    temp = *root;

    result = strcmp(key, temp->key);
    if (result > 0)
    {

        insert(&(temp->right), key, addressOf);
    }
    else
    {
        insert(&(temp->left), key, addressOf);
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
