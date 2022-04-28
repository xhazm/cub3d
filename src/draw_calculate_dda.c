/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calculate_dda.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:15 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 20:12:35 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (map_info.map[vars->mapY][vars->mapX] == - 'R')
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
		if (vars->ray.side_dist_x < vars->ray.side_dist_y)
		{
			vars->ray.side_dist_x += vars->ray.delta_dist_x;
			vars->mapX += vars->ray.step_x;
			vars->ray.side = 0;
		}
		else
		{
			vars->ray.side_dist_y += vars->ray.delta_dist_y;
			vars->mapY += vars->ray.step_y;
			vars->ray.side = 1;
		}
		vars->ray.hit = ft_get_maphit(vars, map_info);
		if (vars->ray.hit == -1)
			return (FAIL);
	}
	if (vars->ray.side == 0)
		vars->perpWallDist = (vars->ray.side_dist_x - vars->ray.delta_dist_x);
	else
		vars->perpWallDist = (vars->ray.side_dist_y - vars->ray.delta_dist_y);
	if (vars->perpWallDist == 0)
		vars->perpWallDist = 0;
	return (SUCCESS);
}
