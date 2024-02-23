#include "../inc/header.h"

char *mx_strjoin(char const *s1, char const *s2)
{
    if(s1 == NULL && s2 == NULL) 
        return NULL;

    if(s1 == NULL)
        return mx_strdup(s2);

    if(s2 == NULL)
        return mx_strdup(s1);

    int size = mx_strlen(s1) + mx_strlen(s2) - 2;
    char *p = mx_strnew(size);
    p = mx_strcat(p, s1);
    p = mx_strcat(p, s2);
   
    return p;
}
