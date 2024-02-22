#include "../inc/header.h"

void error_handling(int map, char *argv[]){
    if (map < 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    // err if x1,y1 = '#' mx_printerr("entry point cannot be an obstacle");
    // err if x2,y2 = '#' mx_printerr("exit point cannot be an obstacle");
    // err : mx_printerr("route not found");
    // err out of range mx_printerr("points are out of map range");
}
