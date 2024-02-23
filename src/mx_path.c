#include "../inc/header.h"

bool path_of_stars(int **grid, int ax, int ay, int bx, int by, size map_size, int *len, int *pathX, int *pathY) {
    const int DIRECTIONS_X[4] = {-1, 0, 1, 0};
    const int DIRECTIONS_Y[4] = {0, -1, 0, 1};

    if (grid[ay][ax] == -1) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(1);
    }

    if (grid[by][bx] == -1) {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(1);
    }

    int d = 0;
    grid[ay][ax] = 0;

    while (true) {
        bool stop = true;

        for (int y = 0; y < map_size.row; ++y) {
            for (int x = 0; x < map_size.col; ++x) {
                if (grid[y][x] == d) {
                    for (int k = 0; k < 4; ++k) {
                        int iy = y + DIRECTIONS_Y[k], ix = x + DIRECTIONS_X[k];

                        if (iy >= 0 && iy < map_size.row && ix >= 0 && ix < map_size.col && grid[iy][ix] == -2) {
                            stop = false;
                            grid[iy][ix] = d + 1;
                        }
                    }
                }
            }
        }

        d++;

        if (stop || grid[by][bx] != -2) {
            break;
        }
    }

    if (grid[by][bx] == -2) {
        return false;
    }

    *len = grid[by][bx];
    int x = bx;
    int y = by;
    d = *len;

    while (d > 0) {
        pathX[d] = x;
        pathY[d] = y;
        d--;

        for (int k = 0; k < 4; ++k) {
            int iy = y + DIRECTIONS_Y[k], ix = x + DIRECTIONS_X[k];

            if (iy >= 0 && iy < map_size.row && ix >= 0 && ix < map_size.col && grid[iy][ix] == d) {
                x = x + DIRECTIONS_X[k];
                y = y + DIRECTIONS_Y[k];
                break;
            }
        }
    }

    pathX[0] = ax;
    pathY[0] = ay;

    return true;
}
