#include "cub3d.h"

int map[21][21]=
{
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

static void	ft_init(t_vars *vars)
{
	vars->pl.x = 22;
	vars->pl.y = 12;
	vars->ray.hit = 0;
	vars->img.yoff = 0;
	vars->img.xoff = 0;
	vars->img.scale = vars->input.scale;
}

int	ft_draw_rays_3d(t_vars *vars)
{
	int	x;

	x = 0;
	while(x < IMG_W)
	{
		vars->cameraX = 2 * x / (double)IMG_W - 1; //IMG_W right?
		vars->ray.dirX = vars->pl.dirX + vars->pl.planeX * vars->cameraX;
		vars->ray.dirY = vars->pl.dirY + vars->pl.planeY * vars->cameraX;
		vars->mapX = (int)vars->pl.x;
		vars->mapY = (int)vars->pl.y;
		if (vars->ray.dirX == 0) //righty right?
			vars->ray.deltaDistX = 1e30;
		else
			vars->ray.deltaDistX =  abs(1 / vars->ray.dirX);//sqrt(1 + (vars->ray.dirY * vars->ray.dirX) / (vars->ray.dirY * vars->ray.dirX))
		if (vars->ray.dirY == 0) //righty right?
			vars->ray.deltaDistY = 1e30;
		else
			vars->ray.deltaDistY =  abs(1 / vars->ray.dirY);//sqrt(1 + (vars->ray.dirY * vars->ray.dirX) / (vars->ray.dirY * vars->ray.dirX))
		if (vars->ray.dirX < 0)
		{
			vars->ray.stepX = -1;
			vars->ray.sideDistX = (vars->pl.x - vars->mapX) * vars->ray.deltaDistX;
		}
		else
		{
			vars->ray.stepX = 1;
			vars->ray.sideDistX = (vars->pl.x + (vars->mapX + 1)) * vars->ray.deltaDistX;
		}
		if (vars->ray.dirY < 0)
		{
			vars->ray.stepY = -1;
			vars->ray.sideDistY = (vars->pl.y - vars->mapY) * vars->ray.deltaDistY;
		}
		else
		{
			vars->ray.stepY = 1;
			vars->ray.sideDistY = (vars->pl.y + (vars->mapX + 1)) * vars->ray.deltaDistY;
		}
		while (vars->ray.hit == 0)
		{
			if (vars->ray.sideDistX < vars->ray.sideDistY)
			{
				vars->ray.sideDistX += vars->ray.deltaDistX;
				vars->mapX += vars->ray.stepX;
				vars->ray.side = 0;
			}
			else
			{
				vars->ray.sideDistY += vars->ray.deltaDistY;
				vars->mapY += vars->ray.stepY;
				vars->ray.side = 1;
			}
			if (map[vars->mapX][vars->mapY] > 0)
				vars->ray.hit = 1;
		}
		if (vars->ray.side == 0)
			vars->perpWallDist = (vars->ray.sideDistX - vars->ray.deltaDistX);
		else
			vars->perpWallDist = (vars->ray.sideDistY - vars->ray.deltaDistY);
		vars->draw.lineH = (int)(IMG_H / vars->perpWallDist);
		vars->draw.start = -vars->draw.lineH / 2 + IMG_H / 2;
		if (vars->draw.start < 0)
			vars->draw.start = 0;
		vars->draw.end = vars->draw.lineH / 2 + IMG_H / 2;
		if (vars->draw.end >= IMG_H)
			vars->draw.end = IMG_H -1;
		if (vars->ray.side == 0)
		{
			bresenham(vars,x, vars->draw.start, x, vars->draw.end, 0x0088ffe1);
			printf("NS %d\n", x);
		}
		else
		{
			printf("EW %d\n", x);
			bresenham(vars, x, vars->draw.start, x, vars->draw.end, 0x00FF0000);
		}
		my_mlx_pixel_put(vars, x ,100 , 0x00FF0000);
		x++;
	}
}


int draw_player(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, IMG_W, IMG_H);
	vars->img.data.addr = mlx_get_data_addr(vars->img.img,
		&vars->img.data.bits_per_pixel, &vars->img.data.line_length,
		&vars->img.data.endian);
	ft_draw_rays_3d(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

int	main(void)
{
	t_vars vars;

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