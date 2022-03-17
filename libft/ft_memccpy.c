/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:24:44 by lpfleide          #+#    #+#             */
/*   Updated: 2021/06/30 13:51:37 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	j;
	char			*ret;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	j = c;
	d = dst;
	s = (unsigned char *) src;
	while (i < n && j != s[i])
	{
		d[i] = s[i];
		i++;
	}
	if (s[i] == j)
	{
		d[i] = s[i];
		ret = dst;
		return (&ret[i + 1]);
	}
	return (0);
}
