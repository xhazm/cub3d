/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_doors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:10:05 by elenz             #+#    #+#             */
/*   Updated: 2022/04/28 20:41:57 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_rabbit(void)
{
	static int	rabbit = 0;

	if (rabbit == 1)
		return (-1);
	rabbit = 1;
	return (0);
}

int	check_t(char **map, int x, int y, int sign)
{
	if (sign == 'R')
		if (check_rabbit() < 0)
			return (-1);
	if ((ft_strchr("10TR", map[y - 1][x]) == 0 || map[y - 1][x] == '\0')
	|| (ft_strchr("10TR", map[y + 1][x]) == 0 || map[y + 1][x] == '\0')
	|| (ft_strchr("10TR", map[y][x + 1]) == 0 || map[y][x + 1] == '\0')
	|| (ft_strchr("10TR", map[y][x - 1]) == 0 || map[y][x - 1] == '\0')
	|| (ft_strchr("10TR", map[y - 1][x - 1]) == 0 || map[y - 1][x - 1] == '\0')
	|| (ft_strchr("10TR", map[y - 1][x + 1]) == 0 || map[y - 1][x + 1] == '\0')
	|| (ft_strchr("10TR", map[y + 1][x -1]) == 0 || map[y + 1][x -1] == '\0')
	|| (ft_strchr("10TR", map[y + 1][x + 1]) == 0 || map[y + 1][x + 1] == '\0'))
		return (-1);
	return (0);
}
