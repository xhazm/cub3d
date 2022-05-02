/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:09:01 by lpfleide          #+#    #+#             */
/*   Updated: 2022/05/02 21:12:27 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

/* 
** changes the camera plane & player direction for rotating the FOV
 */
static void	ft_rotate(t_player *pl)
{
	double	odir_x;
	double	opl;

	odir_x = pl->dir_x;
	opl = pl->plane_x;
	if (pl->mv_left == true)
	{
		odir_x = pl->dir_x;
		pl->dir_x = pl->dir_x * cos(-pl->rot_sp) - pl->dir_y * sin(-pl->rot_sp);
		pl->dir_y = odir_x * sin(-pl->rot_sp) + pl->dir_y * cos(-pl->rot_sp);
		opl = pl->plane_x;
		pl->plane_x = pl->plane_x * cos(-pl->rot_sp) \
		- pl->plane_y * sin(-pl->rot_sp);
		pl->plane_y = opl * sin(-pl->rot_sp) + pl->plane_y * cos(-pl->rot_sp);
	}
	if (pl->mv_right == true)
	{
		odir_x = pl->dir_x;
		pl->dir_x = pl->dir_x * cos(pl->rot_sp) - pl->dir_y * sin(pl->rot_sp);
		pl->dir_y = odir_x * sin(pl->rot_sp) + pl->dir_y * cos(pl->rot_sp);
		opl = pl->plane_x;
		pl->plane_x = pl->plane_x * cos(pl->rot_sp) - pl->plane_y \
		* sin(pl->rot_sp);
		pl->plane_y = opl * sin(pl->rot_sp) + pl->plane_y * cos(pl->rot_sp);
	}
}

/* 
** changes FOV by changing the player position when moving and changing the
** camera plane when rotating. All actions activated by key or mouseinput.
 */
void	ft_move(t_map *map_info, t_player *pl)
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
	ft_rotate(pl);
}
