#include "../defines/cub3d.h"

int	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || y > WIN_HEIGHT || y < 0 || x < 0 || x > IMG_W || y > IMG_H)
		return (1);
	dst = vars->img.data.addr + (y * vars->img.data.line_length + x
			* (vars->img.data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (1);
}

static void	ft_calc_grid_dist(t_vars *vars)
{
	if (vars->ray.dirX < 0)
	{
		vars->ray.stepX = -1;
		vars->ray.sideDistX = (vars->pl.x - vars->mapX) * vars->ray.deltaDistX;
	}
	else
	{
		vars->ray.stepX = 1;
		vars->ray.sideDistX = (vars->mapX + 1.0 - vars->pl.x) * vars->ray.deltaDistX;
	}
	if (vars->ray.dirY < 0)
	{
		vars->ray.stepY = -1;
		vars->ray.sideDistY = (vars->pl.y - vars->mapY) * vars->ray.deltaDistY;
	}
	else
	{
		vars->ray.stepY = 1;
		vars->ray.sideDistY = (vars->mapY + 1.0 - vars->pl.y) * vars->ray.deltaDistY;
	}
}

static void	ft_calc_raylen(t_vars *vars)
{
	if (vars->ray.dirX == 0)
		vars->ray.deltaDistX = 1e30;
	else
		vars->ray.deltaDistX =  fabs(1 / vars->ray.dirX);
	if (vars->ray.dirY == 0)
		vars->ray.deltaDistY = 1e30;
	else
		vars->ray.deltaDistY = fabs(1 / vars->ray.dirY);
}

static void	ft_dda_algorithm(t_vars *vars, t_map *map_info)
{
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
		if (map_info->map[vars->mapY][vars->mapX] > 0)
			vars->ray.hit = 1;
	}
	if (vars->ray.side == 0)
		vars->perpWallDist = (vars->ray.sideDistX - vars->ray.deltaDistX);
	else
		vars->perpWallDist = (vars->ray.sideDistY - vars->ray.deltaDistY);
	if (vars->perpWallDist == 0)
		vars->perpWallDist = 0;
}

int	ft_draw_rays_3d(t_vars *vars, t_map *map_info)
{
	int	x;
	t_ray ray;

	x = 0;
	while(x < IMG_W)
	{
		vars->ray.hit = 0;
		vars->ray.side = 0;
		vars->cameraX = 2 * x / (double)IMG_W - 1;
		vars->ray.dirX = vars->pl.dirX + vars->pl.planeX * vars->cameraX;
		vars->ray.dirY = vars->pl.dirY + vars->pl.planeY * vars->cameraX;
		vars->mapX = (int)vars->pl.x;
		vars->mapY = (int)vars->pl.y;
		ft_calc_grid_dist(vars);
		ft_calc_raylen(vars);
		ft_dda_algorithm(vars, map_info);
		ft_draw_textures(vars, x);
		x++;
	}
}
