/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calculate_dda.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:15 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 20:15:31 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static int	ft_get_maphit(t_vars *vars, t_map map_info)
{
	if (vars->is_sprite == 0)
	{
		if (map_info.map[vars->map_y][vars->map_x] > 0)
			return (1);
	}
	else if (vars->is_sprite == 1)
	{
		if (map_info.map[vars->map_y][vars->map_x] == - 'R')
			return (1);
		else if (map_info.map[vars->map_y][vars->map_x] > 0)
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
			vars->map_x += vars->ray.step_x;
			vars->ray.side = 0;
		}
		else
		{
			vars->ray.side_dist_y += vars->ray.delta_dist_y;
			vars->map_y += vars->ray.step_y;
			vars->ray.side = 1;
		}
		vars->ray.hit = ft_get_maphit(vars, map_info);
		if (vars->ray.hit == -1)
			return (FAIL);
	}
	if (vars->ray.side == 0)
		vars->perpwalldist = (vars->ray.side_dist_x - vars->ray.delta_dist_x);
	else
		vars->perpwalldist = (vars->ray.side_dist_y - vars->ray.delta_dist_y);
	if (vars->perpwalldist == 0)
		vars->perpwalldist = 0;
	return (SUCCESS);
}
