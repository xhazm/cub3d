/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 10:56:17 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/15 12:58:55 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_var
{
	va_list	args;
	int		width;
	int		flagminus;
	int		flagzero;
	int		flaghash;
	int		precision;
	int		chars;
	int		position;
	int		length;
}	t_var;

int		ft_printf(const char *format, ...);
void	ft_printpercent(t_var *var);
void	ft_printunsdec(t_var *var);
void	ft_printint(t_var *var);
void	ft_printptr(t_var *var, char *str);
void	ft_printcharr(t_var *var);
void	ft_printchar(t_var *var);
void	ft_insertflag(t_var *var, int len);
int		ft_intminus(t_var *var, long istr);
void	ft_insertp(t_var *var, int len);
int		ft_checkzero(t_var *var, long istr);
void	ft_widthwriter(t_var *var, int len);
int		ft_countitoa(long a);
int		ft_usitoa(unsigned int a, int countonly);
void	ft_printhex(t_var *var, char *str);
char	*ft_checkzerostr(t_var *var, char *cstr);

#endif