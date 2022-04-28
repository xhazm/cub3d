/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:48:48 by elenz             #+#    #+#             */
/*   Updated: 2022/04/28 17:49:00 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define FAIL 0
# define SUCCESS 1

typedef enum e_line_type
{
	MAP,
	NO,
	SO,
	WE,
	EA,
	C,
	F,
	EMPTY_LINE,
}	t_line_type;

typedef struct s_map
{
	int				fd;
	int				first_row_map;
	char			pl_dir;
	double			pl_x;
	double			pl_y;
	char			**map;
	int				height;
	int				width;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
}			t_map;

int				parser(int argc, char **argv, t_map *map_info);
int				read_info(char **argv, t_map *map_info);
int				open_map(char **argv, t_map *map_info);
int				check_spaces(char c);
int				get_informations(t_map *map_info, char **raw_read);
int				get_type(t_map *map_info, char **sp_line);
int				get_map_size(t_map *map_info, int *x, char **raw_read);
int				get_map(t_map *map_info, char **map_read);
int				check_meta_info(t_map *m);
int				check_map(t_map *map_info);
int				check_first_row(t_map *map_info);
int				check_middle_rows(t_map *map_info);
int				check_last_row(t_map *map_info);
int				check_t(char **map, int x, int y, int sign);
void			print_map(char **map, t_map *map_info);
int				ft_error(char *msg);
void			ft_free_map_info(t_map *map_info);
unsigned int	ft_color_converter(char *cStr);
#endif
