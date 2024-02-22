#include "../inc/header.h"

char **mx_parse_text(char *text) 
{
    int num_lines = 0;

    for (char *c = text; *c != '\0'; c++) {
        if (*c == '\n') {
            num_lines++;
        }
    }

    char **parsed_text = malloc(sizeof(char*) * (num_lines + 1));
    char *current_line = mx_strnew(0);
    int line_index = 0;

    for (char *c = text; *c != '\0'; c++) {
        if (*c == '\n') {
            parsed_text[line_index++] = current_line;
            current_line = mx_strnew(0);
        } else if (*c == '#' || *c == '.') {
            current_line = mx_str_add(current_line, *c);
        }
    }
    parsed_text[line_index] = NULL;

    return parsed_text;
}
