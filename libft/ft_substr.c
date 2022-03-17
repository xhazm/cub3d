/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:07:01 by lpfleide          #+#    #+#             */
/*   Updated: 2021/07/16 12:32:30 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = ft_strlen(s);
	str = malloc(len + 1);
	if (str == 0 || s == 0)
		return (0);
	if (start >= j)
	{
		str[0] = 0;
		return (str);
	}
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
