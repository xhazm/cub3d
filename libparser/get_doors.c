/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_doors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:10:05 by elenz             #+#    #+#             */
/*   Updated: 2022/04/08 18:49:58 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_T(char **map, int x, int y)
{
	if ((ft_strchr("10T", map[y - 1][x]) == 0)
	|| (ft_strchr("10T", map[y + 1][x]) == 0)
	|| (ft_strchr("10T", map[y][x + 1]) == 0)
	|| (ft_strchr("10T", map[y][x - 1]) == 0)
	|| (ft_strchr("10T", map[y - 1][x - 1]) == 0)
	|| (ft_strchr("10T", map[y - 1][x + 1]) == 0)
	|| (ft_strchr("10T", map[y + 1][x -1]) == 0)
	|| (ft_strchr("10T", map[y + 1][x + 1]) == 0))
		return (-1);
	return (0);
}
