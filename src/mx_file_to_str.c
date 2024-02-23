#include "../inc/header.h"

char *mx_file_to_str(const char *filename) {
    int file_open = open(filename, O_RDONLY);
    char s[1];
    int file_read = read(file_open, s, 1);
    int counter = 0;

    while (file_read > 0) {
        if (s[0] == '#' || s[0] == '.' || s[0] == '\n') {
            ++counter;
        }
        file_read = read(file_open, s, 1);
    }
    close(file_open);

    file_open = open(filename, O_RDONLY);
    char *res = (char *)malloc(counter + 1);

    file_read = read(file_open, s, 1);

    for (int i = 0; i < counter && file_read > 0; ++i) {
        if (s[0] == '.' || s[0] == '#' || s[0] == '\n') {
            res[i] = s[0];
            ++i;
        }
        file_read = read(file_open, s, 1);
        --i;
    }
    res[counter] = '\0';
    close(file_open);
    return res;
}
