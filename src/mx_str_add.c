#include "../inc/header.h"

char *mx_str_add(char *str, char c)
{
	int size = mx_strlen(str) + 1;
	char *s = mx_strnew(size);
    
	for(int i = 0; i < size; i++)
		if(i == size - 1)
			s[i] = c;
		else 
			s[i] = str[i];
	return s;
}
