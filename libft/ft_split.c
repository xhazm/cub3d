/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:48:13 by lpfleide          #+#    #+#             */
/*   Updated: 2021/06/30 13:51:06 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strcount(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s[i] != c && s[i] != '\0')
		j++;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		if (i != 0 && s[i - 1] == c && s[i] != c)
			j++;
		i++;
	}
	return (j);
}

static	size_t	ft_get_string_size(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	char	**ft_free_reloaded(char **s, size_t j)
{
	size_t	i;

	i = 0;
	while (j >= i)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	if (s == 0)
		return (0);
	str = malloc(sizeof(char *) * (ft_strcount(s, c) + 1));
	if (str == 0)
		return (0);
	while (s[i] != '\0' && j < (size_t)ft_strcount(s, c))
	{
		if (s[i] != c && s[i] != '\0')
		{			
			str[j] = ft_substr(s, i, ft_get_string_size(&s[i], c));
			if (str[j] == 0)
				return (ft_free_reloaded(str, j));
			i += ft_get_string_size(&s[i], c);
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
