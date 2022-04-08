#include "parser.h"

static void	init_map_info(t_map *map_info)
{
	map_info->map = NULL;
	map_info->no_path = NULL;
	map_info->so_path = NULL;
	map_info->we_path = NULL;
	map_info->ea_path = NULL;
	map_info->floor_color = NULL;
	map_info->ceilling_color = NULL;
	map_info->width = 0;
	map_info->height = 0;
	map_info->pl_dir = 'x';
	map_info->fd = -1;
}

int	open_map(char **argv, t_map *map_info)
{
	char	*path;

	path = argv[1];
	map_info->fd = open(path, O_RDONLY);
	if (map_info->fd < 0)
		return (ft_error("Error reading file"));
	return (0);
}

int	parser(int argc, char **argv, t_map *map_info)
{
	if (argc != 2)
	{
		printf("Wrong number of args\n");
		return (-1);
	}
	init_map_info(map_info);
	if (open_map(argv, map_info) < 0)
		return (-1);
	if (read_info(argv, map_info) < 0)
		return (-1);
	printf("Valid map\n");
	print_info(map_info);
	return (0);
}
