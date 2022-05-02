/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:57:39 by elenz             #+#    #+#             */
/*   Updated: 2022/05/02 20:06:01 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_define.h"
# include "../mlx/mlx.h"
# include "../libparser/parser.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>

typedef enum e_textures{
	E_WALL_N,
	E_WALL_S,
	E_WALL_W,
	E_WALL_E,
	E_DOOR,
}				t_textures;

typedef struct s_texture {
	int		width;
	int		height;
	char	*data;
	void	*img_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}			t_texture;

typedef struct s_mouse {
	int		drag;
	int		x_start;
	int		y_start;
	int		div;
}				t_mouse;

typedef struct s_player {
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	x;
	double	y;
	double	mv_sp;
	double	rot_sp;
	double	origrotsp;
	bool	mv_forward;
	bool	mv_backward;
	bool	mv_left;
	bool	mv_right;
}				t_player;

typedef struct s_draw {
	int		lineh;
	int		start;
	int		end;
}				t_draw;

typedef struct s_input
{
	int			rows;
	int			cols;
	int			color;
	double		zscale;
	int			scale;
	int			zmin;
	int			zmax;
}				t_input;

typedef struct s_data {
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_img {
	void	*img;
	double	scale;
	double	time;
	double	old_time;
	int		xoff;
	int		yoff;
	int		iso;
	t_data	data;
}				t_img;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
}				t_ray;

typedef struct s_vars{
	void		*mlx;
	void		*win;
	double		camera_x;
	double		frametime;
	double		perpwalldist;
	double		perpwalldist_v2;
	int			map_x;
	int			map_y;
	int			is_sprite;
	long		sprite_c;
	int			sprite_dead;
	t_draw		draw;
	t_texture	texture[5];
	t_texture	sprite[4];
	t_map		*map_info;
	t_mouse		mouse;
	t_player	pl;
	t_ray		ray;
	t_img		img;
	t_img		b_img;
	t_input		input;
}				t_vars;

int				ft_init(t_vars *vars, t_map *map_info);
unsigned int	ft_pick_tex_color(t_texture tex, int x, int y);
int				ft_pick_texture(t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
int				my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
void			ft_draw_textures(t_vars *vars, int x, t_texture *texture);
int				ft_dda_algorithm(t_vars *vars, t_map map_info);
void			ft_move(t_map *map_info, t_player *pl);
void			ft_draw_rays_3d(t_vars *vars, t_map *map_info);
void			ft_minimap(t_vars *vars, t_map *map_info);
int				mousexy_hook(int x, int y, t_vars *vars);
int				mouse_press(int keycode, int x, int y, t_vars *vars);
int				mouse_release(int keycode, int x, int y, t_vars *vars);
int				ft_init_textures(t_vars *vars, t_map *map_info);
void			ft_minimap(t_vars *vars, t_map *map_info);
#endif