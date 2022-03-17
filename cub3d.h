#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_define.h"
# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

float px,py,pdx,pdy,pa;

typedef struct s_move {
	float	xoff;
	float	yoff;
	float	x;
	float	y;
	// t_mouse	mouse;
}				t_move;

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
	int		xoff;
	int		yoff;
	int		iso;
	t_data	data;
}				t_img;


typedef struct s_vars{
	void		*mlx;
	void		*win;
	// t_rotate	rt;
	t_move		mv;
	t_img		img;
	t_input		input;
}				t_vars;

int	key_hook(int keycode, t_vars *vars);


#endif