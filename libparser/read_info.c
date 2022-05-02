/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:44:57 by elenz             #+#    #+#             */
/*   Updated: 2022/05/02 20:23:08 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Fills the information from the input file to the allocated space 
 */
static char	**fill_raw_read(int fd, char **raw_read, int rows)
{
	int		x;
	char	*line;

	x = 0;
	line = NULL;
	while (x < rows)
	{
		line = get_next_line(fd, 5);
		if (line != NULL)
			raw_read[x] = line;
		x++;
	}
	raw_read[x] = NULL;
	return (raw_read);
}

/* 
** Checks for the total numbers of rows for later allocation
 */
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

/* 
** Get all the information out of the map
 */
int	read_info(char **argv, t_map *map_info)
{
	int		rows;
	char	**raw_read;

	rows = get_info_size(argv, map_info);
	if (rows == 0)
		return (ft_error("Empty Map"));
	raw_read = malloc((rows + 1) * sizeof(char *));
	if (raw_read == NULL)
		return (ft_error("malloc Error"));
	raw_read = fill_raw_read(map_info->fd, raw_read, rows);
	if (get_informations(map_info, raw_read) < 0)
		return (-1);
	return (0);
}
