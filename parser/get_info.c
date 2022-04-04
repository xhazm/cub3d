#include "parser.h"

static int	get_meta_info(t_map *map_info, char **raw_read)
{
	int		x;
	int		i;
	char	*str;
	int		type;

	x = 0;
	while(raw_read[x])
	{
		i = 0;
		str = raw_read[x];
		while (check_spaces(str[i]))
			i++;
		if (str[i] != '\n' && ft_strlen(str) != 0)
			type = get_type(map_info, ft_split(&str[i],' '));
		else
			type = EMPTY_LINE;
		if (type == -1)
			return (-1);
		if (type == MAP)
		{
			if (get_map_size(map_info, &x, raw_read) < 0)
				return (-1);
		}
		else
			x++;
	}
	return (0);
}

int get_informations(t_map *map_info, char **raw_read)
{
	if (get_meta_info(map_info, raw_read) < 0)
	{
		//ft_free_2d((void ***)&raw_read);
		return (-1);
	}
	if (check_meta_info(map_info) < 0)
		return (ft_error("Invalid map"));
	if (get_map(map_info, &raw_read[map_info->first_row_map]) < 0)
	{
		//ft_free_2d((void ***)&raw_read);
		//free map_info;
		return(-1);
	}
	//free raw_read;
	if (check_map(map_info) < 0)
	{
		//free map_info;
		return(-1);
	}
	print_map(map_info->map);
	print_info(map_info);
	return (0);
}