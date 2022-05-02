/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_firstrow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:33:23 by elenz             #+#    #+#             */
/*   Updated: 2022/05/02 20:32:18 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** If the found sign is a space it checks downwoard if there is a 
**forbidden character (not space, 0, or 1)
*/
static int	check_sign(t_map *map_info, char sign, int i)
{
	int	j;

	if (sign == ' ')
	{
		j = 0;
		while (j < map_info->height)
		{
			if ((ft_strchr(" 1\0", map_info->map[j][i]) == 0)
			&& (ft_strchr(" 1\0", map_info->map[j][i]) == 0
				&& map_info->map[j][i] != '\n'))
				return (-1);
			if (map_info->map[j][i] == '1')
				return (0);
			j++;
		}
	}
	return (0);
}

/* 
** Checks the top-map-row if there is another number then 1 or space
 */
int	check_first_row(t_map *map_info)
{
	char	*first;
	int		i;

	i = 0;
	first = map_info->map[0];
	while (first[i])
	{
		if ((ft_strchr(" 1", first[i]) == 0)
			&& (ft_strchr(" 1", first[i]) == 0 && first[i] != '\n'))
			return (-1);
		if (check_sign(map_info, first[i], i) < 0)
			return (-1);
		i++;
	}
	return (0);
}
