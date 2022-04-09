#include "parser.h"

void print_map(char **map, int height, t_map *map_info)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while(x < map_info->height)
	{
		y = 0;
		while(y < map_info->width)
		{
			if (map[x][y] <= 9 && map[x][y] >= 0)
				printf("%d",map[x][y]);
			else
				printf("%c",map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}

void print_info(t_map *m)
{
	printf( "PARSED INFO: \n\
		pl_dir: %c\n \
		pl_x: %f \n\
		pl_y: %f \n\
		ceilingcolor: %s\n \
		floorcolor: %s\n \
		no: %s\n \
		so: %s \n \
		we: %s\n \
		ea: %s\n \
		heightmap: %d\n \
		widthmap: %d\n", m->pl_dir, m->pl_x, m->pl_y, m->ceilling_color, m->floor_color, m->no_path,
		m->so_path, m->we_path, m->ea_path, m->height, m->width);
}

int	ft_error(char *msg)
{
	printf("%s\n", msg);
	return (-1);
}

int check_spaces(char c)
{
	if (c == ' ' || c == '	')
		return(1);
	return(0);
}

static void free_paths(t_map *map_info)
{
	if (map_info->no_path)
	{
		free(map_info->no_path);
		map_info->no_path = NULL;
	}
	if (map_info->so_path)
	{
		free(map_info->so_path);
		map_info->so_path = NULL;
	}
	if (map_info->we_path)
	{
		free(map_info->we_path);
		map_info->we_path = NULL;
	}
	if (map_info->ea_path)
	{
		free(map_info->ea_path);
		map_info->ea_path = NULL;
	}
}

void ft_free_map_info(t_map *map_info)
{
	free_paths(map_info);
	if (map_info->ceilling_color)
	{
		free(map_info->ceilling_color);
		map_info->ceilling_color = NULL;
	}
	if (map_info->floor_color)
	{
		free(map_info->floor_color);
		map_info->floor_color = NULL;
	}
	if (map_info->map)
		ft_free2darr((void **) map_info->map);
}
