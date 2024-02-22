#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(0);
    }
    int map = open(argv[1], O_RDONLY);
    if (map < 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    // err if x1,y1 = '#' mx_printerr("entry point cannot be an obstacle");
    // err if x2,y2 = '#' mx_printerr("exit point cannot be an obstacle");
    // err : mx_printerr("route not found");
    // err out of range mx_printerr("points are out of map range");

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
