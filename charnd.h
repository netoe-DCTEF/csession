#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

char allowedChar[] =
{
    "ABCDEFGHIJKLMNOPQRSUVWXYZabcefghijklmnopqrstuvwxyz1234567890!@#$%¨&*()"
};



void setSeed()
{
    srand(
        time(NULL)
    );
}

void setChar()
{
    setlocale(LC_ALL,"");
}

int genRnd(const int limit)
{
    return rand() % limit;
}

void genHash_char(char *string)
{
    setSeed();
    setChar();
    int maxsize = sizeof(string);
    int i = 0;

    for(i = 0;i < maxsize;i++)
    {
        string[i] = allowedChar[genRnd(sizeof(allowedChar) - 1)];
    }
}

void genHash_int(int *pointer)
{
    setSeed();
    setChar();
    int maxsize = (sizeof(pointer)) / (sizeof(int));
    int i = 0;

    for(i = 0;i < maxsize;i++)
    {
        pointer[i] = genRnd(RAND_MAX);
    }

}




