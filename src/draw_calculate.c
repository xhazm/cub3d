/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:31 by lpfleide          #+#    #+#             */
/*   Updated: 2022/05/02 21:29:08 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

/* 
** distance from player to next full map-grid intersection and sets ray step dir
 */
static void	ft_calc_grid_dist(t_vars *vars)
{
	if (vars->ray.dir_x < 0)
	{
		vars->ray.step_x = -1;
		vars->ray.side_dist_x = (vars->pl.x - vars->map_x) \
		* vars->ray.delta_dist_x;
	}
	else
	{
		vars->ray.step_x = 1;
		vars->ray.side_dist_x = (vars->map_x + 1.0 - vars->pl.x) \
		* vars->ray.delta_dist_x;
	}
	if (vars->ray.dir_y < 0)
	{
		vars->ray.step_y = -1;
		vars->ray.side_dist_y = (vars->pl.y - vars->map_y) \
		* vars->ray.delta_dist_y;
	}
	else
	{
		vars->ray.step_y = 1;
		vars->ray.side_dist_y = (vars->map_y + 1.0 - vars->pl.y) \
		* vars->ray.delta_dist_y;
	}
}

/* 
** distance from last map-grid intersection to next map-grid intersection
 */
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

/* 
** sets everything needed for player camera plane
 */
static void	ft_init_draw_values(t_vars *vars, int x)
{
	vars->ray.hit = 0;
	vars->ray.side = 0;
	vars->camera_x = 2 * x / (double)IMG_W - 1;
	vars->ray.dir_x = vars->pl.dir_x + vars->pl.plane_x * vars->camera_x;
	vars->ray.dir_y = vars->pl.dir_y + vars->pl.plane_y * vars->camera_x;
	vars->map_x = (int)vars->pl.x;
	vars->map_y = (int)vars->pl.y;
}

/* 
** Calculates and draws POV vision
 */
void	ft_draw_rays_3d(t_vars *vars, t_map *map_info)
{
	int	x;

	x = 0;
	vars->is_sprite = 0;
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
		if (vars->is_sprite == 0)
			ft_draw_textures(vars, x, vars->texture);
		else if (vars->is_sprite == 1 && vars->ray.side == 0)
			ft_draw_textures(vars, x, vars->sprite);
		x++;
		if (x == IMG_W && vars->is_sprite == 0)
		{
			x = 0;
			vars->is_sprite = 1;
		}
	}
}
