#include "../inc/header.h"

void mx_lees_alghoritm(Map **map, int x, int y, int n)
{
	if(x < 0 || x >= (*map)->width || y < 0 || y >= (*map)->height)
		return;

	if((*map)->dots[y][x] == -2)
		return;
	
	if((*map)->dots[y][x] == -1)
		(*map)->dots[y][x] = n;
	
	if(y + 1 < (*map)->height)
		if((*map)->dots[y + 1][x] == -1 || (*map)->dots[y + 1][x] > n + 1)
			(*map)->dots[y + 1][x] = n + 1;
		
	if(y - 1 >= 0)
		if((*map)->dots[y - 1][x] == -1 || (*map)->dots[y - 1][x] > n + 1)
			(*map)->dots[y - 1][x] = n + 1;
		
	if(x + 1 < (*map)->width)
		if((*map)->dots[y][x + 1] == -1 || (*map)->dots[y][x + 1] > n + 1)
			(*map)->dots[y][x + 1] = n + 1;
		
	if(x - 1 >= 0)
		if((*map)->dots[y][x - 1] == -1 || (*map)->dots[y][x - 1] > n + 1)
			(*map)->dots[y][x - 1] = n + 1;
	
	if(y + 1 < (*map)->height)
		if((*map)->dots[y + 1][x] >= n + 1)
			mx_lees_alghoritm(map, x, y + 1, n + 1);
		
	if(y - 1 >= 0)
		if((*map)->dots[y - 1][x] >= n + 1)
			mx_lees_alghoritm(map, x, y - 1, n + 1);
	
	if(x + 1 < (*map)->width)
		if((*map)->dots[y][x + 1] >= n + 1)
			mx_lees_alghoritm(map, x + 1, y, n + 1);
		
	if(x - 1 >= 0)
		if((*map)->dots[y][x - 1] >= n + 1)
			mx_lees_alghoritm(map, x - 1, y, n + 1);
}
