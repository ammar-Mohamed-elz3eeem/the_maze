#include "game.h"

int *parse_map(char *filename, int *map)
{
	FILE *fp;
	char row[MAP_WIDTH * 2];
	char *number;
	int i, j;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Map File couldn't be opened");
		return (NULL);
	}

	map = malloc(sizeof(int) * MAP_WIDTH * MAP_HEIGHT);
	if (map == NULL)
		return (NULL);
	
	i = 0;
	while (fgets(row, sizeof(row), fp) != NULL)
	{
		if (strlen(row) <= 1)
			continue;
		
		number = strtok(row, "\n ");

		j = 0;
		while (number != NULL)
		{
			map[i * MAP_WIDTH + j] = atoi(number);
			number = strtok(NULL, "\n ");
			j++;
		}
		i++;
	}
	fclose(fp);
	return (map);
}
