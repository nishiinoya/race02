#include "../inc/header.h"

int mx_get_dot_dist(Map *map, int x, int y)
{
	return map->dots[y][x];
}