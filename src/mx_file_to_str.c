#include "../inc/header.h"

char *mx_file_to_str(const char *filename) 
{
    int size = 0;
    char c;

    if (filename == NULL)
         return NULL;
    
    int fileToOpen = open(filename, O_RDONLY);
    if (fileToOpen < 0)
         return NULL;

    while (read(fileToOpen, &c, 1))
        size++;
    
    close(fileToOpen);
    
    fileToOpen = open(filename, O_RDONLY);
    if (fileToOpen < 0)
         return NULL;
    
    char *str = mx_strnew(size);

    for (int i = 0; read(fileToOpen, &c, 1); i++) 
        str[i] = c;
    
    close(fileToOpen);
    return str;
}
