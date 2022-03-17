/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:03:46 by lpfleide          #+#    #+#             */
/*   Updated: 2022/01/12 19:49:23 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

struct s_line
{
	char	*cstr;
	int		alloc;
	int		write;
};

struct s_buffer
{
	int			read;
	int			write;
	char		buffer[BUFFER_SIZE];
};

char	*get_next_line(int fd);
char	*ft_memcpy_gnl(char *dst, char *src, size_t n);

#endif
