/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lastrow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:34:27 by elenz             #+#    #+#             */
/*   Updated: 2022/05/02 20:33:17 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_sign(t_map *map_info, char sign, int i)
{
	int	j;

	if (sign == ' ')
	{
		j = map_info->height - 1;
		while (j > 0)
		{
			if ((ft_strchr(" 1\0", map_info->map[j][i]) == 0)
				&& (ft_strchr(" 1\0", map_info->map[j][i]) == 0
				&& map_info->map[j][i] != '\n'))
				return (-1);
			if (map_info->map[j][i] == '1')
				return (0);
			j--;
		}
	}
	return (0);
}

/* 
** See documentation of check_first_row. Same procedure just upwards.
 */
int	check_last_row(t_map *map_info)
{
	char	*last;
	int		i;

	i = 0;
	last = map_info->map[map_info->height - 1];
	while (last[i])
	{
		if ((ft_strchr(" 1", last[i]) == 0)
			&& (ft_strchr(" 1", last[i]) == 0 && last[i] != '\n'))
			return (-1);
		if (check_sign(map_info, last[i], i) < 0)
			return (-1);
		i++;
	}
	return (0);
}
