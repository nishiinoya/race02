#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(0);
    }
    int map = open(argv[1], O_RDONLY);
    error_handling(map, argv);
    
    return 0;
}
