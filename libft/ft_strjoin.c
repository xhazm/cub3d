/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 15:18:01 by lpfleide          #+#    #+#             */
/*   Updated: 2021/06/29 21:22:31 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == 0)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	len = ft_strlen(str);
	while (s2[i] != '\0')
	{
		str[len + i] = s2[i];
		i++;
	}
	str[len + i] = '\0';
	return (str);
}
