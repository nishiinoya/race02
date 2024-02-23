#include "../inc/header.h"
// breadth-first search (BFS) algorithm
int mx_max(int **grid, int ax, int ay, int He, int Wi, char **final) {
    const int MAX_DIRECTIONS = 4;
    const int dx[MAX_DIRECTIONS] = {1, 0, -1, 0};
    const int dy[MAX_DIRECTIONS] = {0, 1, 0, -1};

    int d, x, y, k;
    bool stop = false;
    int max_distan;
    int flag = 1;

    // in. distances and mark the starting point
    d = 0;
    grid[ay][ax] = 0;

    // BFS loop
    while (!stop || flag) {
        stop = true;

        for (y = 0; y < He; ++y) {
            for (x = 0; x < Wi; ++x) {
                if (grid[y][x] == d) {
                    for (k = 0; k < MAX_DIRECTIONS; ++k) {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 && iy < He && ix >= 0 && ix < Wi &&
                            grid[iy][ix] == -2) {
                            stop = false;
                            grid[iy][ix] = d + 1;
                        }
                    }
                }
            }
        }

        d++;
        flag = 0;
    }

    // Find the maximum distance in the grid
    max_distan = grid[0][0];
    for (int i = 0; i < He; ++i) {
        for (int j = 0; j < Wi; ++j) {
            if (grid[i][j] > max_distan)
                max_distan = grid[i][j];
        }
    }

    // Update the final array based on the maximum distance
    for (int i = 0; i < He; ++i) {
        for (int j = 0; j < Wi; ++j) {
            if (grid[i][j] == max_distan) {
                final[i][j] = (final[i][j] == '*') ? 'X' : 'D';
            }
        }
    }

    return max_distan;
}
