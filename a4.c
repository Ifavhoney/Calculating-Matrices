#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>

#define BUFFER_SIZE 1024

int collisions;
int duplicates;

//lesson type L(Alphabet)#-123
struct record
{
    char *last_name;
    char *first_name;
    char *license_type;
    char *license_no;
    char *issue_date;
};

struct array
{
    struct record *arr;
    int nelements;
    struct record **hash;
    int hash_size;
};

int char2int(unsigned char c)
{

    if (isupper(c))
    {

        return (int)(c - 'A');
    }
    if (islower(c))
    {
        return (int)(c - 'a');
    }

    return 26;
}

int hash2(long key)
{
    return (7 - (key % 7));
}

int reduce1(char c, int max)
{

    if (isupper(c))
    {

        return (int)(c - '#') % max;
    }
    if (islower(c))
    {
        return (int)(c - '#' % max);
    }

    return 26;
}

int hash1(char *s, int max)
{
    char *c;
    int i = 0;
    unsigned long number, column, new;

    if (max % 2 == 0)
    {

        max = max + 1;
    }

    column = 1;
    number = 0;

    for (c = s; (*c); c++)
    {

        //key
        number += reduce1(*c, max) * column;
        column *= 27;
    }

    new = 0;

 
    while (number)
    {

        i++;

        new = (new + (number << 2)) % max;

        number = (number / max);
    }

    if (strstr(s, "#") != NULL)
    {
        new = 0;
        for (c = s; (*c); c++)
        {

            //key
            number += reduce1(*c, max) * column;
            column *= 7;
        }

        i = 0;

        while (number)
        {
            new = ((new + (number << 3)) % max);
            number = (number / (max));
        }
    }

    printf("%ld---#\n", new);
    return (int)new;
}

struct array *read_records()
{
    char buffer[BUFFER_SIZE];

    struct array *arrptr;

    FILE *fp;

    int line, start, end;

    arrptr = malloc(sizeof(struct array));
    arrptr->nelements = 0;

    fp = fopen("Professional_and_Occupational_Licensing.csv", "r");
    fgets(buffer, BUFFER_SIZE, fp);

    while (!feof(fp))
    {
        if (fgets(buffer, BUFFER_SIZE, fp) == NULL)
        {
            break;
        }

        if (strlen(buffer) == BUFFER_SIZE - 1)
        {
            fprintf(stderr, "Error:  BUFFER TOO SMALL\n");
            exit(-1);
        }

        (arrptr->nelements)++;
    }

    arrptr->arr = malloc(sizeof(struct record) * (arrptr->nelements));

    fseek(fp, 0, SEEK_SET);

    fgets(buffer, BUFFER_SIZE, fp);
    for (line = 0; line < arrptr->nelements; line++)
    {
        fgets(buffer, BUFFER_SIZE, fp);

        start = 0;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        /*last name*/
        (arrptr->arr)[line].last_name = malloc(end - start + 1);
        strncpy((arrptr->arr)[line].last_name, buffer + start, end - start);
        (arrptr->arr)[line].last_name[end - start] = '\0';

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        (arrptr->arr)[line].first_name = malloc(end - start + 1);
        strncpy((arrptr->arr)[line].first_name, buffer + start, end - start);
        (arrptr->arr)[line].first_name[end - start] = '\0';

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
        {

            (arrptr->arr)[line].first_name = malloc(end - start + 1);
            strncpy((arrptr->arr)[line].first_name, buffer + start, end - start);
            (arrptr->arr)[line].first_name[end - start] = '\0';
        }
        /* find next comma */

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        (arrptr->arr)[line].license_type = malloc(end - start + 1);
        strncpy((arrptr->arr)[line].license_type, buffer + start, end - start);
        (arrptr->arr)[line].license_type[end - start] = '\0';
    }

    return arrptr;
}

void build_hash(struct array *arrptr, int hash_size)
{
    int idx, line;
    int duplicate;

    //my size
    arrptr->hash_size = hash_size;
    //my hash table
    arrptr->hash = malloc(sizeof(struct record *) * arrptr->hash_size);

    for (idx = 0; idx < arrptr->hash_size; idx++)
    {
        (arrptr->hash)[idx] = NULL;
    }

    for (line = 0; line < arrptr->nelements; line++)
    {
        printf(" Adding %s\n", (arrptr->arr)[line].last_name);

        idx = hash1((arrptr->arr)[line].last_name, arrptr->hash_size);

        duplicate = 0;
        //meaning that slot is taken e.g -1
        while ((arrptr->hash)[idx] != NULL)
        {
            if (strcmp(((arrptr->hash)[idx])->last_name,
                       (arrptr->arr)[line].last_name) == 0)
            {
                printf("  Skipping duplicate\n");
                duplicates++;
                duplicate = 1;
                break;
            }
            printf("  collision at %d %s\n", idx, ((arrptr->hash)[idx])->last_name);
            collisions++;
            idx++;
            if (idx >= arrptr->hash_size)
            {
                idx = 0;
            }
        }

        if (!duplicate)
        {
            (arrptr->hash)[idx] = (arrptr->arr) + line;
        }
    }
}

void free_array_ptr(struct array *ptr)
{
    int i;

    for (i = 0; i < ptr->nelements; i++)
    {
        free(ptr->arr[i].last_name);
        free(ptr->arr[i].first_name);
        free(ptr->arr[i].license_type);
    }

    free(ptr->arr);
    free(ptr->hash);

    free(ptr);
}

struct record *find(char *key, struct array *arrptr)
{
    int idx;

    idx = hash1(key, arrptr->hash_size);
    while ((arrptr->hash)[idx] != NULL)
    {
        if (strcmp(key, ((arrptr->hash)[idx])->last_name) == 0)
        {
            return (arrptr->hash)[idx];
        }
        idx++;

        if (idx >= (arrptr->hash_size))
        {
            idx = 0;
        }
    }
    return NULL;
}

int main()
{
    struct array *arrptr;
    int line;
    struct record *r;

    collisions = 0;
    duplicates = 0;

    arrptr = read_records();

    build_hash(arrptr, 500000);

    /*
  for (line=0;line<arrptr->nelements;line++)
  {
    printf( " %d %s, %s: %s %d\n", line,
                        (arrptr->arr)[line].last_name,
                        (arrptr->arr)[line].first_name,
                (arrptr->arr)[line].license_type,
           
                    str2int( (arrptr->arr)[line].last_name, 100 ) );
  }

*/
    printf("Duplicates: %d\n", duplicates);
    printf("Collisions: %d\n", collisions);

    r = find("Kremalskdfjalsdkfjer", arrptr);
    if (r == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("%s, %s : %s\n", r->last_name,
               r->first_name,
               r->license_type);
    }

    free_array_ptr(arrptr);
    return 0;
}
