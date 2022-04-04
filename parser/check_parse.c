#include "parser.h"

static int	check_rgb(char *str)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_split(str, ',');
	while (colors[i])
	{
		if (ft_atoi(colors[i]) > 255 || i > 2)
		{
			//free colors
			return (-1);
		}
		i++;
	}
	//free colors
	return (0);
}

int	check_meta_info(t_map *m)
{
	if (m->ceilling_color == NULL || check_rgb(m->ceilling_color) == -1)
		return(-1);
	if (m->floor_color == NULL || check_rgb(m->floor_color) == -1)
		return(-1);
	if(m->no_path == NULL || m->so_path == NULL || m->we_path == NULL
		|| m->ea_path == NULL)
		return(-1);
	return (0);
}

int	check_map(t_map *map_info)
{
	if (check_first_row(map_info) < 0)
		return(ft_error("Invalid map"));
	if (check_last_row(map_info) < 0)
		return(ft_error("Invalid map"));
	if (check_middle_rows(map_info) < 0)
		return(ft_error("Invalid map"));
	return (0);
}
