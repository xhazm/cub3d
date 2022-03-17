/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:11:20 by lpfleide          #+#    #+#             */
/*   Updated: 2022/01/12 15:27:00 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_max_min_int(char *src, int strlen, int sign)
{
	char	*check_int;
	int		i;

	i = 0;
	if (sign == '-')
		check_int = "2147483648";
	if (sign == '+')
		check_int = "2147483647";
	while (i < strlen)
	{
		if (src[i] > check_int[i])
			return (0);
		if (src[i] < check_int[i])
			return (1);
		i++;
	}
	return (1);
}

/* returns 1 if str is int */
int	ft_str_is_int(char	*src)
{
	int		strlen;
	int		check;

	strlen = ft_strlen(src);
	check = 0;
	if (ft_str_isnum(src) == 1)
	{
		if (strlen > 11 || (strlen == 11 && (src[0] != '-' && src[0] != '+')))
			return (0);
		if (strlen < 10 || (strlen == 10 && (src[0] == '-' || src[0] == '+')))
			return (1);
		if (src[0] == '-')
			check = ft_check_max_min_int(&src[1], strlen - 1, '-');
		else if (src[0] == '+')
			check = ft_check_max_min_int(&src[1], strlen - 1, '+');
		else
			check = ft_check_max_min_int(src, strlen, '+');
		return (check);
	}
	else
		return (0);
}
