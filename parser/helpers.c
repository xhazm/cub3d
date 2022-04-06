#include "parser.h"

void print_map(char **map, int height)
{
	int x;

	x = 0;
	while(x < height)
	{
		printf("%s",map[x]);
		x++;
	}
}

void print_info(t_map *m)
{
	printf( "	pl_dir: %c\n \
		ceilingcolor: %s\n \
		floorcolor: %s\n \
		no: %s\n \
		so: %s \n \
		we: %s\n \
		ea: %s\n \
		heightmap: %d\n \
		widthmap: %d\n", m->pl_dir, m->ceilling_color, m->floor_color, m->no_path,
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
