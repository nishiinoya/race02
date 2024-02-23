#include "../inc/header.h"

char *mx_open_rewrite_file(char *argv[]) {
    int file = open(argv[1], O_RDWR);
    if (file < 0) {
        mx_printerr("map does not exist\n");
        exit(1);
    }
    char buf;
    int ref;

    char *result = mx_strnew(0);
    while ((ref = read(file, &buf, 1)) > 0) {
        if (ref < 0) {
            mx_printerr("map does not exist\n");
            exit(1);
        }
        if (buf != '#' && buf != '.' && buf != ',' && buf != '\n' && buf != '\r') {
            mx_printerr("map error\n");
            exit(1);
        }
        if (buf != '\r')
            result = mx_str_add(result, buf);
    }

    if (close(file) < 0) {
        mx_printerr("error\n");
        exit(1);
    }

    return result;
}
