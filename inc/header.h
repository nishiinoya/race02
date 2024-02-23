#ifndef HEADER_H
#define HEADER_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

typedef struct map_size {
    int width;
    int height;
} Size;

typedef struct map {
    int width, height, **dots;
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

void mx_lees_alghoritm(Map **map, int x, int y, int n);
char *mx_open_rewrite_file(char *argv[]);
char *mx_str_add(char *str, char c);

//in mx_points_calc.c
void save_map_and_path(Map *map, char *filename);
void calculate_exit_path(Map *map, int x1, int y1, int x2, int y2);
void calculate_distant_point(Map *map, int x1, int y1);

char **mx_parse_text(char *text);
void mx_strdel(char **str);
void mx_printint(int n);
#endif
