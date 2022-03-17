/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:52:48 by lpfleide          #+#    #+#             */
/*   Updated: 2021/06/29 14:04:47 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	d;
	char			*p;

	d = c;
	p = b;
	i = 0;
	while (i < len)
	{
		p[i] = d;
		i++;
	}
	return (b);
}
