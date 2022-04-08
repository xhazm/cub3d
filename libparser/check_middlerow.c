#include "parser.h"

static int	check_pl(t_map *map_info, char **map, int x, int y)
{
	if (map_info->pl_dir != 'x')
		return (-1);
	map_info->pl_dir = map[y][x];
	map_info->pl_x = x;
	map_info->pl_y = y;
	if ((ft_strchr("10T", map[y - 1][x]) == 0)
	|| (ft_strchr("10T", map[y + 1][x]) == 0)
	|| (ft_strchr("10T", map[y][x + 1]) == 0)
	|| (ft_strchr("10T", map[y][x - 1]) == 0)
	|| (ft_strchr("10T", map[y - 1][x - 1]) == 0)
	|| (ft_strchr("10T", map[y - 1][x + 1]) == 0)
	|| (ft_strchr("10T", map[y + 1][x -1]) == 0)
	|| (ft_strchr("10T", map[y + 1][x + 1]) == 0))
		return (-1);
	return (0);
}

static int	check_zero(char **map, int x, int y)
{
	if ((ft_strchr("10NSWET", map[y - 1][x]) == 0)
	|| (ft_strchr("10NSWET", map[y + 1][x]) == 0)
	|| (ft_strchr("10NSWET", map[y][x + 1]) == 0)
	|| (ft_strchr("10NSWET", map[y][x - 1]) == 0)
	|| (ft_strchr("10NSWET", map[y - 1][x - 1]) == 0)
	|| (ft_strchr("10NSWET", map[y - 1][x + 1]) == 0)
	|| (ft_strchr("10NSWET", map[y + 1][x -1]) == 0)
	|| (ft_strchr("10NSWET", map[y + 1][x + 1]) == 0))
		return (-1);
	return (0);
}

static int check_sign(t_map *map_info, char *row, int y)
{
	int	x;

	x = 0;
	while(row[x])
	{
		if (row[x] == '0')
		{
			if (check_zero(map_info->map, x, y) < 0)
			{
				(printf("FEHLER ORT %i %i\n", x,y)); // TODO RAUSNEHMEN
				return (-1);
			}
		}
		if (ft_strchr("NSWE", row[x]) != 0)
			if (check_pl(map_info, map_info->map, x, y) < 0)
				return (-1); 
		if (row[x] == 'T')
			if (check_T(map_info->map, x, y) < 0)
				return (-1); 
		x++;
	}
	return (0);
}

int	check_middle_rows(t_map *map_info)
{
	int		y;
	char	*row;

	y = 1;
	while (y < map_info->height - 1)
	{
		row = map_info->map[y];
		if (check_sign(map_info, row, y) < 0)
			return (-1);
		y++;
	}
	return (0);
}
