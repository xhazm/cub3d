/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_width_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:38:52 by lpfleide          #+#    #+#             */
/*   Updated: 2021/08/25 20:25:17 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_widthwriter(t_var *var, int len)
{
	while (len < var->width)
	{
		write(1, " ", 1);
		var->width--;
		var->chars++;
	}
}

void	ft_insertp(t_var *var, int len)
{
	int	i;

	i = var->width - var->precision;
	if (var->precision >= 0 && !var->flagminus)
	{
		while ((var->precision + len) < var->width)
		{
			write(1, " ", 1);
			var->width--;
			var->chars++;
		}
	}
	if ((var->precision >= 0 && (var->flagminus || var->flaghash == 2))
		|| (var->precision >= 0 && !var->width))
	{
		while (i < var->width)
		{
			write(1, "0", 1);
			var->width--;
			var->chars++;
		}
	}
}

void	ft_insertflag(t_var *var, int len)
{
	if (var->flaghash)
		ft_insertp(var, len);
	while (len + var->flaghash < var->width)
	{
		if (var->flagzero > 0 || var->precision >= 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		var->width--;
		var->chars++;
	}
}
