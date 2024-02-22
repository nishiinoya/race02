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

    // err if x1,y1 = '#' mx_printerr("entry point cannot be an obstacle");
    // err if x2,y2 = '#' mx_printerr("exit point cannot be an obstacle");
    // err : mx_printerr("route not found");
    // err out of range mx_printerr("points are out of map range");


    //we need to add a func that open a file and checks a chars inside 
    
}
