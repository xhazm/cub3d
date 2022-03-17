/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:22:17 by lpfleide          #+#    #+#             */
/*   Updated: 2021/06/29 16:18:30 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = len;
	d = dst;
	s = (char *)src;
	if (src == 0 && dst == 0)
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	i = len;
	while (0 < i)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
	return (dst);
}
