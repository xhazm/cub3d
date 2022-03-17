/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:45:42 by lpfleide          #+#    #+#             */
/*   Updated: 2021/11/01 22:22:29 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convertstoi(const char *str, int numend, int base)
{
	int	num;
	int	tempbase;

	num = 0;
	tempbase = 1;
	while (numend >= 0)
	{
		if (str[numend] >= '0' && str[numend] <= '9')
			num += tempbase * (str[numend] - '0');
		if (str[numend] >= 'a' && str[numend] <= 'f')
			num += tempbase * (str[numend] - 'a' + 10);
		if (str[numend] >= 'A' && str[numend] <= 'F')
			num += tempbase * (str[numend] - 'A' + 10);
		tempbase *= base;
		numend--;
	}
	return (num);
}

int	ft_btoi(const char *str, int base)
{
	int	neg;
	int	numstart;
	int	numend;

	numstart = 0;
	numend = 0;
	neg = 1;
	while ((str[numstart] > 8 && str[numstart] < 14) || str[numstart] == 32)
		numstart++;
	if (str[numstart] == '-' || str[numstart] == '+')
	{
		if (str[numstart] == '-')
			neg = -1;
		numstart++;
	}
	if (str[numstart] == '0' && (str[numstart + 1] == 'x'
			|| str[numstart + 1] == 'X'))
		numstart += 2;
	while (ft_isalnum(str[numstart + numend]))
		numend++;
	numend--;
	return (neg * ft_convertstoi(&str[numstart], numend, base));
}
