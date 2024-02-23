#include "../inc/header.h"

char *mx_strcat(char *s1, const char *s2 ) 
{
    int lenght = mx_strlen(s1);

    for(int i = 0; lenght < mx_strlen(s1) + mx_strlen(s2); i++) 
    {
        s1[lenght] = s2[i];
        lenght++;
    }
    return s1;
}
