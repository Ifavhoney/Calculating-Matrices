#include "text.h"

/*
   char str1[15];
   char str2[15];
   
   strcpy(str1, "ABCDEF");
   strcpy(str2, "ABCDEF");

 int ret = strcmpvoid(str1, str2);
   
   if(ret == 0){
       printf("indicates str1 is equal to str2");
   }
   else {
       printf("indicates str1 is not equal to str2");
       //not equal
   }

 */

struct node_struct *search(struct node_struct *list, char *target, int (*compar)(const void *, const void *))
{

    int ret;
    struct node_struct *ptr2;
    struct node_struct *list2 = (struct node_struct *)malloc(20);

    while (list->next != NULL)
    {
        list = list->next;

        ret = (compar)(target, list->data);

        if (ret == 0)
        {
            if (list2->data == NULL)
            {
                list2->data = list;
                list2->next = NULL;
                continue;
            }
            //  printf("Check ");
            long length = strlen(list->data) + 1;

            ptr2 = (struct node_struct *)malloc(length);
            ptr2->data = list;
            ptr2->next = NULL;

            struct node_struct *temp;
            temp = list2;

            while (temp->next != NULL)
            {
                temp = temp->next;
                // printf("%s \t", temp -> data);
            }

            temp->next = ptr2;
        }
    }
    //Tail
    //  printf("%s", list2->data);

    return list2;
}

struct node_struct *txt2words(FILE *fp)
{
    int MAXCHAR = 256;
    /*Max Char*/
    char buff[MAXCHAR];
    struct node_struct *word;
    int valSize = MAXCHAR;
    /*Max Char*/
    word = (struct node_struct *)malloc(MAXCHAR);

    if (fp != NULL)
    {
        while (fgets(buff, MAXCHAR, fp) != NULL)
        {
            char *val = (char *)malloc(valSize);
            /*use strcat to add strings and strncat for chars */
            strcat(val, buff);
            word->data = buff;
            get_word(&word);
            valSize += MAXCHAR;
        }
    }
    else
    {
        printf("unable to open file");
    }
    //    free(val);
    /*returns head*/
    return word;
}

char *get_word(struct node_struct **list)
{

    struct node_struct *ptr2;

    /*Storing GIVEN 256 CHARACTERS into ARRAY*/
    struct node_struct *ptr = (struct node_struct *)malloc(sizeof(struct node_struct));

    ptr = *list;
    int length = (int)strlen(ptr->data) + 1;

    char array[length];

    memcpy(array, ptr->data, length);

    char firstWord[length];

    char *innitialWord = malloc(length);

    int i;

    int begin = 0;
    //printf("\nFULL WORD: %s \n\n", array);

    for (i = 0; array[i] != '\0'; i++)
    {

        /*SEPRATING WORDS BY SPACE*/
        if (array[i] == ' ' || array[i + 1] == '\0')
        {
            /*malloc*/
            //   printf("test ptr -> data %s", ptr->data);

            char *temp;

            temp = malloc(length);
            while (begin <= i)
            {
                /*Tail statement*/
                if (array[begin + 1] == '\0')
                {
                    strncat(temp, &array[begin], 1);
                }

                if (begin == i)
                {
                    /*Avoids extra spaces*/
                    break;
                }

                firstWord[begin] = array[begin];

                /*use strncat when you are not sure that it has a \0 at the end and for adding chars*/
                strncat(temp, &firstWord[begin], 1);

                begin++;
            }
            /* ADDING WORD TO LINKEDLIST */
            firstWord[begin] = '\0';
            strncat(temp, &firstWord[begin], 1);

            ptr2 = (struct node_struct *)malloc(sizeof(struct node_struct));

            //    printf("WORD: %s \n", temp);

            ptr2->data = temp;
            ptr2->next = NULL;

            struct node_struct *prev = *list;

            //printf("\n Adding To LinkedList: ");

            int header = 0;
            while (prev->next != NULL)
            {
                prev = prev->next;
                if (header == 0)
                {
                    memcpy(innitialWord, prev->data, length);
                    header = 1;
                }
            }

            /*see if ptr2 -> data exists printf it*/
            prev->next = ptr2;

            begin++;
        }
    }
    ptr->data = innitialWord;
    return ptr->data;
}

int ftext(FILE *fp, struct node_struct *list)
{

    struct node_struct *ptr = (struct node_struct *)malloc(sizeof(struct node_struct));

    *ptr = *list;

    int i = 0;
    if (ptr->next == NULL)
    {
        printf("\nEMPTY!");
    }
    else
    {
        while (ptr->next != NULL)
        {
            i++;
            ptr = ptr->next;
            if (i % 80 == 0)
            {
                printf("\n");
            }
            printf("%s ", ptr->data);
            /* param(3) the number of the objects to be written & thus, param(3) individual char*/
            fwrite(ptr->data, sizeof(char), strlen(ptr->data) + 1, fp);
            fwrite("\n", sizeof(char), 1, fp);
        }
    }

    return 1;
}
