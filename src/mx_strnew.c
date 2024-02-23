#include "../inc/header.h"

char *mx_strnew(const int size)
{
    if(size < 1)
        return NULL;
    
    char *pc = (char *)malloc(size + 1);

    if(pc == NULL)
        return NULL;

    for(int i = 0; i < size; i++)
    {
        pc[i] = '\0';
    }

    return pc;
}   
