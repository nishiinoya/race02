#include "../inc/header.h"

char *mx_openAndReWrite_file(char *path)
{
	int file = open(argv[1], O_RDWR);
    if(file < 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
	char buf;
	int ref;

	char *result = mx_strnew(0);
	while ((ref = read(file, &buf, 1)) > 0) 
	{
		if (ref < 0)
		{
			mx_printerr("map does not exist\n");
			exit(0);
		}
		if(buf != '#' && buf != '.' && buf != ',' && buf != '\n' && buf != '\r')
		{
			mx_printerr("map error\n");
			exit(0);
		}
		if(buf != '\r')
			result = mx_str_add(result, buf);
	}
	
    if(close(file) < 0) {
        mx_printerr("error\n");
        exit(0);
    }

	return result;
}
