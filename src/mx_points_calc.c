#include "../inc/header.h"

// Function to calculate the shortest path to the most distant point (X or D)
void calculate_distant_point(Map *map, int x1, int y1) {
    mx_lees_alghoritm(&map, x1, y1, 0);

    // Find the most distant point
    int max_dist = 0;
    int max_x = -1, max_y = -1;
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            if (map->dots[y][x] > max_dist) {
                max_dist = map->dots[y][x];
                max_x = x;
                max_y = y;
            }
        }
    }

    // Print the number of movements to the most distant point
    mx_printstr("dist=");
    mx_printint(max_dist);
    mx_printchar('\n');

    // Mark the most distant point on the map
    if (max_x != -1 && max_y != -1) {
        map->dots[max_y][max_x] = -3; // Assuming -3 represents 'X' on the map
    }
}

// Function to calculate the shortest path to the exit point
void calculate_exit_path(Map *map, int x1, int y1, int x2, int y2) {
    mx_lees_alghoritm(&map, x1, y1, 0);

    // Print the number of movements to the exit point
    mx_printstr("exit=");
    mx_printint(map->dots[y2][x2]);
    mx_printchar('\n');

    // Mark the exit point on the map
    map->dots[y2][x2] = -3; // Assuming -3 represents 'D' on the map
}

// Function to save the map and path to the file path.txt
void save_map_and_path(Map *map, char *filename) {
    int file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (file < 0) {
        mx_printerr("error\n");
        exit(1);
    }

    // Write the map and path to the file
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            if (map->dots[y][x] == -3) {
                write(file, "D", 1);
            } else if (map->dots[y][x] == -2) {
                write(file, "*", 1);
            } else if (map->dots[y][x] == -1) {
                write(file, "#", 1);
            } else {
                write(file, ".", 1);
            }
        }
        write(file, "\n", 1);
    }

    if (close(file) < 0) {
        mx_printerr("error\n");
        exit(1);
    }
}

