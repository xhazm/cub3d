/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:31:30 by lpfleide          #+#    #+#             */
/*   Updated: 2021/08/26 14:42:24 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(unsigned long istr, int uc, int countonly)
{
	int		i;
	char	c;

	i = 1;
	if (istr > 15)
		i += ft_hex(istr / 16, uc, countonly);
	c = istr % 16;
	if (!countonly)
	{
		if (c < 10)
			c += 48;
		else if (uc == 'X')
			c += 55;
		else
			c += 87;
		write(1, &c, 1);
	}
	return (i);
}

static void	ft_hasher(t_var *var, int upperlower, int decrement)
{
	if (var->length && !decrement)
	{
		if (upperlower == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		var->width -= 2;
		var->chars += 2;
	}
	var->flaghash *= 2;
	if (var->precision >= 0)
		ft_insertp(var, var->length);
}

void	ft_printptr(t_var *var, char *str)
{
	unsigned long	istr;

	istr = va_arg(var->args, unsigned long);
	var->length = ft_hex(istr, 1, 1);
	if (!istr)
		var->length--;
	if ((var->flagzero || var->flagminus) && !istr)
		var->width = 0;
	if (var->precision >= 0 && var->length >= var->precision)
		var->precision = 0;
	else
		var->precision -= var->length;
	var->length += 2;
	if (var->width == 0 && var->precision)
		var->width = var->precision;
	if (var->precision >= 0 && !var->flaghash)
		ft_insertp(var, var->length);
	if (var->width && !var->flagminus)
		ft_insertflag(var, var->length);
	ft_hasher(var, str[0], 0);
	var->length = ft_hex(istr, str[0], 0);
	var->chars += var->length;
	if (var->flagminus && var->width)
		ft_widthwriter(var, var->length);
}

void	ft_printhex(t_var *var, char *str)
{
	unsigned int	istr;

	istr = va_arg(var->args, unsigned int);
	if (ft_checkzero(var, istr))
		return ;
	var->length = ft_hex(istr, 1, 1);
	if ((var->flagzero || var->flagminus) && !istr)
		var->width = 0;
	if (var->precision >= 0 && var->length >= var->precision)
		var->precision = 0;
	else
		var->precision -= var->length;
	if (var->flaghash && istr)
		var->length += 2;
	if (var->precision >= 0)
		ft_insertp(var, var->length);
	if (var->width && !var->flagminus)
		ft_insertflag(var, var->length);
	if (var->flaghash && istr)
		ft_hasher(var, str[0], 0);
	var->chars += ft_hex(istr, str[0], 0);
	if (var->flagminus && var->width)
		ft_widthwriter(var, var->length);
}
