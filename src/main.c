#include "../inc/header.h"

int main(int argc, char const *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(1);
    }

    int source_file = open(argv[1], O_RDONLY);
    if (source_file < 0) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    char s[1];
    int n = read(source_file, s, 4);
    if (n <= 0) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    size map_size;
    int x1, x2, y1, y2;

    // Extract map size and coordinates
    char *file_string = mx_file_to_str(argv[1]);
    int **mat = matrix(file_string, &map_size);
    char **final = char_matrix(file_string, &map_size);
    int **mat_1 = matrix(file_string, &map_size);

    x1 = mx_atoi(argv[2]);
    x2 = mx_atoi(argv[4]);
    y1 = mx_atoi(argv[3]);
    y2 = mx_atoi(argv[5]);

    if (x1 >= map_size.col || x2 >= map_size.col || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || y1 >= map_size.row || y2 >= map_size.row) {
        mx_printerr("points are out of map range\n");
        exit(1);
    }

    int px[map_size.row * map_size.col], py[map_size.row * map_size.col];
    int length;

    if (!path_of_stars(mat, x1, y1, x2, y2, map_size, &length, px, py)) {
        mx_printerr("route not found\n");
        exit(1);
    }

    int file1 = open("path.txt", O_WRONLY);
    if (file1 < 0)
        file1 = open("path.txt", O_CREAT | O_WRONLY);

    for (int i = 0; i < length; ++i) {
        final[py[i]][px[i]] = '*';
    }

    final[y2][x2] = '*';
    mx_max(mat_1, x1, y1, map_size.row, map_size.col, final);

    for (int i = 0; i < map_size.row; ++i) {
        for (int j = 0; j < map_size.col; ++j) {
            char s = final[i][j];
            write(file1, &s, 1);
        }
        write(file1, "\n", 1);
    }

    if (close(file1) < 0) {
        mx_printerr("error\n");
        exit(1);
    }

    print_res(mat_1, x1, y1, map_size.row, map_size.col, final, length);

    return 0;
}
