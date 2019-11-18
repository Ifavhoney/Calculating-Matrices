#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>

#define BUFFER_SIZE 1024
int array1[20000];
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

int hash1RedMain(char c, int max)
{

    if (isupper(c))
    {

        return (int)(c - '#');
    }
    if (islower(c))
    {
        return (int)(c - '#');
    }

    return 26;
}

int hash1Red2(char c, int max)
{

    if (isupper(c))
    {

        return (int)(c + '#');
    }
    if (islower(c))
    {
        return (int)(c + '#');
    }

    return 26;
}

int hash1RedNum(char c, int max)
{

    int ran = rand() % (120 + 1 - 65) + 65;

    if (isupper(c))
    {

        return (int)(ran + 7);
    }
    if (islower(c))
    {
        return (int)(ran + 7);
    }

    return 26;
}

int hash1Red5(char c, int max)
{

    int ran = rand() % (120 + 1 - 65) + 65;

    if (isupper(c))
    {

        return (int)(ran - 30);
    }
    if (islower(c))
    {
        return (int)(ran - 30);
    }

    return 26;
}

int hash1(char *s, int max)
{

    if (max % 2 == 0)
    {

        max = max + 1;
    }
    char *c;

    unsigned long number, column, new;

    column = 1;
    number = 0;

    if (strstr(s, "2") != NULL)
    {
        new = 0;
        for (c = s; (*c); c++)
        {

            number += hash1Red2(*c, max) * column;
            column *= 27;
        }

        while (number)
        {
            new = ((new + (number << 4)) % max);
            number = (number / (max));
        }

        return (int)new;
    }

    if (strstr(s, "5") != NULL)
    {
        new = 0;
        for (c = s; (*c); c++)
        {

            number += hash1Red5(*c, max) * column;
            column *= 27;
        }

        while (number)
        {
            new = ((new + (number << 8)) % max);
            number = (number / (max));
        }

        return (int)new;
    }

    if (strstr(s, "#") != NULL)
    {
        new = 0;
        for (c = s; (*c); c++)
        {

            number += hash1RedNum(*c, max) * column;
            column *= 28;
        }

        while (number)
        {
            new = ((new + (number << 1)) % max);
            number = (number / (max));
        }

        return (int)new;
    }

    for (c = s; (*c); c++)
    {

        number += hash1RedMain(*c, max) * column;
        column *= 27;
    }

    new = 0;
    int i = 0;

    while (number)
    {

        i++;

        new = (new + (number << 2)) % max;

        number = (number / max);
    }

    printf("%ld0#\n", new);
    return (int)new;
}

int reduce2(char c, int max)
{

    if (isupper(c))
    {

        return (int)(c - '#') % max;
    }
    if (islower(c))
    {
        return (int)(c - '#') % max;
    }

    return 26;
}

char asciConvert(char *c, int counter)
{
    int value = 0;
    char asci = '1';
    if (counter == 1)
    {
        value = ((*c - 48) + 65 + (counter * 10));

        return asci = (char)value;
    }
    if (counter == 2)
    {

        value = ((*c - 48) + 65 + (counter * 10));
        return asci = (char)value;
    }
    if (counter == 3)
    {

        value = ((*c - 48) + 65 + (counter * 10));
        return asci = (char)value;
    }
    if (counter == 4)
    {

        value = ((*c - 48) + 65 + (counter * 10));
        return asci = (char)value;
    }
    if (counter == 5)
    {

        value = ((*c - 48) + 65 + ((counter / 2) * 10));
        return asci = (char)value;
    }
    if (counter > 5)
    {

        value = ((*c - 48) + 65 + ((counter / 2) * 10));
        return asci = (char)value;
    }

    else
    {
        asci = (char)65;
        return asci;
    }
}

