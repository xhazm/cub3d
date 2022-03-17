/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_general.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:40:04 by lpfleide          #+#    #+#             */
/*   Updated: 2021/10/11 13:06:35 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_usitoa(unsigned int a, int countonly)
{
	char	c;
	int		i;

	i = 0;
	if (a > 10)
		i += ft_usitoa(a / 10, countonly);
	c = a % 10;
	if (!countonly)
	{
		c += 48;
		write(1, &c, 1);
	}
	return (i);
}

int	ft_countitoa(long a)
{
	long	i;

	i = 0;
	if (a == 0)
		i++;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

int	ft_checkzero(t_var *var, long istr)
{
	if (var->precision == 0 && istr == 0)
	{
		var->length--;
		if (var->width >= 0)
			ft_widthwriter(var, var->length);
		return (1);
	}
	else
		return (0);
}

int	ft_intminus(t_var *var, long istr)
{
	if (istr < 0)
	{
		if (var->flagzero != 2)
		{
			if (var->flagzero != 0)
			{
				write(1, "-", 1);
				var->chars++;
			}
			if (var->flagzero != 0)
				var->flagzero = 2;
		}
		if (var->flagzero == 0)
			var->flagzero = -1;
		if (var->flagzero != 1 && var->flagzero != -1)
			ft_insertp(var, var->length);
		return (-1);
	}
	return (1);
}

char	*ft_checkzerostr(t_var *var, char *cstr)
{
	if (cstr == 0)
		cstr = "(null)";
	if (cstr[0] == 0)
		var->precision = -1;
	return (cstr);
}
