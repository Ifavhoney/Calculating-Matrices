/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */

#include <stdio.h>
#include "title.h"
#include "binary.h"
#include "principals.h"
#include "name.h"
#include "common.h"

#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    /* Other */
    int i = 0;

    struct node *treeKeyName = NULL;
    struct node *treeKeyNconst = NULL;

    struct node *treeTitleTconst = NULL;

    struct node *treeTitleTitle = NULL;

    struct node *treePrincipalsTconst = NULL;

    struct node *treePrincipalsNconst = NULL;

    struct arrayStruct *ptr;
    struct arrayStruct *ptr2;

    struct arrayStruct *ptr3;
    struct name_basics *name_basicss;
    struct title_basics *title_basicss;
    struct title_principals *title_principalss;

    char *arr = argv[1];
    ptr = (struct arrayStruct *)malloc(sizeof(struct arrayStruct));
    ptr = get_name(arr);
    ptr2 = (struct arrayStruct *)malloc(sizeof(struct arrayStruct));

    ptr2 = get_title(arr);

    ptr3 = (struct arrayStruct *)malloc(sizeof(struct arrayStruct));

    ptr3 = get_title_principals(arr);

    name_basicss = (struct name_basics *)ptr->address;

    title_basicss = (struct title_basics *)ptr2->address;

    title_principalss = (struct title_principals *)ptr3->address;
    printf("\n Name Basics tree\n");

    for (i = 0; i < ptr->size; i++)
    {
        name_basicss++;

        if (name_basicss->nconst != NULL)
        {

            insert(&treeKeyNconst, name_basicss->nconst, ptr);
            insert(&treeKeyName, reverse(name_basicss->primaryName), ptr);
        }
    }

    printInorder(treeKeyNconst);
    printf("\n");
    printInorder(treeKeyName);
    printf("\n\nTitles tree\n");
  

    for (i = 0; i < ptr2->size - 1; i++)
    {
        title_basicss++;
        if (title_basicss != NULL && title_basicss->tconst != NULL)
        {
            insert(&treeTitleTconst, title_basicss->tconst, ptr2);
            insert(&treeTitleTitle, reverse(title_basicss->primaryTitle), ptr2);
        }
    }
    printInorder(treeTitleTconst);
    printf("\n");
    printInorder(treeTitleTitle);

    printf("\n\nPrincipals tree\n");

    /*title_principalss++;*/
    for (i = 0; i < ptr3->size; i++)
    {
    
        title_principalss++;
        if (title_principalss->nconst != NULL && title_principalss->tconst != NULL )
        {

            insert(&treePrincipalsTconst, title_principalss->tconst, ptr3);
            insert(&treePrincipalsNconst, title_principalss->nconst, ptr3);
        }
    }

    printInorder(treePrincipalsTconst);
    printf("\n");
    printInorder(treePrincipalsNconst);

}
