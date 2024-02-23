#include "../inc/header.h"

int mx_get_max_dist(Map *map)
{
    int max_num = 0;

	for(int i = 0; i < map->height; i++)
    {
		for(int j = 0; j < map->width; j++)
        {
			if(map->dots[i][j] > max_num)
				max_num = map->dots[i][j];
        }
    }
	return max_num;
}
