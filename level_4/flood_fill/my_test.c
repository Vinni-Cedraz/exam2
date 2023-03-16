
#include "flood_fill.h"
#include "my_flood_fill.c"
// #include "recursive_flood_fill.c"
#include <stdio.h>
#include <stdlib.h>

char	**make_area(char **zone, t_point size)
{
	char	**new;

	new = malloc(sizeof(char *) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}
	return (new);
}

int	main(int argc, char **argv)
{
	char	**area;
	t_point size = (t_point){8, 5};

	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	(void)argc;
	area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
	t_point begin = {.x = atoi(argv[2]), .y = atoi(argv[1])};
	my_flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
