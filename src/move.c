/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:09:01 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/07 13:52:02 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static void	ft_rotate(t_vars *vars, t_map *map_info)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = vars->pl.dirX;
	oldPlaneX = vars->pl.planeX;
	if (vars->pl.moveLeft == true)
	{
		oldDirX = vars->pl.dirX;
		vars->pl.dirX = vars->pl.dirX * cos(-vars->pl.rotSpeed) - vars->pl.dirY * sin(-vars->pl.rotSpeed);
		vars->pl.dirY = oldDirX * sin(-vars->pl.rotSpeed) + vars->pl.dirY * cos(-vars->pl.rotSpeed);
		oldPlaneX = vars->pl.planeX;
		vars->pl.planeX = vars->pl.planeX * cos(-vars->pl.rotSpeed) - vars->pl.planeY * sin(-vars->pl.rotSpeed);
		vars->pl.planeY = oldPlaneX * sin(-vars->pl.rotSpeed) + vars->pl.planeY * cos(-vars->pl.rotSpeed);
	}
	if (vars->pl.moveRight == true)
	{
		oldDirX = vars->pl.dirX;
		vars->pl.dirX = vars->pl.dirX * cos(vars->pl.rotSpeed) - vars->pl.dirY * sin(vars->pl.rotSpeed);
		vars->pl.dirY = oldDirX * sin(vars->pl.rotSpeed) + vars->pl.dirY * cos(vars->pl.rotSpeed);
		oldPlaneX = vars->pl.planeX;
		vars->pl.planeX = vars->pl.planeX * cos(vars->pl.rotSpeed) - vars->pl.planeY * sin(vars->pl.rotSpeed);
		vars->pl.planeY = oldPlaneX * sin(vars->pl.rotSpeed) + vars->pl.planeY * cos(vars->pl.rotSpeed);
	}
}

void	ft_move(t_vars *vars, t_map *map_info)
{
	if (vars->pl.moveForward == true)
	{
		if (map_info->map[(int)(vars->pl.y + vars->pl.dirY * vars->pl.moveSpeed)][(int)(vars->pl.x)] <= 0)
			vars->pl.y += vars->pl.dirY * vars->pl.moveSpeed;
		if (map_info->map[(int)(vars->pl.y)][(int)(vars->pl.x + vars->pl.dirX * vars->pl.moveSpeed)] <= 0)
			vars->pl.x += vars->pl.dirX * vars->pl.moveSpeed;
	}
	if (vars->pl.moveBackward == true)
	{
		if (map_info->map[(int)(vars->pl.y - vars->pl.dirY * vars->pl.moveSpeed)][(int)(vars->pl.x)] <= 0)
			vars->pl.y -= vars->pl.dirY * vars->pl.moveSpeed;
		if (map_info->map[(int)(vars->pl.y)][(int)(vars->pl.x - vars->pl.dirX * vars->pl.moveSpeed)] <= 0)
			vars->pl.x -= vars->pl.dirX * vars->pl.moveSpeed;
	}
	ft_rotate(vars, map_info);
}
