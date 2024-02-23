#include "../inc/header.h"

int **matrix(char *res, size *matrix_size) {
    int i;
    int width = 0;
    int height = 0;

    // Calculate size
    for (i = 0; res[i] != '\0'; ++i) {
        if (res[i] == '\n') {
            ++height;
        }
    }

    width = (i - height) / height;

    // Allocate memory for rows
    int **mat = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        mat[i] = (int *)malloc(width * sizeof(int));
    }

    // Populate the matrix
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0) {
                if (res[j] == '#') {
                    mat[i][j] = -1;
                } else if (res[j] == '.') {
                    mat[i][j] = -2;
                } else if (res[j] != ',' && res[j] != '\n') {
                    mx_printerr("map error\n");
                    exit(1);
                }
            } else {
                if (res[j + i * (width + 1)] == '#') {
                    mat[i][j] = -1;
                } else if (res[j + i * (width + 1)] == '.') {
                    mat[i][j] = -2;
                } else if (res[j + i * (width + 1)] != ',' && res[j + i * (width + 1)] != '\n') {
                    mx_printerr("map error\n");
                    exit(1);
                }
            }
        }
    }

    matrix_size->col = width;
    matrix_size->row = height;

    return mat;
}
