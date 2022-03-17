/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:43:03 by lpfleide          #+#    #+#             */
/*   Updated: 2021/07/02 12:54:51 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	char	*ret;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		ret = (char *)&(haystack[i]);
		while (haystack[k + i] && needle[k] && haystack[k + i] == needle[k]
			&& k + i < len)
			k++;
		if (needle[k] == '\0')
			return (ret);
		i++;
	}
	return (0);
}
