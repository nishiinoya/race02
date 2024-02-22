#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
//print
void mx_printstr(const char *s);
void mx_printchar(char c);
void mx_printerr(const char *s);

<<<<<<< HEAD
=======
//mx_file_to_str
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_file_to_str(const char *filename);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
int mx_strlen(const char *s);

>>>>>>> 6b41871bf41ea77ceb512cc796e380eb539c5586
#endif
