/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:17:08 by lpfleide          #+#    #+#             */
/*   Updated: 2021/08/27 19:51:31 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*j;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			j = (char *) &s[i];
			return (j);
		}
		i++;
	}
	if (c == '\0' && s[i] == '\0')
	{
		j = (char *) &s[i];
		return (j);
	}
	return (0);
}
