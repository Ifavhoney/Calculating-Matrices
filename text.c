/*
full name: Jason Eddy N'Guessan, student ID number: 1079936, and uoguelph e-mail: jnguessa@uoguelph.ca
 */
#include "text.h"
void remove_repeats(struct node_struct *list, int (*compar)(const void *, const void *))
{

    int ret = -1;
    struct node_struct *prev;
    int i = 0;
    prev = list;

    while (list->next != NULL)
    {

        list = list->next;
        if (i != 1)
        {

            i++;
            continue;
        }
        else
        {
            prev = prev->next;
        }

        if (list->next != NULL)
        {
            ret = (compar)(list->data, list->next->data);
            if (ret == 0)
            {
                /*
                int n = (compar)(list->data, (void *)"\n");
                if (n != 0)
                {
                    free_list(prev->next, 1);
                }
                */
                free_list(prev->next, 1);
            }
        }
    }
}

struct node_struct *search(struct node_struct *list, char *target, int (*compar)(const void *, const void *))
{

    int ret;
    struct node_struct *ptr2;
    struct node_struct *list2 = (struct node_struct *)malloc(sizeof(struct node_struct));

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

            ptr2 = (struct node_struct *)malloc(sizeof(struct node_struct));
            ptr2->data = list;
            ptr2->next = NULL;

            struct node_struct *temp;
            temp = list2;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = ptr2;
        }
    }
    return list2;
}

int length(struct node_struct *list)
{
    int i = 0;

    if (list == NULL)
    {
        return 0;
    }
    while (list->next != NULL)
    {
        list = list->next;
        i++;
    }
    return i + 1;
}

struct node_struct *copy(struct node_struct *start, struct node_struct *end)
{
    
    if (start == NULL || end == NULL) {
        return NULL;
    }

    struct node_struct *ptr2;
    struct node_struct *list2 = (struct node_struct *)malloc(256);

    long length;
    while (start != end)
    {

        length = strlen(start->data);

        if (start->next != NULL && start->data != NULL)
        {

            ptr2 = (struct node_struct *)malloc(length);
            ptr2->data = start->data;

            struct node_struct *temp;

            temp = list2;

            if (list2->data == NULL)
            {
                list2->data = ptr2->data;
                list2->next = NULL;
                continue;
            }

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr2;
        }

        start = start->next;
    }

    return list2;
}

struct node_struct *txt2words(FILE *fp)
{
    char buff[256];
    struct node_struct *word;
    word = (struct node_struct *)malloc(sizeof(struct node_struct));

    if (fp != NULL)
    {
        while (fgets(buff, 256, fp) != NULL)
        {
            char *val = (char *)malloc(256);
            strcat(val, buff);
            word->data = buff;
            get_word(&word);
        }
    }
    else
    {
        printf("unable to open file");
    }

    return word;
}

char *get_word(struct node_struct **list)
{

    struct node_struct *ptr2;

    struct node_struct *ptr = (struct node_struct *)malloc(sizeof(struct node_struct));

    ptr = *list;
    /*Takes that whole line's length*/
    int length = (int)strlen(ptr->data) + 2;

    char array[length];

    memcpy(array, ptr->data, length);

    char firstWord[length];

    char *innitialWord = malloc(length);

    int i;

    int begin = 0;

    for (i = 0; array[i] != '\0'; i++)
    {

        if (array[i] == ' ' || array[i + 1] == '\0')
        {

            char *temp;

            temp = malloc(length);
            while (begin <= i)
            {
                /*Glues the words together*/

                if (array[begin + 1] == '\0')
                {
                    strncat(temp, &array[begin], 1);
                }

                if (begin == i)
                {
                    break;
                }

                firstWord[begin] = array[begin];

                strncat(temp, &firstWord[begin], 1);

                begin++;
            }
            /*End the line */
            firstWord[begin] = '\0';
            strncat(temp, &firstWord[begin], 1);

            ptr2 = (struct node_struct *)malloc(sizeof(struct node_struct));

            ptr2->data = temp;
            ptr2->next = NULL;

            struct node_struct *prev = *list;

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

            prev->next = ptr2;
            /* printf("%s", ptr2 ->data); */
            begin++;
        }
    }

    ptr->data = innitialWord;
    return ptr->data;
}

void free_list(struct node_struct *list, int free_data)
{

    struct node_struct *current;
    while (list->next != NULL)
    {
        if (free_data == 0)
        {
            free(list);
        }
        else
        {
            current = list;

            current->next = list->next->next;

            break;
        }
    }
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
            fwrite(ptr->data, sizeof(char), strlen(ptr->data) + 1, fp);
            fwrite("\n", sizeof(char), 1, fp);
        }
    }

    return 1;
}
