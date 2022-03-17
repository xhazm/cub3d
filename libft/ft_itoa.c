/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:29:12 by lpfleide          #+#    #+#             */
/*   Updated: 2021/08/26 12:48:56 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_reverse(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

static int	ft_get_numlen(long n)
{
	int	numlen;

	numlen = 1;
	if (n < 0)
		numlen++;
	while (n / 10)
	{
		numlen++;
		n /= 10;
	}
	return (numlen);
}

static	int	ft_minus(long *n, char *nstr)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	if (*n == 0)
	{
		ft_strlcpy(nstr, "0", 2);
		return (2);
	}
	return (0);
}

char	*ft_itoa(long n)
{
	int		i;
	long	j;
	int		neg;
	char	*nstr;

	i = 0;
	j = n;
	nstr = malloc((ft_get_numlen(n) + 1) * sizeof(char));
	if (nstr == 0)
		return (0);
	neg = ft_minus(&j, nstr);
	if (neg == 2)
		return (nstr);
	while (j > 0)
	{
		nstr[i] = j % 10 + '0';
		j /= 10;
		i++;
	}
	if (neg == 1)
		nstr[i++] = '-';
	nstr[i++] = '\0';
	return (ft_reverse(nstr));
}
