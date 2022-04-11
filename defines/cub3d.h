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

typedef enum	e_textures{
	E_WALL_N,
	E_WALL_S,
	E_WALL_W,
	E_WALL_E,
	E_DOOR,
} 				t_textures;

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
	int		xStart;
	int		yStart;
	int		div;
}				t_mouse;

typedef struct s_player {
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	x;
	double	y;
	double	moveSpeed;
	double	rotSpeed;
	double	origRotSpeed;
	bool	moveForward;
	bool	moveBackward;
	bool	moveLeft;
	bool	moveRight;
}				t_player;

typedef struct s_draw {
	int		lineH;
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
	double	dirX;
	double	dirY;
	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	int		hit;
	int		side;
	int		stepX;
	int		stepY;
}				t_ray;

typedef struct s_vars{
	void		*mlx;
	void		*win;
	double		cameraX;
	double		frametime;
	double		perpWallDist;
	int			mapX;
	int			mapY;
	int			isSprite;
	long		spriteC;
	int			spriteDead;
	t_draw		draw;
	t_texture	texture[5];
	t_texture	sprite[4];
	t_map 		*map_info;
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
void 			bresenham(t_vars *vars, int x0, int y0, int x1, int y1, int color);
int				my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
void			ft_draw_textures(t_vars *vars, int x, t_texture *texture);
int				ft_dda_algorithm(t_vars *vars, t_map map_info);
void			ft_move(t_vars *vars, t_map *map_info);
int				ft_draw_rays_3d(t_vars *vars, t_map *map_info);
void			ft_minimap(t_vars *vars, t_map *map_info);
int				mousexy_hook(int x, int y, t_vars *vars);
int				mouse_press(int keycode, int x, int y, t_vars *vars);
int				mouse_release(int keycode, int x, int y, t_vars *vars);
int				ft_init_textures(t_vars *vars, t_map *map_info);


#endif