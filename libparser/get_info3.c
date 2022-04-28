/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:43:18 by elenz             #+#    #+#             */
/*   Updated: 2022/04/28 17:44:16 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	assign_map(t_map *map_info, char *str, int row)
{
	int	i;

	i = 0;
	map_info->map[row] = ft_calloc(map_info->width + 1, sizeof(char *));
	if (map_info->map[row] == NULL)
		return (-1);
	while (str[i] && str[i] != '\n')
	{
		map_info->map[row][i] = str[i];
		i++;
	}
	return (0);
}

int	get_map(t_map *map_info, char **map_read)
{
	int		x;

	map_info->map = ft_calloc(map_info->height, sizeof(char *));
	if (map_info->map == NULL)
		return (ft_error("malloc Error"));
	x = 0;
	while (x < map_info->height)
	{
		if (assign_map(map_info, map_read[x], x) < 0)
			return (ft_error("malloc Error"));
		x++;
	}
	return (0);
}
