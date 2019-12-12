#include "text.h"

int strcmpvoid(const void *a, const void *b)
{
  char *ptr_a, *ptr_b;
  ptr_a = (char *)a;
  ptr_b = (char *)b;

  return strcmp(ptr_a, ptr_b);
}

int main(int argc, const char *argv[])
{
  FILE *fp;
  struct node_struct *head, *chapter1, *chapter2, *copy_of;
  struct node_struct *sptr, *sptr1;

  fp = fopen("1342-0.txt", "r");
  head = txt2words(fp);

  fclose(fp);

  sptr = search(head, "Pride", strcmpvoid);
  sptr1 = search(head, "PRIDE", strcmpvoid);

  chapter2 = sptr1->data;
  chapter1 = sptr->data;

  printf("sptr1 %s", chapter2->data);

  printf("\n\n");

  copy_of = copy(chapter1, chapter2);

  if (copy_of != NULL)
  {
    while (copy_of->next != NULL)
    {
      copy_of = copy_of->next;
      printf("%s", copy_of->data);
    }
  }

  free(sptr);
  free(sptr1);
}

/*
//Search
 FILE *fp;
  struct node_struct *head, *chapter1, *chapter2, *copy_of;
  struct node_struct *sptr, *sptr1;

  fp = fopen("1342-0.txt", "r");
  head = txt2words(fp);

  fclose(fp);

  sptr = search(head, "Pride", strcmpvoid);
  sptr1 = search(head, "PRIDE", strcmpvoid);

    chapter1 = sptr->data;
  chapter2 = sptr1->data;
    printf("sptr1 %s", chapter2 ->data);

    printf("\n\n");
  copy_of = copy(chapter1, chapter2);
  while (copy_of->next != NULL)
  {
    copy_of = copy_of->next;
    printf("%s", copy_of->data);
  }
  free(sptr);
  free(sptr1);


 //My main setup
 //do not forget to use your own .txt file
 #include "text.h"

 int strcmpvoid(const void *a, const void *b){
     char *ptr_a, *ptr_b;
     ptr_a = (char *)a;
     ptr_b = (char *)b;
     
     return strcmp(ptr_a, ptr_b);

 }

 int main(int argc, const char * argv[]) {
  
         return 0;
 }
 
 */

/*
 //Remove Repeats
 
 FILE *fp;
   
   struct node_struct *head;
     
      fp = fopen( "1342-0.txt", "r" );
      head = txt2words( fp );

      fclose( fp );
     
   remove_repeats(head, strcmpvoid);
   
   while (head -> next != NULL) {
        head = head -> next;
        printf("%s ", head -> data);
    }
 free(head);
 
 */

/*
 //Free_List

    FILE *fp;
    struct node_struct *head;
   
       
        fp = fopen( "1342-0.txt", "r" );
        head = txt2words( fp );

       free_list(head -> next -> next, 1);
       
       
       while (head -> next != NULL) {
           head = head -> next;
           printf("%s ", head -> data);
       }
        
    free(head);
 */

/*
// Copy Test Case
 
      FILE *fp;
   struct node_struct *head, *chapter1, *chapter2, *copy_of;
      struct node_struct *sptr, *sptr1;
  
   fp = fopen( "1342-0.txt", "r" );
   head = txt2words( fp );

   fclose( fp );
  
  sptr = search( head, "of", strcmpvoid );
  sptr1 = search( head, "Jane", strcmpvoid );
  
  chapter1 = sptr -> data;
  chapter2 = sptr1 -> data;

  copy_of = copy(chapter1, chapter2);
  while (copy_of -> next != NULL) {
      copy_of = copy_of -> next;
      printf("%s",copy_of -> data);
  }
  free(sptr);
  free(sptr1);
 */

/*
 //Seach test case
 #include "text.h"

 int strcmpvoid(const void *a, const void *b)
 {
   char *ptr_a, *ptr_b;
   ptr_a = (char *)a;
   ptr_b = (char *)b;

   return strcmp(ptr_a, ptr_b);
 }

 int main(int argc, const char *argv[])
 {
       FILE *fp;
         struct node_struct *head, *chapter1, *chapter2, *number1, *number2;
         struct node_struct *sptr;

         fp = fopen("1342-0.txt", "r");
         head = txt2words(fp);
         // printf( "%s\n", (void *)head -> next -> next -> data );

         fclose(fp);

         sptr = search(head, "of", strcmpvoid);

         printf("%p\n", (void *)sptr);

         chapter1 = sptr->data;
         printf("%p\n", (void *)(chapter1));
         printf("-%s\n", chapter1->data);

         number1 = chapter1->next;
         printf("%p\n", (void *)(number1));
         printf("-%s\n", (char *)(number1->data));

         chapter2 = ((struct node_struct *)(sptr->next))->data;
         printf("%p\n", (void *)(chapter2));
         printf("-%s\n", (char *)(chapter2->data));

         number2 = chapter2->next;
         printf("%p\n", (void *)(number2));
         printf("-%s\n", (char *)(number2->data));

     free(sptr);
 }
 */

/*
  
  //Txt2words, ftext test case
  
  FILE *fp;
  fp = fopen("1342-0.txt", "r");

    struct node_struct *ptr;

    ptr =  txt2words(fp);
    fclose(fp);


    fp = fopen("output.txt", "w");
    ftext(fp, ptr);
  
  free(ptr);

  */
