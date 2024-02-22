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

void error_handling(int map, char *argv[]);

#endif