long hash(long x)
{
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

long hash2(char *s, int max)
{

    if (max % 2 == 0)
    {

        max = max + 1;
    }
    char str1[10];

    char *c;
    char *string;
    char *preString;
    char asci;
    char *end;
    int number, column, new, firstZero, counter, value;
    long result;

    value = 0;
    firstZero = 0;
    counter = 0;
    new = 0;
    asci = ' ';
    column = 1;
    number = 0;

    //NUMBER portion
    string = malloc(sizeof(strlen(s) * 2));

    preString = malloc(sizeof(strlen(s) * 2));

    /*Special case needed for x1 && MD && L1 && LH && RA && B1-2 --- ||J2, J3, J4, J5 -- B1 -- LPN O1*/
    if (strstr(s, "G1") || strstr(s, "G3") || strstr(s, "RA"))
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 4)
            {

                sprintf(str1, "%d", asci + 3);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10) / 2;

        printf("||TH result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    //202675
    if (strstr(s, "G2") == s || strstr(s, "MD") == s || strstr(s, "JT") == s || strstr(s, "U2") || strstr(s, "O1") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 4)
            {

                sprintf(str1, "%d", asci + 3);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||TH result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "LG") == s || strstr(s, "PC") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter == 0)
            {

                sprintf(str1, "%d", asci << 2);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||TH result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "M1-E") == s || strstr(s, "CA") == s || strstr(s, "LH") == s || strstr(s, "DA") == s || strstr(s, "PL") == s || strstr(s, "MC") == s || strstr(s, "MT") == s || strstr(s, "ME") == s || strstr(s, "DN") == s || strstr(s, "FA") == s || strstr(s, "MM") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 10 || strstr(c, "D") == c || strstr(c, "A") == c || strstr(c, "DN") == c || strstr(c, "M") == c || strstr(c, "T") == c)
            {

                if (strstr(s, "LH") == s)
                {
                    sprintf(str1, "%d", (asci << 3));
                }
                if (strstr(s, "FA") == s)
                {
                    asci = asci + 1;
                }

                if (strstr(s, "ME") == s)
                {
                    asci = asci + 1;
                }
                sprintf(str1, "%d", (asci + 1));

                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||CC result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "L1") == s || strstr(s, "L2") == s || strstr(s, "A7") || strstr(s, "RS") == s || strstr(s, "RB") == s || strstr(s, "N1") == s || strstr(s, "R1") == s || strstr(s, "R2") == s || strstr(s, "R3") == s || strstr(s, "R4") == s)
    {

        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 3 || strstr(c, "S") == c || strstr(c, "B") == c)
            {

                sprintf(str1, "%d", (asci + 1));

                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||CC result:%s||\n", string);
        return labs((long)hash(result)) % max;
    }

    if (strstr(s, "P1") == s || strstr(s, "P2") == s || strstr(s, "P3") == s || strstr(s, "P4") == s || strstr(s, "P5") == s || strstr(s, "P7") == s)
    {

        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 10 || strstr(c, "3") == c)
            {

                if (strstr(c, "3") == c)
                {
                    asci = asci > 2;
                }
                sprintf(str1, "%d", (asci << 2));
                strncat(string, str1, 1);
            }

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||CC result:%s||\n", string);
        return (long)labs(hash(result)) % max;
    }

    if (strstr(s, "CC") == s || strstr(s, "Q3") == s)
    {

        for (c = s; *c; c++)
        {

            asci = *c;

            if (strstr(c, "C") == c || counter <= 10)
            {
                sprintf(str1, "%d", (asci + 10));
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||CC result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "M2") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 2 || strstr(c, "T") == c)
            {

                if (strstr(c, "T") == c)
                {
                    sprintf(str1, "%d", asci + 1);
                }

                sprintf(str1, "%d", asci << 2);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||TH result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "Q1") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter == 0)
            {

                sprintf(str1, "%d", asci << 2);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||TH result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "I1") == s || strstr(s, "I2") == s || strstr(s, "I3") == s || strstr(s, "I4") == s || strstr(s, "M5") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 4)
            {

                sprintf(str1, "%d", asci << 2);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||TH result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "G4") || strstr(s, "X1") == s || strstr(s, "X2") == s || strstr(s, "X3") == s || strstr(s, "X4") == s || strstr(s, "X5") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 2)
            {

                sprintf(str1, "%d", asci + 1);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||TH result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "TH") == s || strstr(s, "TJ") == s || strstr(s, "TP") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 4 || strstr(c, "H") == c || strstr(c, "J") == c)
            {
                if (strstr(c, "H") == c)
                {
                    asci = asci + 1;
                }
                if (strstr(c, "J") == c)
                {
                    asci = asci << 2;
                }

                sprintf(str1, "%d", asci << 2);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||TH result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "A7") || strstr(s, "K4") == s || strstr(s, "L6") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 4 || strstr(c, "A") == c || strstr(c, "N") == c)
            {

                sprintf(str1, "%d", asci << 2);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||L6 result:%s||\n", string);
        return labs(hash(result)) % max;
    }
    if (strstr(s, "K1") == s || strstr(s, "K3") == s || strstr(s, "AN") == s || strstr(s, "A2") == s || strstr(s, "A4") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 5 || strstr(c, "A") == c || strstr(c, "N") == c)
            {

                sprintf(str1, "%d", asci + 1);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||AN-R result:%s||\n", string);
        return labs(hash(result)) % max;
    }
    if (strstr(s, "S5") == s || strstr(s, "S4") == s || strstr(s, "S6") == s || strstr(s, "S1") == s || strstr(s, "S2") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 1 || strstr(c, "B") == c || strstr(c, "R") == c || strstr(c, "L") == c || strstr(c, "E") == c || strstr(c, "A") == c)
            {
                if (strstr(c, "B") == c)
                {
                    asci = asci < 2;
                }
                if (strstr(c, "R") == c)
                {
                    asci = asci << 2;
                }

                sprintf(str1, "%d", asci >> 1);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||S5 result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "E1") == s || strstr(s, "E2") == s || strstr(s, "E3") == s)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 2)
            {
                if (strstr(s, "E2") == s)
                {
                    asci = asci + 3;
                }

                sprintf(str1, "%d", asci);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        long result = strtol(string, &end, 10);

        printf("||E1 result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "M1-R") != NULL)
    {
        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 2 || strstr(c, "R") != NULL)
            {

                sprintf(str1, "%d", asci);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||M1-R result:%s||\n", string);
        return labs(hash(result)) % max;
    }
    if (strstr(s, "ed") != NULL || strstr(s, " ") != NULL)
    {

        s++;
        new = 0;
        for (c = s; (*c); c++)
        {

            //key
            number += hash1Red5(*c, max) * column;
            column *= 27;
        }

        while (number)
        {
            new = ((new + (number << 4)) % max);
            number = (number / (max));
        }
        printf("new: %d\n", new);
        return labs(new);
    }
    if (strstr(s, "M1") == s || strstr(s, "H1") == s || strstr(s, "O1") == s || strstr(s, "C1") == s ||
        strstr(s, "C6") == s || strstr(s, "C7") == s || strstr(s, "C8") == s || strstr(s, "C9") == s ||

        strstr(s, "J1") == s || strstr(s, "C9") == s || strstr(s, "L5") == s || strstr(s, "L4") == s || strstr(s, "L3") == s || strstr(s, "C2") == s || strstr(s, "C3") == s || strstr(s, "C4") == s || strstr(s, "C5") == s || strstr(s, "J2") == s || strstr(s, "J3") == s || strstr(s, "J4") == s ||
        strstr(s, "ing") == NULL)
    {

        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 2)
            {

                if (strstr(s, "J1") == s)
                {

                    asci = asci + 2;
                }
                if (strstr(s, "J2") == s)
                {

                    asci = asci + 4;
                }
                if (strstr(s, "J3") == s)
                {

                    asci = asci + 3;
                }
                if (strstr(s, "M1") == s)
                {

                    asci = asci << 9;
                }
                if (strstr(s, "L1") == s)
                {

                    asci = asci + 1;
                }
                if (strstr(s, "L2") == s)
                {

                    asci = asci - 3;
                }
                if (strstr(s, "C1") == s)
                {

                    asci = asci + 1;
                }
                if (strstr(s, "H1") == s)
                {

                    asci = asci + 10;
                }
                if (strstr(s, "J1") == s)
                {

                    asci = asci + 7;
                }

                if (strstr(s, "C5") == s)
                {

                    asci = asci + 1;
                }

                if (strstr(s, "C6") == s)
                {

                    asci = asci + 3;
                }

                if (strstr(s, "C7") == s)
                {

                    asci = asci + 9;
                }

                if (strstr(s, "C8") == s)
                {

                    asci = asci + 7;
                }

                if (strstr(s, "C9") == s)
                {

                    asci = asci + 9;
                }

                sprintf(str1, "%d", asci);

                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
            /*

                                                    if (firstZero == 1 && strcmp(c, "0") == 0)
                                                    {

                                                        strncat(string, "0", 1);
                                                        c++;
                                                    }
                      */
        }

        printf("---%s", string);

        strcat(string, preString);
        long result = strtol(string, &end, 10);
        result = labs(hash(result)) % max;

        printf("||1 result:%s||\n", string);
        return result;
    }

    if (strstr(s, "U1") != NULL)
    {

        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter == 0)
            {

                sprintf(str1, "%d", asci << 3);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||U1 result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "GPN") != NULL || strstr(s, "HM") != NULL || strstr(s, "DR") != NULL || strstr(s, "GN") != NULL)
    {

        for (c = s; *c; c++)
        {

            asci = *c;

            if (counter <= 4)
            {

                sprintf(str1, "%d", asci);
                strncat(string, str1, 1);
            }

            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
            /*

                                                    if (firstZero == 1 && strcmp(c, "0") == 0)
                                                    {

                                                        strncat(string, "0", 1);
                                                        c++;
                                                    }
                      */
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||T2 result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "RN") != NULL)
    {

        sprintf(str1, "%d", asci / 2);
        strncat(string, c, 1);

        for (c = s; *c; c++)
        {
            asci = *c;

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
            /*

                                  if (firstZero == 1 && strcmp(c, "0") == 0)
                                  {

                                      strncat(string, "0", 1);
                                      c++;
                                  }
    */
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10);

        printf("||T2 result:%s||\n", string);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "-") != NULL && strlen(s) < 10

    )

    {

        for (c = s; *c; c++)
        {
            asci = *c;

            if (counter <= 2)
            {

                sprintf(str1, "%d", asci);
                strncat(string, str1, 1);
            }

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                continue;
            }

            if (*c > '0')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }
            /*

                                      if (firstZero == 1 && strcmp(c, "0") == 0)
                                      {

                                          strncat(string, "0", 1);
                                          c++;
                                      }
        */
        }

        printf("---%s", string);

        strcat(string, preString);
        result = strtol(string, &end, 10) % max;
        printf("||GPN:%d||\n", result);
        return labs(hash(result)) % max;
    }

    if (strstr(s, "0") != NULL && strstr(s, "#") == NULL)
    {
        s++;
        for (c = s; *c; c++)
        {
            asci = *c;

            if (counter == 0)
            {

                sprintf(str1, "%d", asci);
                strncat(string, str1, 1);
            }

            if (asci >= 64 && asci <= 90 && asci != 45)
            {

                sprintf(string, "%d", asci);

                // strncat(string, , 1);

                continue;
            }

            if (*c != '0' && *c != '-')
            {

                firstZero = 1;

                counter++;

                strncat(string, c, 1);
            }

            if (firstZero == 1 && strcmp(c, "0") == 0)
            {

                strncat(string, "0", 1);
                c++;
            }
        }

        //117818
        strcat(string, preString);
        result = strtol(string, &end, 10);
        printf("||%s: %d||\n", s, result);

        return labs(hash((int)result) % max);
    }

    else
    {

        s++;
        new = 0;
        for (c = s; (*c); c++)
        {

            //key
            number += hash1Red5(*c, max) * column;
            column *= 27;
        }

        while (number)
        {
            new = ((new + (number << 4)) % max);
            number = (number / (max));
        }
        printf("new: %d\n", new);
        return labs(new); /*
    strcat(preString, string);

    char *end;
    result = strtol(string, &end, 10) % max;
    printf("||%ld||", result);
     */
    }
}

