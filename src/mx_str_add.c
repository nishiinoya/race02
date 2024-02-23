#include "../inc/header.h"

char *mx_str_add(char *str, char c)
{
    int len = mx_strlen(str);
    char *new_str = mx_strnew(len + 1);

    mx_strcpy(new_str, str);
    new_str[len] = c;
    new_str[len + 1] = '\0'; 

    free(str);

    return new_str;
}
