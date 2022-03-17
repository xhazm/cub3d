/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:03:46 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 15:52:38 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
	int		read;
	int		write;
	int		allocflag;
};

struct s_buffer
{
	int			read ;
	int			write;
	char		buffer[BUFFER_SIZE];
};

char	*get_next_line(int fd);
char	*ft_memcpy_gnl(char *dst, char *src, size_t n);

#endif