struct array *read_records()
{
    char buffer[BUFFER_SIZE];

    struct array *arrptr;

    FILE *fp;

    int line, start, end;

    arrptr = malloc(sizeof(struct array));
    arrptr->nelements = 0;

    fp = fopen("Professional_and_Occupational_Licensing1.csv", "r");
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
            ;
        /*last name*/
        (arrptr->arr)[line].last_name = malloc(end - start + 1);
        strncpy((arrptr->arr)[line].last_name, buffer + start, end - start);
        (arrptr->arr)[line].last_name[end - start] = '\0';

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        /*first name*/
        (arrptr->arr)[line].first_name = malloc(end - start + 1);
        strncpy((arrptr->arr)[line].first_name, buffer + start, end - start);
        (arrptr->arr)[line].first_name[end - start] = '\0';

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ;

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ;

        (arrptr->arr)[line].license_no = malloc(end - start + 1);
        strncpy((arrptr->arr)[line].license_no, buffer + start, end - start);
        (arrptr->arr)[line].license_no[end - start] = '\0';
        /* find next comma */

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ; /* find next comma */

        (arrptr->arr)[line].license_type = malloc(end - start + 1);
        strncpy((arrptr->arr)[line].license_type, buffer + start, end - start);
        (arrptr->arr)[line].license_type[end - start] = '\0';

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

