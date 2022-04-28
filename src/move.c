/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:09:01 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 17:57:13 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static void	ft_rotate(t_vars *vars, t_player *pl)
{
	double	odirx;
	double	oplanex;

	odirx = pl->dirX;
	oplanex = pl->planeX;
	if (pl->mvLeft == true)
	{
		odirx = pl->dirX;
		pl->dirX = pl->dirX * cos(-pl->rotSp) - pl->dirY * sin(-pl->rotSp);
		pl->dirY = odirx * sin(-pl->rotSp) + pl->dirY * cos(-pl->rotSp);
		oplanex = pl->planeX;
		pl->planeX = pl->planeX * cos(-pl->rotSp) \
		- pl->planeY * sin(-pl->rotSp);
		pl->planeY = oplanex * sin(-pl->rotSp) + pl->planeY * cos(-pl->rotSp);
	}
	if (pl->mvRight == true)
	{
		odirx = pl->dirX;
		pl->dirX = pl->dirX * cos(pl->rotSp) - pl->dirY * sin(pl->rotSp);
		pl->dirY = odirx * sin(pl->rotSp) + pl->dirY * cos(pl->rotSp);
		oplanex = pl->planeX;
		pl->planeX = pl->planeX * cos(pl->rotSp) - pl->planeY * sin(pl->rotSp);
		pl->planeY = oplanex * sin(pl->rotSp) + pl->planeY * cos(pl->rotSp);
	}
}

void	ft_move(t_vars *vars, t_map *map_info, t_player *pl)
{
	if (pl->mvForward == true)
	{
		if (map_info->map[(int)(pl->y + pl->dirY \
		* pl->mvSp)][(int)(pl->x)] <= 0)
			pl->y += pl->dirY * pl->mvSp;
		if (map_info->map[(int)(pl->y)][(int)(pl->x + pl->dirX \
		* pl->mvSp)] <= 0)
			pl->x += pl->dirX * pl->mvSp;
	}
	if (pl->mvBackward == true)
	{
		if (map_info->map[(int)(pl->y - pl->dirY \
		* pl->mvSp)][(int)(pl->x)] <= 0)
			pl->y -= pl->dirY * pl->mvSp;
		if (map_info->map[(int)(pl->y)][(int)(pl->x - pl->dirX \
		* pl->mvSp)] <= 0)
			pl->x -= pl->dirX * pl->mvSp;
	}
	ft_rotate(vars, pl);
}
