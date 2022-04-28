/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:59:00 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 17:46:58 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* reallocs given arr with len (not arr + len), if alloc fails 0 is given back
and arr is not freed */
int	ft_remalloc(void **arr, int len)
{
	void	**newarr;

	newarr = malloc(sizeof(char *) * len);
	if (newarr == 0)
		return (0);
	ft_memcpy(newarr, arr, len);
	free(arr);
	arr = newarr;
	return (1);
}
