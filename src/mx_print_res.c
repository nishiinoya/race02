#include "../inc/header.h"

void print_res(int **mat1, int x1, int y1, int row, int col, char **final, int len) {
    mx_printstr("dist=");
    mx_printint(mx_max(mat1, x1, y1, row, col, final));
    mx_printstr("\n");
    mx_printstr("exit=");
    mx_printint(len);
    mx_printstr("\n");
}
