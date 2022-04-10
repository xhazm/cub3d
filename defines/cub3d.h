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

typedef struct s_texture {
	int		width;
	int		height;
	char	*data;
	void	*img_ptr;
	int		bpp;
	int		endian;
	int		line_length;
}			t_texture;

typedef struct s_player {
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	x;
	double	y;
	double	moveSpeed;
	double	rotSpeed;
	bool	moveForward;
	bool	moveBackward;
	bool	moveLeft;
	bool	moveRight;
	// t_mouse	mouse;
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
	t_draw		draw;
	t_texture	texture[4];
	t_map 		*map_info;
	// t_rotate	rt;
	t_player	pl;
	t_ray		ray;
	t_img		img;
	t_input		input;
}				t_vars;



int	key_hook(int keycode, t_vars *vars);
void bresenham(t_vars *vars, int x0, int y0, int x1, int y1, int color);
int	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int	key_press(int keycode, t_vars *vars);
int	key_release(int keycode, t_vars *vars);
int	ft_init_textures(t_vars *vars);
void	ft_draw_textures(t_vars *vars, int x);





#endif