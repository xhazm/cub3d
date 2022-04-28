/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:31 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 20:12:35 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static void	ft_calc_grid_dist(t_vars *vars)
{
	if (vars->ray.dir_x < 0)
	{
		vars->ray.step_x = -1;
		vars->ray.side_dist_x = (vars->pl.x - vars->mapX) * vars->ray.delta_dist_x;
	}
	else
	{
		vars->ray.step_x = 1;
		vars->ray.side_dist_x = (vars->mapX + 1.0 - vars->pl.x) \
		* vars->ray.delta_dist_x;
	}
	if (vars->ray.dir_y < 0)
	{
		vars->ray.step_y = -1;
		vars->ray.side_dist_y = (vars->pl.y - vars->mapY) * vars->ray.delta_dist_y;
	}
	else
	{
		vars->ray.step_y = 1;
		vars->ray.side_dist_y = (vars->mapY + 1.0 - vars->pl.y) \
		* vars->ray.delta_dist_y;
	}
}

static void	ft_calc_raylen(t_vars *vars)
{
	if (vars->ray.dir_x == 0)
		vars->ray.delta_dist_x = 1e30;
	else
		vars->ray.delta_dist_x = fabs(1 / vars->ray.dir_x);
	if (vars->ray.dir_y == 0)
		vars->ray.delta_dist_y = 1e30;
	else
		vars->ray.delta_dist_y = fabs(1 / vars->ray.dir_y);
}

int	ft_init_draw_values(t_vars *vars, int x)
{
	vars->ray.hit = 0;
	vars->ray.side = 0;
	vars->cameraX = 2 * x / (double)IMG_W - 1;
	vars->ray.dir_x = vars->pl.dir_x + vars->pl.plane_x * vars->cameraX;
	vars->ray.dir_y = vars->pl.dir_y + vars->pl.plane_y * vars->cameraX;
	vars->mapX = (int)vars->pl.x;
	vars->mapY = (int)vars->pl.y;
}

int	ft_draw_rays_3d(t_vars *vars, t_map *map_info)
{
	int	x;

	x = 0;
	vars->isSprite = 0;
	while (x < IMG_W)
	{
		ft_init_draw_values(vars, x);
		ft_calc_grid_dist(vars);
		ft_calc_raylen(vars);
		if (ft_dda_algorithm(vars, *map_info) == FAIL)
		{
			x++;
			continue ;
		}
		if (vars->isSprite == 0)
			ft_draw_textures(vars, x, vars->texture);
		else if (vars->isSprite == 1 && vars->ray.side == 0)
			ft_draw_textures(vars, x, vars->sprite);
		x++;
		if (x == IMG_W && vars->isSprite == 0)
		{
			x = 0;
			vars->isSprite = 1;
		}
	}
}
