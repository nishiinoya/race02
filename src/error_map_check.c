#include "../inc/header.h"

void error_map_check(char *argv[], int x1, int y1, int x2, 
    int y2, Size map_size) {

    char *str_file = mx_file_to_str(argv[1], ",");

    // Check if x1, y1, x2, y2 are within the map boundaries
    if (x1 < 0 || x1 >= map_size.width || y1 < 0 || y1 >= map_size.height ||
        x2 < 0 || x2 >= map_size.width || y2 < 0 || y2 >= map_size.height) {
        mx_printerr("points are out of map range\n");
        exit(1);
    }

    // Check if the entry point (x1, y1) and exit point (x2, y2) are obstacles
    if (str_file[y1 * map_size.width + x1] == '#') {
        mx_printerr("entry point cannot be an obstacle\n");
        free(str_file);
        exit(1);
    }

    if (str_file[y2 * map_size.width + x2] == '#') {
        mx_printerr("exit point cannot be an obstacle\n");
        free(str_file);
        exit(1);
    }
    if (close(str_file) < 0) {
        mx_printerr("error\n");
        exit(1);
    }
    free(str_file);
}
