#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(0);
    }
    return 0;

    int file = open(argv[1], O_RDONLY);
    if(file < 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    if(close(file) < 0) {
        mx_printerr("error\n");
        exit(0);
    }
}
