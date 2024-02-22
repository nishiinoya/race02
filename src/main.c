#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(0);
    }

    int x1 = mx_atoi(argv[2]);
	int y1 = mx_atoi(argv[3]);
	int x2 = mx_atoi(argv[4]);
	int y2 = mx_atoi(argv[5]);
    
    int map = open(argv[1], O_RDONLY);
    if (map < 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }


    char *str_file = mx_file_to_str(argv[1]);

    // we need to add a func that open a file and checks a chars inside
    if (close(map) < 0) {
        mx_printerr("error\n");
        exit(0);
    }
    return 0;
}
