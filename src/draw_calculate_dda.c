#include "../defines/cub3d.h"

static int	ft_get_maphit(t_vars *vars, t_map map_info)
{
	if (vars->isSprite == 0)
	{
		if (map_info.map[vars->mapY][vars->mapX] > 0)
			return (1);
	}
	else if (vars->isSprite == 1)
	{
		if (map_info.map[vars->mapY][vars->mapX] == -'R')
			return (1);
		else if (map_info.map[vars->mapY][vars->mapX] > 0)
			return (-1);
	}
	return (0);
}

int	ft_dda_algorithm(t_vars *vars, t_map map_info)
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
		vars->ray.hit = ft_get_maphit(vars, map_info);
		if (vars->ray.hit == -1)
			return (FAIL);
	}
	if (vars->ray.side == 0)
		vars->perpWallDist = (vars->ray.sideDistX - vars->ray.deltaDistX);
	else
		vars->perpWallDist = (vars->ray.sideDistY - vars->ray.deltaDistY);
	if (vars->perpWallDist == 0)
		vars->perpWallDist = 0;
	return (SUCCESS);
}
