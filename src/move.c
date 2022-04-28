/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:09:01 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 20:08:04 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static void	ft_rotate(t_vars *vars, t_player *pl)
{
	double	odir_x;
	double	oplane_x;

	odir_x = pl->dir_x;
	oplane_x = pl->plane_x;
	if (pl->mv_left == true)
	{
		odir_x = pl->dir_x;
		pl->dir_x = pl->dir_x * cos(-pl->rot_sp) - pl->dir_y * sin(-pl->rot_sp);
		pl->dir_y = odir_x * sin(-pl->rot_sp) + pl->dir_y * cos(-pl->rot_sp);
		oplane_x = pl->plane_x;
		pl->plane_x = pl->plane_x * cos(-pl->rot_sp) \
		- pl->plane_y * sin(-pl->rot_sp);
		pl->plane_y = oplane_x * sin(-pl->rot_sp) + pl->plane_y * cos(-pl->rot_sp);
	}
	if (pl->mv_right == true)
	{
		odir_x = pl->dir_x;
		pl->dir_x = pl->dir_x * cos(pl->rot_sp) - pl->dir_y * sin(pl->rot_sp);
		pl->dir_y = odir_x * sin(pl->rot_sp) + pl->dir_y * cos(pl->rot_sp);
		oplane_x = pl->plane_x;
		pl->plane_x = pl->plane_x * cos(pl->rot_sp) - pl->plane_y * sin(pl->rot_sp);
		pl->plane_y = oplane_x * sin(pl->rot_sp) + pl->plane_y * cos(pl->rot_sp);
	}
}

void	ft_move(t_vars *vars, t_map *map_info, t_player *pl)
{
	if (pl->mv_forward == true)
	{
		if (map_info->map[(int)(pl->y + pl->dir_y \
		* pl->mv_sp)][(int)(pl->x)] <= 0)
			pl->y += pl->dir_y * pl->mv_sp;
		if (map_info->map[(int)(pl->y)][(int)(pl->x + pl->dir_x \
		* pl->mv_sp)] <= 0)
			pl->x += pl->dir_x * pl->mv_sp;
	}
	if (pl->mv_backward == true)
	{
		if (map_info->map[(int)(pl->y - pl->dir_y \
		* pl->mv_sp)][(int)(pl->x)] <= 0)
			pl->y -= pl->dir_y * pl->mv_sp;
		if (map_info->map[(int)(pl->y)][(int)(pl->x - pl->dir_x \
		* pl->mv_sp)] <= 0)
			pl->x -= pl->dir_x * pl->mv_sp;
	}
	ft_rotate(vars, pl);
}
