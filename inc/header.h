#ifndef HEADER_H
#define HEADER_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct map_size {
    int width;
    int heigth;
} Size;

typedef struct map {
    int width;
    int heigth;
    int **dots;
} Map;

// print
void mx_printstr(const char *s);
void mx_printchar(char c);
void mx_printerr(const char *s);

// mx_file_to_str
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_file_to_str(const char *filename, char skip_symbol);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
// atoi
int mx_atoi(const char *str);

// reads file and returns size of map (comas exluded)
Map_size read_map(char *filename);
void error_map_check(char *argv[], int x1, int y1, int x2, int y2, Size map_size);
#endif
