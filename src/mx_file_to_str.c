#include "../inc/header.h"

//modified to skip comas
char *mx_file_to_str(const char *filename, char skip_symbol) {
    int size = 0;
    char c;

    if (filename == NULL)
        return NULL;

    int fileToOpen = open(filename, O_RDONLY);
    if (fileToOpen < 0)
        return NULL;

    // Calculate the size excluding the skipped symbol
    while (read(fileToOpen, &c, 1))
        if (c != skip_symbol){
            size++;
        }

    close(fileToOpen);

    fileToOpen = open(filename, O_RDONLY);
    if (fileToOpen < 0)
        return NULL;

    char *str = mx_strnew(size);
    int index = 0;

    // Read characters and skip the specified symbol
    while (read(fileToOpen, &c, 1)) {
        if (c != skip_symbol) {
            str[index] = c;
            index++;
        }
    }

    close(fileToOpen);
    return str;
}
