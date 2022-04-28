/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:35:54 by elenz             #+#    #+#             */
/*   Updated: 2022/04/28 17:35:55 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

unsigned int	ft_color_converter(char *cStr)
{
	int				i;
	char			**rgb;
	unsigned int	color;
	long int		temp_color;

	rgb = ft_split(cStr, ',');
	color = 0;
	temp_color = 0;
	i = 0;
	while (i < 3)
	{
		temp_color = ft_atoi(rgb[i]);
		if (temp_color > 255 || temp_color < 0)
			return (-1);
		color |= temp_color;
		if (i != 2)
			color = color << 8;
		i++;
	}
	ft_free2darr((void **)rgb);
	return (color);
}
