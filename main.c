#include "cub3d.h"


int map[]=
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

static void	ft_init(t_vars *vars)
{
	vars->mv.yoff = 0;
	vars->img.yoff = 0;
	vars->mv.xoff = 0;
	vars->img.xoff = 0;
	vars->img.scale = vars->input.scale;
}

static int	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || y > WIN_HEIGHT || y < 0 || x < 0)
		return (1);
	// if (vars->input.color)
	// 	color = vars->input.color;
	// else
	// 	color = 0x00AAAAAA + (color * 5000);
	dst = vars->img.data.addr + (y * vars->img.data.line_length + x
			* (vars->img.data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (1);
}

int draw_map(t_vars *vars)
{
	int xo = 0;
	int yo = 0;

	for(int y = 0; y < MAP_H; y++)
	{
		for(int x = 0; x < MAP_W; x++)
		{
			if (map[y*MAP_W+x] >= 1)
			{
				xo = x * MAP_S;
				yo = y * MAP_S;
				if (map[y*MAP_W+x + 1] >= 1 && x < MAP_W - 1)
				{
					for(int h = 0; h < MAP_S; h++)
						my_mlx_pixel_put(vars, xo + h, yo, 0x000FFAAA);
					// if (xo >= 1200 || yo >= 1200)
					// 	printf("%d %d\n",xo, yo);
				}
				if (map[(y + 1)*MAP_W+x] >= 1 && y < MAP_H - 1)
				{
					for(int h = 0; h < MAP_S; h++)
						my_mlx_pixel_put(vars, xo, yo + h, 0x000FFAAA);
					// if (xo >= 1200 || yo >= 1200)
					// 	printf("%d %d\n",xo, yo);
				}
			}
		}
	}
}

int draw_player(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, IMG_W, IMG_H);
	vars->img.data.addr = mlx_get_data_addr(vars->img.img,
		&vars->img.data.bits_per_pixel, &vars->img.data.line_length,
		&vars->img.data.endian);
	draw_map(vars);
	for(int i = -5; i < 5; i++)
	{
		for(int j = -5; j < 5; j++)
		{
			my_mlx_pixel_put(vars, px + vars->mv.xoff + i, py + vars->mv.yoff + j, 0x00FF0000);
			for (int h = 0; h < 80; h++)
			{
				my_mlx_pixel_put(vars, (px+pdx*h) + vars->mv.xoff ,(py+pdy*h) + vars->mv.yoff , 0x00FF0000);
			}
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

int	main(void)
{
	t_vars vars;

	px = 500;
	py = 500;
	pdx = cos(pa);
	pdy = sin(pa);
	ft_init(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	vars.img.img = mlx_new_image(vars.mlx, IMG_W, IMG_H);
	vars.img.data.addr = mlx_get_data_addr(vars.img.img,
			&vars.img.data.bits_per_pixel, &vars.img.data.line_length,
			&vars.img.data.endian);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, draw_player, &vars);
	mlx_loop(vars.mlx);
}