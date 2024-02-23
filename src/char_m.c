#include "../inc/header.h"

char **char_matrix(char *res, size *matrix_size) {
    int i;
    int width = 0;
    int height = 0;

    for (i = 0; res[i] != '\0'; ++i) {
        if (res[i] == '\n') {
            ++height;
        }
    }
    width = (i - height) / height;

    char **mat = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        mat[i] = (char *)malloc(width * sizeof(char));
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0) {
                if (res[j] == '#') {
                    mat[i][j] = '#';
                } else if (res[j] == '.') {
                    mat[i][j] = '.';
                } else if (res[j] != ',' && res[j] != '\n') {
                    mx_printerr("map error\n");
                    exit(0);
                }
            } else {
                if (res[j + i * (width + 1)] == '#') {
                    mat[i][j] = '#';
                } else if (res[j + i * (width + 1)] == '.') {
                    mat[i][j] = '.';
                } else if (res[j + i * (width + 1)] != ',' && res[j + i * (width + 1)] != '\n') {
                    mx_printerr("map error\n");
                    exit(0);
                }
            }
        }
    }

    matrix_size->col = width;
    matrix_size->row = height;

    return mat;
}
