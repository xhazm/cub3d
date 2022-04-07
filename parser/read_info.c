#include "parser.h"

static char **fill_raw_read(int fd, char **raw_read, int rows)
{
	int		x;
	char 	*line;

	x = 0;
	line = NULL;
	while (x < rows)
	{
		line = get_next_line(fd, 5);
		if (line != NULL)
		{
			printf(" GET LINE %s\n", line);
			// raw_read[x] = ft_strdup(line);
			raw_read[x] = line;
			// write(2, raw_read[x], ft_strlen(raw_read[x]));
			// free(line);
			// line = NULL;
		}
		x++;
	}
	raw_read[x] = NULL;
	int i = 0;
	while (raw_read[i])
	{
		write(2, raw_read[i], ft_strlen(raw_read[i]));
		i++;
	}
	return (raw_read);
}

static int	get_info_size(char **argv, t_map *map_info)
{
	int		rows;
	char	*str;

	rows = 0;
	str = get_next_line(map_info->fd, 5);
	while (str != NULL)
	{
		rows++;
		free(str);
		str = NULL;
		str = get_next_line(map_info->fd, 5);
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
	raw_read = malloc((rows + 1) * sizeof(char*));
	if (raw_read == NULL)
		return(ft_error("malloc Error"));
	raw_read = fill_raw_read(map_info->fd, raw_read, rows);
	if (get_informations(map_info, raw_read) < 0)
		return (-1);
	return (0);
}
