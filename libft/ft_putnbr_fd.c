/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:45:08 by lpfleide          #+#    #+#             */
/*   Updated: 2021/06/29 17:02:38 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;
	int		arr[20];
	int		i;

	i = 0;
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (n != 0)
	{
		arr[i] = n % 10;
		if (arr[i] < 0)
			arr[i] *= -1;
		i++;
		n /= 10;
	}
	while (i--)
	{
		temp = arr[i] + '0';
		write(fd, &temp, 1);
	}
}
