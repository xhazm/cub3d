/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:44:33 by elenz             #+#    #+#             */
/*   Updated: 2022/05/01 19:24:48 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_free2dmap(char **arr, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (0);
}

int	ft_error(char *msg)
{
	printf("%s\n", msg);
	return (-1);
}

int	check_spaces(char c)
{
	if (c == ' ' || c == '	')
		return (1);
	return (0);
}

static void	free_paths(t_map *map_info)
{
	if (map_info->no_path != NULL)
	{
		free(map_info->no_path);
		map_info->no_path = NULL;
	}
	if (map_info->so_path != NULL)
	{
		free(map_info->so_path);
		map_info->so_path = NULL;
	}
	if (map_info->we_path != NULL)
	{
		free(map_info->we_path);
		map_info->we_path = NULL;
	}
	if (map_info->ea_path != NULL)
	{
		free(map_info->ea_path);
		map_info->ea_path = NULL;
	}
}

void	ft_free_map_info(t_map *map_info)
{
	free_paths(map_info);
	if (map_info->map)
		ft_free2dmap(map_info->map, map_info->height);
}
