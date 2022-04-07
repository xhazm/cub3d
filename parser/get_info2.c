#include "parser.h"

static int assign_str(t_map *map_info, int type, char **sp_line)
{
	if (sp_line[2] != NULL)
	{
		ft_free2darr((void **) sp_line);
		//ft_free_2d((void ***) &sp_line);
		return(ft_error("To many args in map"));
	}
	if (type == NO)
		map_info->no_path = ft_strdup(sp_line[1]);
	if (type == SO)
		map_info->so_path = ft_strdup(sp_line[1]);
	if (type == WE)
		map_info->we_path = ft_strdup(sp_line[1]);
	if (type == EA)
		map_info->ea_path = ft_strdup(sp_line[1]);
	if (type == F)
		map_info->floor_color = ft_strdup(sp_line[1]);
	if (type == C)
		map_info->ceilling_color = ft_strdup(sp_line[1]);
	//ft_free_2d((void ***) &sp_line);
	ft_free2darr((void **) sp_line);
	return (type);
}

int get_map_size(t_map *map_info, int *x, char **raw_read)
{
	static int	map_flag = 0;
	int			i;
	char		*str;

	map_info->first_row_map = *x;
	if (map_flag == 1)
		return (ft_error("Invalid Map"));
	while (raw_read[*x])
	{
		i = 0;
		str = raw_read[*x];
		while (check_spaces(str[i]))
			i++;
		if (str[i] != '1')
			break ;
		if (ft_strlen(str) > (size_t) map_info->width)
			map_info->width = ft_strlen(str);
		map_info->height += 1;
		(*x)++;
	}
	map_flag = 1;
	return (0);
}

int get_type(t_map *map_info, char **sp_line)
{
	printf("SPLINE %s\n", sp_line[0]);
	if (ft_strncmp(sp_line[0], "NO", 2) == 0 && map_info->no_path == NULL)
		return (assign_str(map_info, NO, sp_line));
	else if (ft_strncmp(sp_line[0], "SO", 2) == 0 && map_info->so_path == NULL)
		return (assign_str(map_info, SO, sp_line));
	else if (ft_strncmp(sp_line[0], "WE", 2) == 0 && map_info->we_path == NULL)
		return (assign_str(map_info, WE, sp_line));
	else if (ft_strncmp(sp_line[0], "EA", 2) == 0 && map_info->ea_path == NULL)
		return (assign_str(map_info, EA, sp_line));
	else if (ft_strncmp(sp_line[0], "C", 2) == 0 && map_info->ceilling_color == NULL)
		return (assign_str(map_info, C, sp_line));
	else if (ft_strncmp(sp_line[0], "F", 1) == 0 && map_info->floor_color == NULL)
		return (assign_str(map_info, F, sp_line));
	else if (sp_line[0][0] == '1')
	{
		ft_free2darr((void **) sp_line);
		return (MAP);
	}
	ft_free2darr((void **) sp_line);
	return (ft_error("Invalid map"));
}