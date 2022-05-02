/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:46:03 by elenz             #+#    #+#             */
/*   Updated: 2022/05/02 21:30:41 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	init_map_info(t_map *map_info)
{
	map_info->map = NULL;
	map_info->no_path = NULL;
	map_info->so_path = NULL;
	map_info->we_path = NULL;
	map_info->ea_path = NULL;
	map_info->floor_color = INT32_MAX;
	map_info->ceiling_color = INT32_MAX;
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

void	char_to_nbr(t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_info->height)
	{
		x = 0;
		while (x < map_info->width)
		{
			if (ft_isdigit(map_info->map[y][x]))
				map_info->map[y][x] -= 48;
			else if (map_info->map[y][x] == 'N' || map_info->map[y][x] == 'E' ||
				map_info->map[y][x] == 'S' || map_info->map[y][x] == 'W')
				map_info->map[y][x] = 0;
			else if (map_info->map[y][x] == 'R')
				map_info->map[y][x] = - 'R';
			x++;
		}
		y++;
	}
}

/* 
** Parser for taking in the information of the input file and
** stores them in a struct
 */
int	parser(int argc, char **argv, t_map *map_info)
{
	if (argc != 2)
	{
		printf("Wrong number of args\n");
		return (FAIL);
	}
	init_map_info(map_info);
	if (open_map(argv, map_info) < 0)
		return (FAIL);
	if (read_info(argv, map_info) < 0)
		return (FAIL);
	char_to_nbr(map_info);
	printf("Valid map\n");
	return (SUCCESS);
}
