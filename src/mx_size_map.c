#include "../inc/header.h"

Size read_map(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    int height = 0, width = 0;
    char c;

    while (read(fd, &c, 1) > 0) {
        if (c != ',' && c != '.' && c != '#' && c != '\n') {
            mx_printerr("map error\n");
            exit(1);
        }
        if (c == '\n') {
            if (width == 0) {
                width = height;
            }
            height++;
        } else if (c != ',') {
            width++;
        }
    }

    close(fd);
    if(close(fd) < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    Size map_size;
    map_size.width = width;
    map_size.height = height;

    return map_size;
}
