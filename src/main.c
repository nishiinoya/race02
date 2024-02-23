#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(1);
    }

    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    int height = 0, width = 0;
    char c;

    // Calculate the width and height of the map
    while (read(fd, &c, 1) > 0) {
        if (c != ',' && c != '.' && c != '#' && c != '\n') {
            mx_printerr("map error\n");
            exit(1);
        }
        if (c == ',') {
            continue;
        } else if (c == '\n') {
            if (width == 0) {
                width = height > 0 ? width : height;
            }
            height++;
        }
        width++;
    }

    close(fd);

    // Reopen the file and read the map into a string
    char *fileContents = mx_file_to_str(argv[1], ',');

    // Check if x1, y1, x2, y2 are within the map boundaries
    if (x1 < 0 || x1 >= width || y1 < 0 || y1 >= height ||
        x2 < 0 || x2 >= width || y2 < 0 || y2 >= height) {
        mx_printerr("points are out of map range\n");
        free(fileContents);
        exit(1);
    }

    // Check if the entry point (x1, y1) and exit point (x2, y2) are obstacles
    if (fileContents[y1 * width + x1] == '#') {
        mx_printerr("entry point cannot be an obstacle\n");
        free(fileContents);
        exit(1);
    }

    if (fileContents[y2 * width + x2] == '#') {
        mx_printerr("exit point cannot be an obstacle\n");
        free(fileContents);
        exit(1);
    }

    // Initialize map with parsed data
    Map *map = malloc(sizeof(Map));
    map->width = width;
    map->height = height;
    map->dots = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        map->dots[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            if (fileContents[i * width + j] == '#') {
                map->dots[i][j] = -1; // Mark obstacle on the map
            } else if (fileContents[i * width + j] == '.') {
                map->dots[i][j] = -2; // Empty space
            }
        }
    }

    // Calculate the shortest paths
    calculate_distant_point(map, x1, y1);
    calculate_exit_path(map, x1, y1, x2, y2);

    // Save the map and path to the file path.txt
    save_map_and_path(map, "path.txt");

    // Free allocated memory
    free(fileContents);
    for (int i = 0; i < height; i++) {
        free(map->dots[i]);
    }
    free(map->dots);
    free(map);

    return 0;
}
