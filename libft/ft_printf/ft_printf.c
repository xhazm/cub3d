/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:34:17 by lpfleide          #+#    #+#             */
/*   Updated: 2021/08/25 20:27:43 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_readminuszeroflag(t_var *var, char *str)
{
	if (str[var->position] == '-')
		var->flagminus = 1;
	if (str[var->position] == '0')
		var->flagzero = 1;
	if (var->flagminus && var->flagzero)
		var->flagzero = 0;
	var->position++;
}

static int	ft_readflag(t_var *var, char *str)
{
	if (str[var->position] == '#')
	{
		var->flaghash = 1;
		var->position++;
	}
	if (str[var->position] == '-' || str[var->position] == '0')
		ft_readminuszeroflag(var, str);
	while (ft_isdigit(str[var->position]))
	{
		var->width = var->width * 10 + (str[var->position] - '0');
		var->position++;
	}
	if (str[var->position] == '.')
	{
		var->precision = 0;
		var->position++;
		while (ft_isdigit(str[var->position]))
		{			
			var->precision = var->precision * 10
				+ (str[var->position] - '0');
			var->position++;
		}
	}
	return (0);
}

static int	ft_checktype(t_var *var, char *str)
{
	ft_readflag(var, str);
	if (str[var->position] == 'c')
		ft_printchar(var);
	else if (str[var->position] == 's')
		ft_printcharr(var);
	else if (str[var->position] == 'p')
		ft_printptr(var, &str[var->position]);
	else if (str[var->position] == 'd' || str[var->position] == 'i')
		ft_printint(var);
	else if (str[var->position] == 'u')
		ft_printunsdec(var);
	else if (str[var->position] == 'x' || str[var->position] == 'X')
		ft_printhex(var, &str[var->position]);
	else if (str[var->position] == '%')
		ft_printpercent(var);
	else
	{
		write(2, "FLAGERROR", 9);
		return (-1);
	}
	var->position++;
	return (0);
}

static int	ft_start(t_var *var, char *str)
{
	while (str[var->position] != '\0')
	{
		if (str[var->position] == '%')
		{
			var->position++;
			if (ft_checktype(var, str) < 0)
				return (-1);
			var->width = 0;
			var->precision = -1;
			var->flagminus = 0;
			var->flagzero = 0;
			var->flaghash = 0;
			var->length = 0;
		}
		else
		{
			write(1, &str[var->position++], 1);
			var->chars++;
		}
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_var	var;
	char	*str;

	var.precision = -1;
	var.flagminus = 0;
	var.flagzero = 0;
	var.flaghash = 0;
	var.position = 0;
	var.length = 0;
	var.chars = 0;
	var.width = 0;
	va_start(var.args, format);
	str = (char *)format;
	if (ft_start(&var, str) < 0)
		return (-1);
	va_end(var.args);
	return (var.chars);
}
