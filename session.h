#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#include "./charnd.h"

#define LMTSTR 30

struct Session
{
    char keyword[LMTSTR];
    int keynumber[LMTSTR];
};


typedef struct Session;


bool init_session(Session *pointer)
{

    char aux[(sizeof(pointer->keyword))];
    int aux2[(sizeof(pointer->keynumber)) / (sizeof(int))];

    genHash_char(aux);
    genHash_int(aux2);

    if(strcpy(pointer->keyword,aux))
    {   
        puts("SessionLog:Keyword generated.");
        if(pointer->keynumber == aux2)
        {
            puts("SessionLog:Keynumber generated.");
            return true;
        }
    }

    puts("SessionLog:A error occured in the init_session function.");
    puts("May be a Error with a pointer in the strcpy() operation.");
    return false;
}

bool verify_validSession(Session *pointerGenerate,Session *pointerNow)
{  
    if(pointerGenerate->keynumber == pointerNow->keynumber)
    {
        puts("VerifyValidSession:Pass 1/2:OK.");
        if(strcmp(pointerGenerate->keyword,pointerNow->keyword))
        {
            puts("VerifyValidSession:Pass 2/2:OK.");
            return true;
        }
    }
    return false;
}