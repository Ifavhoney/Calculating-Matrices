#include <stdio.h>
#include "title.h"
#include "binary.h"
#include "principals.h"
#include "name.h"
#include "common.h"

#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        fprintf(stderr, "Usage:  %s directory\n", argv[0]);
        return -1;
    }
    //now Im dynamically allocating string memory for the structs
    /* Other */
    int i = 0;

    /*Tree Structs*/
    struct node *treeKeyName = NULL;
    struct node *treeKeyNconst = NULL;

    struct node *treeTitleTconst = NULL;
    struct node *treeTitleTitle = NULL;
    struct node *treePrincipalsTconst = NULL;
    struct node *treePrincipalsNconst = NULL;

    /*File Structs*/

    struct arrayStruct *ptr = (struct arrayStruct *)malloc(sizeof(struct arrayStruct));
    ptr = get_name(argv[1]);

    struct arrayStruct *ptr2 = (struct arrayStruct *)malloc(sizeof(struct arrayStruct));
    ptr2 = get_title("title.basicss.tsv");

    struct arrayStruct *ptr3 = (struct arrayStruct *)malloc(sizeof(struct arrayStruct));
    ptr3 = get_title_principals("title.principalss.tsv");

    //struct name_basics *name_basics = (struct name_basics *)ptr->address;
    struct name_basics *name_basicss = (struct name_basics *)ptr->address;
    struct title_basics *title_basicss = (struct title_basics *)ptr2->address;
    struct title_principals *title_principalss = (struct title_principalss *)ptr3->address;

    printf("%d", ptr->size);
    name_basicss++;
    for (i = 0; i < ptr->size; i++)
    {
        name_basicss++;

        if (name_basicss->nconst != NULL)
        {
            //printf("%s", name_basicss ->nconst);
            // printf("%s", name_basicss ->primaryName);

            insert(&treeKeyNconst, name_basicss->nconst, ptr);
            insert(&treeKeyName, name_basicss->primaryName, ptr);
        }
    }

    free(ptr);

    printInorder(treeKeyNconst);

    /*Title 
    title_basicss++;

    for (i = 0; i < ptr2->size; i++)
    {
        title_basicss++;
        if (title_basicss->tconst != NULL)
        {

            insert(&treeTitleTconst, title_basicss->tconst, ptr);
            insert(&treeTitleTitle, title_basicss->primaryTitle, ptr);
        }
    }
    */

    printInorder(treeTitleTconst);

    title_principalss++;
    for (i = 0; i < ptr3->size; i++)
    {
        title_principalss++;
        if (title_principalss->nconst != NULL)
        {

            insert(&treePrincipalsTconst, title_principalss->tconst, ptr);
            insert(&treePrincipalsNconst, title_principalss->nconst, ptr);
        }
    }
    printInorder(treePrincipalsTconst);

    // printf("%s", result ->key );
    // struct title_basics *ptr2 = get_title(argv[2]);

    /*

    
           for (i = 0; i < 10; i++) {
               if(ptr[i].nconst != NULL){
                   insert(&treeKeyName, ptr[i].primaryName, ptr);

               }
           }
     */

    //

    /*Build index title
     ptr2 = get_title(argv[2]);
           i = 0;
           printf("\nTitle\n");
           for ( i = 0; i < 10; i++) {
                  if(ptr2[i].tconst != NULL){
                  insert(&treeTitleTconst, ptr2[i].tconst , ptr2);
                  insert(&treeTitleTitle, ptr2[i].primaryTitle , ptr2);

                  }
              }
 
    ptr3 = get_title_principals(argv[3]);
    free(ptr);
    free(ptr2);
 free(ptr3);
        
    
    
    
    printInorder(treeKeyNconst);



    */

    //printf("%s ",  tree -> key);
    //build_tindex(ptr);
    /*
      printf( "%s\n", (title_basics->tindex)->key );
      printf( "%p\n", (void *)(title_basics->tindex)->value );
      printf( "%s\n", ((struct title_basics *)((title_basics->tindex)->value))->primaryTitle );
      printf( "%s\n", ((struct title_basics *)((title_basics->tindex)->value))->tconst );
     
     */
}

/*
 #include <stdio.h>
 #include "title.h"
 #include "binary.h"
 #include "principals.h"
 #include "name.h"

 #include <stdlib.h>
 #include <string.h>

 int main(int argc, char **argv)
 {
     
    if (argc < 2)
         {
             fprintf(stderr, "Usage:  %s directory\n", argv[1]);
             return -1;
         }
            printf("\n\n");

         struct name_basics *ptr = get_name(argv[0]);
         
         struct title_basics *ptr2;

         struct node *treeKeyName = NULL;
         struct node *treeKeyNconst = NULL;
         struct node *treeTitleTconst = NULL;
         struct node *treeTitleTitle = NULL;
      
          printf("\n\n");

         
         //ask christian if he is comparing with strcmp
         int i = 0;
         for (i = 0; i < 10; i++) {
             printf("%d - %s - %s\n", i, ptr[i].nconst, ptr[i].primaryName);
             if(ptr[i].nconst != NULL){
                 insert(&treeKeyNconst, ptr[i].nconst, ptr);
                 insert(&treeKeyName, ptr[i].primaryName, ptr);

             }
         }
         free(ptr);
     ptr2 = get_title(argv[1]);

         i = 0;
         printf("\nTitle\n");
         for ( i = 0; i < 10; i++) {
                printf("%d - %s - %s\n", i, ptr2[i].tconst, ptr2[i].primaryTitle);
                if(ptr2[i].tconst != NULL){
                insert(&treeTitleTconst, ptr2[i].tconst , ptr2);
                insert(&treeTitleTitle, ptr2[i].primaryTitle , ptr2);

                }
            }
            i = 0;
         free(ptr2);
           
         
  //       printInorder(treeKeyName);
  //       printInorder(treeKeyNconst);

 
     
         
         



     

     
     

 }

 
 

     
  */
