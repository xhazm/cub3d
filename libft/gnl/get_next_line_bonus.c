/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:06:39 by lpfleide          #+#    #+#             */
/*   Updated: 2021/12/14 15:52:31 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_memcpy_gnl(char *dst, char *src, size_t n);

static int	ft_init_line(struct s_line *line)
{
	line->alloc = 64;
	line->write = 0;
	line->cstr = malloc (sizeof(char) * line->alloc);
	line->cstr[line->alloc - 1] = '\0';
	if (line->cstr == 0)
		return (0);
	return (1);
}

static int	ft_readbuffer(int fd, char *cptr)
{
	static struct s_buffer			buff[10240];
	char							c;

	if (buff[fd].write >= buff[fd].read)
	{
		buff[fd].read = read(fd, buff[fd].buffer, sizeof(char) * BUFFER_SIZE);
		buff[fd].write = 0;
	}
	if (buff[fd].read == 0)
		return (0);
	c = buff[fd].buffer[buff[fd].write];
	buff[fd].write++;
	*cptr = c;
	return (1);
}

static int	ft_char_to_str(struct s_line *line, char c)
{
	char	*newstr;

	if (line->write >= line->alloc)
	{
		line->alloc += 64;
		newstr = malloc(sizeof(char) * line->alloc);
		if (newstr == 0)
			return (0);
		ft_memcpy_gnl(newstr, line->cstr, line->write + 1);
		free (line->cstr);
		line->cstr = newstr;
	}
	line->cstr[line->write] = c;
	line->write++;
	if (c == '\n' || c == 0)
		return (0);
	return (1);
}

static int	ft_makelinestr(struct s_line *line, int fd)
{
	char	c;

	c = 1;
	while (ft_readbuffer(fd, &c))
	{
		if (c < 0)
		{
			free(line->cstr);
			return (-1);
		}
		if (c == 0)
			break ;
		if (ft_char_to_str(line, c) == 0)
			break ;
	}
	line->cstr[line->write] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	struct s_line	line;
	char			*str;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_init_line(&line))
		return (NULL);
	if (ft_makelinestr(&line, fd) == -1)
		return (NULL);
	str = malloc(sizeof(char) * line.write + 1);
	if (!str)
	{
		free(line.cstr);
		return (NULL);
	}
	ft_memcpy_gnl(str, line.cstr, line.write + 1);
	free(line.cstr);
	if (str[0] == '\0')
	{
		free (str);
		return (NULL);
	}
	return (str);
}
