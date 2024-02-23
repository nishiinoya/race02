#ifndef HEADER_H
#define HEADER_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct size {
    int row, col;
} size;
// print
void mx_printstr(const char *s);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printint(int n);
// mx_file_to_str
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_file_to_str(const char *filename);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
// atoi
int mx_atoi(const char *str);
void mx_strdel(char **str);

// ...
char **char_matrix(char *res, size *matrix_size);
int **matrix(char *res, size *matrix_size);
char *mx_file_to_str(const char *filename);
int mx_max(int **grid, int ax, int ay, int He, int Wi, char **final);
bool path_of_stars(int **grid, int ax, int ay, int bx, 
int by, size map_size, int *len, int *pathX, int *pathY);
void print_res(int **mat1, int x1, int y1, int row, int col, char **final, int len);
#endif