        start = end + 1;
        for (end = start; buffer[end] != ','; end++)
            ;

        (arrptr->arr)[line].issue_date = malloc(end - start + 1);
        strncpy((arrptr->arr)[line].issue_date, buffer + start, end - start);
        (arrptr->arr)[line].issue_date[end - start] = '\0';
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
        printf(" Adding %s\n", (arrptr->arr)[line].license_no);

        idx = hash2((arrptr->arr)[line].license_no, arrptr->hash_size);

        duplicate = 0;
        //meaning that slot is taken e.g -1
        while ((arrptr->hash)[idx] != NULL)
        {
            if (strcmp(((arrptr->hash)[idx])->license_no,
                       (arrptr->arr)[line].license_no) == 0)
            {
                printf("  Skipping duplicate\n");
                duplicates++;
                duplicate = 1;
                break;
            }

            printf("collision at %d %s\n", idx, ((arrptr->hash)[idx])->license_no);
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

    idx = hash2(key, arrptr->hash_size);
    while ((arrptr->hash)[idx] != NULL)
    {
        if (strcmp(key, ((arrptr->hash)[idx])->license_no) == 0)
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
    printf( " %d %s, %s: %s %s %s |%d\n", line,
                         (arrptr->arr)[line].last_name,
                        (arrptr->arr)[line].first_name,
                (arrptr->arr)[line].license_no,
           (arrptr->arr)[line].license_type,
           (arrptr->arr)[line].issue_date,

           
                    str2int( (arrptr->arr)[line].last_name, 100 ) );
  }
    */

    printf("Duplicates: %d\n", duplicates);
    printf("Collisions: %d\n\n", collisions);

    r = find("L1-0015338", arrptr);
    if (r == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("found\n");

        /*
         printf("%s, %s : %s\n", r->last_name,
                r->first_name,
                r->license_type);
         */
    }

    r = find("L2-0007835", arrptr);
    if (r == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("found\n");

        /*
            printf("%s, %s : %s\n", r->last_name,
                   r->first_name,
                   r->license_type);
            */
    }

    r = find("TJ-0000322", arrptr);
    if (r == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        printf("found\n");
    }

    free_array_ptr(arrptr);
    return 0;
}
