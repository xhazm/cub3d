/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:35:06 by elenz             #+#    #+#             */
/*   Updated: 2022/05/02 20:29:24 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	path_exist(t_map *m)
{
	if (access(m->no_path, F_OK) != 0 || access(m->so_path, F_OK) != 0
		|| access(m->we_path, F_OK) != 0 || access(m->ea_path, F_OK) != 0)
		return (-1);
	return (0);
}

int	check_meta_info(t_map *m)
{
	if (m->ceiling_color == INT32_MAX)
		return (-1);
	if (m->floor_color == INT32_MAX)
		return (-1);
	if (path_exist(m) == -1
		|| m->no_path == NULL || m->so_path == NULL || m->we_path == NULL
		|| m->ea_path == NULL)
		return (-1);
	return (0);
}

/*
** Looking for invalid maps
*/
int	check_map(t_map *map_info)
{
	if (check_first_row(map_info) < 0)
		return (ft_error("Invalid map"));
	if (check_last_row(map_info) < 0)
		return (ft_error("Invalid map"));
	if (check_middle_rows(map_info) < 0)
		return (ft_error("Invalid map"));
	if (map_info->pl_dir == 'x')
		return (ft_error("Invalid map"));
	return (0);
}
