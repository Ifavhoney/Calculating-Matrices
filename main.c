//
//  main.c
//  assignment2
//
//  Created by Jason Eddy on 2019-10-09.
//  Copyright © 2019 Jason Eddy. All rights reserved.
//

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

  sptr = search(head, "The", strcmpvoid);
  sptr1 = search(head, "online", strcmpvoid);

  chapter1 = sptr->data;
  chapter2 = sptr1->data;

  copy_of = copy(chapter1, chapter2);

  //free_list( copy_of, 0 );
  free_list(copy_of->data, 0);

  if (copy_of != NULL)
  {
    printf("%s", copy_of->data);
  }

  return 0;
}

/*
 Copy Test Case
 
  FILE *fp;
  struct node_struct *head, *chapter1, *chapter2, *copy_of;
     struct node_struct *sptr, *sptr1;
 
  fp = fopen( "1342-0.txt", "r" );
  head = txt2words( fp );

  fclose( fp );
 
 sptr = search( head, "The", strcmpvoid );
 sptr1 = search( head, "online", strcmpvoid );
 
 chapter1 = sptr -> data;
 chapter2 = sptr1 -> data;

 copy_of = copy(chapter1, chapter2);
 while (copy_of -> next != NULL) {
     copy_of = copy_of -> next;
     printf("%s",copy_of -> data);
 }
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

   return 0;
 }
 */

/*
  
  
  
  FILE *fp;
  fp = fopen("1342-0.txt", "r");

       //array is a pointer??
    struct node_struct *ptr;

       //& gets the address, but i just
    ptr =  txt2words(fp);
    fclose(fp);


    fp = fopen("output.txt", "w");
    ftext(fp, ptr);
  
  
 char txt[] = "Hello Jason Eddy MK\nKaizer God";
 list = (struct node_struct *)malloc(sizeof(struct node_struct));
 list -> data = txt ;
 //how to reference the pointer - nneed a double pointer
//  get_word(&list);
  free(ptr);

  */
