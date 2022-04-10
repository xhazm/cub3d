#include "parser.h"

int	check_meta_info(t_map *m)
{
	if (m->ceiling_color == -1)
		return(-1);
	if (m->floor_color == -1)
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
