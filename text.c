#include "text.h"
struct node_struct *txt2words(FILE *fp)
{
    int MAXCHAR = 99999;
    /*Max Char*/
    char buff[MAXCHAR];
    char *val = (char *)malloc(MAXCHAR);
    struct node_struct *word;
    /*Max Char*/
    word = (struct node_struct *)malloc(MAXCHAR);

    if (fp != NULL)
    {
        while (fgets(buff, MAXCHAR, fp) != NULL)
        {

            /*use strcat to add strings and strncat for chars */
            strcat(val, buff);
        }
    }
    else
    {
        printf("unable to open file");
    }

    word->data = val;
    get_word(&word);

    printf("\n\n%s", val);

    free(val);
    /*returns head*/
    return word->data;
}

char *get_word(struct node_struct **list)
{
    printf("BEGIN");

    struct node_struct *ptr2;

    //malloc
    struct node_struct *ptr = (struct node_struct *)malloc(sizeof(struct node_struct));

    ptr = *list;
    //To get correct length of char array
    int length = (int)strlen(ptr->data) + 1;

    char array[length];

    //copies String into array 'j','a'
    memcpy(array, ptr->data, length);
    /* displays finalized word*/
    //total
    char firstWord[length];

    char *innitialWord = malloc(length); /* + 1 for null terminator. */

    int i;

    //to store beginning to next space
    int begin = 0;
    printf("\nFULL WORD: %s \n\n", array);

    for (i = 0; array[i] != '\0'; i++)
    {

        /*allows only for spaces */
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

            if (strlen(innitialWord) == 0)
            {
                memcpy(innitialWord, temp, length);
            }
            ptr2 = (struct node_struct *)malloc(sizeof(struct node_struct));

            //    printf("WORD: %s \n", temp);

            //PTR DATA
            ptr2->data = temp;
            ptr2->next = NULL;

            struct node_struct *prev = *list;

            printf("\n Adding To LinkedList:");

            while (prev->next != NULL)
            {

                prev = prev->next;
                printf("%s \n", prev->data);
            }

            /*see if ptr2 -> data exists printf it*/
            prev->next = ptr2;

            begin++;
        }
    }
    ptr->data = innitialWord;
    return ptr->data;
}
