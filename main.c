#include "cub3d.h"

static int	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);


void bresenham(t_vars *vars, int x0, int y0, int x1, int y1)
{
  int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int err = dx+dy, e2; /* error value e_xy */

  while (1) {
	my_mlx_pixel_put(vars, x0 ,y0 , 0x00FF0000);
    if (x0==x1 && y0==y1) break;
    e2 = 2*err;
    if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}


int map[]=
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,
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

static void	ft_init_rays(t_rays *rays)
{
	rays->r = 0;
	rays->old_rx = 0;
	rays->rx = 0;
	rays->ry = 0;
	rays->old_ry = 0;
	rays->ra = 0;
	rays->xo = 0;
	rays->yo = 0;
	rays->mx = 0;
	rays->my = 0;
	rays->mp = 0;
	rays->dof = 0;
}
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

void drawRays3D(t_vars *vars)
{
	t_rays	rays;
	int my;

	ft_init_rays(&rays);
	rays.ra = pa;
	//Horizontal lines
	for(rays.r = 0; rays.r < 1; rays.r++)
	{
		rays.dof = 0;
		float aTan = -1/tan(rays.ra);
		if (rays.ra > M_PI)
		{
			rays.ry = (((int)py>>6)<<6) - 0.0001;
			rays.rx = (py - rays.ry) * aTan + px;
			rays.yo = -64;
			rays.xo = - rays.yo * aTan;
		}
		if (rays.ra < M_PI)
		{
			rays.ry = (((int)py>>6)<<6) + 64;
			rays.rx = (py - rays.ry) * aTan + px;
			rays.yo = 64;
			rays.xo = - rays.yo * aTan;
		}
		if (rays.ra == M_PI || rays.ra == 0) //looking straight left/right
		{
			rays.rx = px;
			rays.ry = py;
			rays.dof = 8;
		}
		while (rays.dof < 8)
		{
			rays.mx = (int) (rays.rx) >> 6;
			rays.my = (int)(rays.ry) >> 6;
			rays.mp = rays.my * MAP_W + rays.mx;
			if (rays.mp < MAP_W * MAP_H && map[rays.mp] == 1)
			{
				rays.dof = 8;
			}
			else
			{
				rays.rx += rays.xo;
				rays.ry += rays.yo;
				rays.dof += 1;
			}
			my_mlx_pixel_put(vars, rays.rx ,rays.ry , 0x00FF0000);
			if (rays.old_rx != 0 && rays.old_ry != 0)
				bresenham(vars, rays.old_rx, rays.old_ry, rays.rx, rays.ry);
			rays.old_rx = rays.rx;
			rays.old_ry = rays.ry;
		}
	}
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
	drawRays3D(vars);
	for(int i = -5; i < 5; i++)
	{
		for(int j = -5; j < 5; j++)
		{
			my_mlx_pixel_put(vars, px +  i, py + j, 0x00FF0000);
			for (int h = 0; h < 80; h++)
			{
				//my_mlx_pixel_put(vars, px+pdx*h ,py+pdy*h, 0x00FF0000);
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
	pa = 1;
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