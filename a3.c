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
    int i = 0;

    struct node *treeKeyName = NULL;
    struct node *treeKeyNconst = NULL;

    struct node *treeTitleTconst = NULL;

    struct node *treeTitleTitle = NULL;

    struct node *treePrincipalsTconst = NULL;

    struct node *treePrincipalsNconst = NULL;

    struct node *findNConst = NULL;
    struct node *findN2Const = NULL;

    struct node *findTConst = NULL;
    struct node *findTitle = NULL;

    struct arrayStruct *ptr;
    struct arrayStruct *ptr2;

    struct arrayStruct *ptr3;
    struct name_basics *name_basicss;
    struct title_basics *title_basicss;
    struct title_principals *title_principalss;

    struct name_basics *name = NULL;
    struct title_principals *tPNode = NULL;
    struct title_basics *tBNode = NULL;

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

    for (i = 0; i < ptr->size; i++)
    {
        name_basicss++;

        if (name_basicss->nconst != NULL)
        {

            insert(&treeKeyNconst, name_basicss->nconst, name_basicss);
            insert(&treeKeyName, name_basicss->primaryName, name_basicss);
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
            insert(&treeTitleTconst, title_basicss->tconst, title_basicss);
            insert(&treeTitleTitle, title_basicss->primaryTitle, title_basicss);
        }
    }
    printInorder(treeTitleTconst);
    printf("\n");
    printInorder(treeTitleTitle);

    printf("\n\nPrincipals tree\n");

    for (i = 0; i < ptr3->size; i++)
    {

        title_principalss++;
        if (title_principalss->nconst != NULL && title_principalss->tconst != NULL)
        {

            insert(&treePrincipalsTconst, title_principalss->tconst, title_principalss);
            insert(&treePrincipalsNconst, title_principalss->nconst, title_principalss);
        }
    }

    printInorder(treePrincipalsTconst);
    /*Boundary issues */

    findNConst = find_nconst(treeKeyName, "Keanu Reeves");

    printf("\n");
    name = (struct name_basics *)(findNConst->address);

    if (findNConst == NULL)
    {
        printf("\nNCONST NOT FOUNDL\n");
    }
    if (findNConst != NULL)
    {
        name = (struct name_basics *)(findNConst->address);

        findTConst = find_nconst(treePrincipalsNconst, name->nconst);
        /* printf("\n %s\n", findTConst->key); */
        if (findTConst != NULL)
        {
            tPNode = (struct title_principals *)(findTConst->address);
            /*   printf("\nKey: %s\n", tPNode->tconst); printf("tpNode: %s\n", tPNode->nconst);
            printf("\nKey: %s\n", tPNode->tconst);*/

            findTitle = find_nconst(treeTitleTconst, tPNode->tconst);

            if (findTitle != NULL)
            {
                tBNode = (struct title_basics *)(findTitle->address);

                printf("Actor: %s\n", tBNode->primaryTitle);
            }
            else
            {
                printf("\nThe corresponding ID is a short or Does not exist\n");
            }
        }
    }
    else
    {
        printf("\nError: Not found!\n");
    }
    //  findN2Const = find_nconst(treeKeyName, "Taika Waititi");

    return 0;
}
