#include <stdlib.h>
#include <stdio.h>
#include "flood_fill.h"

void	fill_region(char **tab, t_point size, t_point current, char to_fill)
{
	// check if the current point is out of bound
	if (current.x < 0 || current.x >= size.x || current.y < 0 || current.y >= size.y)
		return;
	// check if the current cell is not the area to fill
	if (tab[current.y][current.x] != to_fill)
		return;
	// fill the area, and recursively
	tab[current.y][current.x] = 'F';
	fill_region(tab, size, (t_point){current.x - 1, current.y}, to_fill);
	fill_region(tab, size, (t_point){current.x + 1, current.y}, to_fill);
	fill_region(tab, size, (t_point){current.x, current.y - 1}, to_fill);
	fill_region(tab, size, (t_point){current.x, current.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	to_fill;

	// get the char at the starting point
	to_fill = tab[begin.y][begin.x];
	// call the recursive function
	fill_region(tab, size, begin, to_fill);
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
