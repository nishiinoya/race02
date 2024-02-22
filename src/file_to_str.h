#ifndef FILE_TO_STR_H
#define FILE_TO_STR_H


#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_file_to_str(const char *filename);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
int mx_strlen(const char *s);

#endif
