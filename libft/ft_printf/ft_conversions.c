/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:57:15 by lpfleide          #+#    #+#             */
/*   Updated: 2021/09/01 19:46:10 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(t_var *var)
{
	char	c;

	c = va_arg(var->args, int);
	if (c == 0)
		var->precision = -1;
	if (1 < var->precision)
		var->precision = 1;
	if (var->precision >= 0)
		ft_insertp(var, 1);
	if (var->width && !var->flagminus)
		ft_insertflag(var, 1);
	write(1, &c, 1);
	if (var->flagminus && var->width)
		ft_widthwriter(var, 1);
	var->chars++;
}

void	ft_printcharr(t_var *var)
{
	char	*cstr;

	cstr = va_arg(var->args, char *);
	if (cstr == 0 || cstr[0] == 0)
		cstr = ft_checkzerostr(var, cstr);
	var->length = ft_strlen(cstr);
	if (var->precision < var->length && !var->width
		&& var->precision != -1)
		var->length = var->precision;
	if ((var->precision >= 0 && var->precision < var->length)
		|| (var->precision >= var->length))
		var->precision = -1;
	if (var->precision >= 0)
	{
		ft_insertp(var, var->length);
		var->precision = -1;
	}
	if (var->width && !var->flagminus)
		ft_insertflag(var, var->length);
	write(1, cstr, var->length);
	var->chars += var->length;
	if (var->flagminus && var->width)
		ft_widthwriter(var, var->length);
}

void	ft_printint(t_var *var)
{
	long	istr;
	char	*cstr;

	istr = va_arg(var->args, int);
	var->length = ft_countitoa(istr);
	if (ft_checkzero(var, istr))
		return ;
	if (var->precision >= 0 && var->length >= var->precision)
		var->precision = 0;
	else
		var->precision -= var->length;
	if (istr >= 0)
		ft_insertp(var, var->length);
	if (istr < 0)
		var->length++;
	ft_intminus(var, istr);
	if (var->width && !var->flagminus)
		ft_insertflag(var, var->length);
	istr *= ft_intminus(var, istr);
	cstr = ft_itoa(istr);
	write(1, cstr, ft_strlen(cstr));
	if (var->flagminus && var->width)
		ft_widthwriter(var, var->length);
	var->chars += ft_strlen(cstr);
	free(cstr);
}

void	ft_printunsdec(t_var *var)
{
	unsigned int	istr;
	char			*cstr;
	int				strlen;

	istr = va_arg(var->args, unsigned int);
	var->length = ft_countitoa(istr);
	if (ft_checkzero(var, istr))
		return ;
	if (var->precision >= 0 && var->length >= var->precision)
		var->precision = 0;
	else
		var->precision -= var->length;
	if (var->precision >= 0)
		ft_insertp(var, var->length);
	cstr = ft_itoa(istr);
	strlen = ft_strlen(cstr);
	if (var->width && !var->flagminus)
		ft_insertflag(var, var->length);
	write(1, cstr, strlen);
	if (var->flagminus && var->width)
		ft_widthwriter(var, var->length);
	var->chars += strlen;
	free(cstr);
}

void	ft_printpercent(t_var *var)
{
	var->length++;
	if (var->precision >= 0)
		var->precision = -1;
	if (var->width && !var->flagminus)
		ft_insertflag(var, var->length);
	write(1, "%", 1);
	if (var->flagminus && var->width)
		ft_widthwriter(var, var->length);
	var->chars++;
}
