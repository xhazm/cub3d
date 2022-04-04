#include "parser.h"

static char **fill_raw_read(int fd, char **raw_read)
{
	int		x;
	char 	*line;

	x = 0;
	while (line != NULL)
	{
		line = get_next_line(fd, 5);
		raw_read[x] = ft_strdup(line);
		free(line);
		x++;
	}
	raw_read[x] = NULL;
	return (raw_read);
}

static int	get_info_size(char **argv, t_map *map_info)
{
	int		rows;
	char	*str;

	while (str != NULL)
	{
		str = get_next_line(map_info->fd, 5);
		free(str);
		rows++;
	}
	close(map_info->fd);
	if (open_map(argv, map_info) == -1)
		return (-1);
	return (rows);
}

int	read_info(char **argv, t_map *map_info)
{
	int		rows;
	char	**raw_read;

	rows = get_info_size(argv, map_info);
	if (rows == 0)
		return(ft_error("Empty Map"));
	raw_read = malloc(rows * sizeof(char*));
	if (raw_read == NULL)
		return(ft_error("malloc Error"));
	raw_read = fill_raw_read(map_info->fd, raw_read);
	if (get_informations(map_info, raw_read) < 0)
		return (-1);
	return (0);
}