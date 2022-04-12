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

static void	ft_rotate(t_vars *vars, t_player *pl)
{
	double oDirX;
	double oPlaneX;

	oDirX = pl->dirX;
	oPlaneX = pl->planeX;
	if (pl->mvLeft == true)
	{
		oDirX = pl->dirX;
		pl->dirX = pl->dirX * cos(-pl->rotSp) - pl->dirY * sin(-pl->rotSp);
		pl->dirY = oDirX * sin(-pl->rotSp) + pl->dirY * cos(-pl->rotSp);
		oPlaneX = pl->planeX;
		pl->planeX = pl->planeX * cos(-pl->rotSp) - pl->planeY * sin(-pl->rotSp);
		pl->planeY = oPlaneX * sin(-pl->rotSp) + pl->planeY * cos(-pl->rotSp);
	}
	if (pl->mvRight == true)
	{
		oDirX = pl->dirX;
		pl->dirX = pl->dirX * cos(pl->rotSp) - pl->dirY * sin(pl->rotSp);
		pl->dirY = oDirX * sin(pl->rotSp) + pl->dirY * cos(pl->rotSp);
		oPlaneX = pl->planeX;
		pl->planeX = pl->planeX * cos(pl->rotSp) - pl->planeY * sin(pl->rotSp);
		pl->planeY = oPlaneX * sin(pl->rotSp) + pl->planeY * cos(pl->rotSp);
	}
}

void	ft_move(t_vars *vars, t_map *map_info, t_player *pl)
{
	if (pl->mvForward == true)
	{
		if (map_info->map[(int)(pl->y + pl->dirY * pl->mvSp)][(int)(pl->x)] <= 0)
			pl->y += pl->dirY * pl->mvSp;
		if (map_info->map[(int)(pl->y)][(int)(pl->x + pl->dirX * pl->mvSp)] <= 0)
			pl->x += pl->dirX * pl->mvSp;
	}
	if (pl->mvBackward == true)
	{
		if (map_info->map[(int)(pl->y - pl->dirY * pl->mvSp)][(int)(pl->x)] <= 0)
			pl->y -= pl->dirY * pl->mvSp;
		if (map_info->map[(int)(pl->y)][(int)(pl->x - pl->dirX * pl->mvSp)] <= 0)
			pl->x -= pl->dirX * pl->mvSp;
	}
	ft_rotate(vars, pl);
}
