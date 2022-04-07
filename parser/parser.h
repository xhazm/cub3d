#ifndef PARSER_H
# define PARSER_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

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
	int		fd;
	int		first_row_map;
	char	pl_dir;
	char	**map;
	int		height;
	int		width;
	char	*ceilling_color;
	char	*floor_color;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}			t_map;

int			parser(int argc, char **argv);
int			read_info(char **argv, t_map *map_info);
int 		open_map(char **argv, t_map *map_info);
int 		check_spaces(char c);
int			get_informations(t_map *map_info, char **raw_read);
int			get_type(t_map *map_info, char **sp_line);
int			get_map_size(t_map *map_info, int *x, char **raw_read);
int			get_map(t_map *map_info, char **map_read);
int			check_meta_info(t_map *m);
int			check_map(t_map *map_info);
int			check_first_row(t_map *map_info);
int			check_middle_rows(t_map *map_info);
int			check_last_row(t_map *map_info);
void 		print_map(char **map, int height);
void 		print_info(t_map *m);
int			ft_error(char *msg);
char		*minishell_get_next_line(int fd);
#endif