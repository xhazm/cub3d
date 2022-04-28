/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:58:29 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 17:54:39 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static void	ft_doorkey(t_vars *vars, t_player pl, t_map *map)
{
	int	plx;
	int	ply;

	plx = (int)pl.x + (int)round(pl.dirX);
	ply = (int)pl.y + (int)round(pl.dirY);
	if (map->map[vars->mapY][vars->mapX] == 'T')
		map->map[vars->mapY][vars->mapX] = - 'T';
	else if (map->map[ply][plx] == - 'T')
		map->map[ply][plx] = 'T';
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->pl.mvForward = true;
	if (keycode == KEY_S)
		vars->pl.mvBackward = true;
	if (keycode == KEY_A)
		vars->pl.mvLeft = true;
	if (keycode == KEY_D)
		vars->pl.mvRight = true;
	if (keycode == KEY_F)
		ft_doorkey(vars, vars->pl, vars->map_info);
	if (keycode == KEY_G)
		vars->spriteDead ^= 1;
	if (keycode == KEY_ESC)
	{
		ft_free_map_info(vars->map_info);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (SUCCESS);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->pl.mvForward = false;
	if (keycode == KEY_S)
		vars->pl.mvBackward = false;
	if (keycode == KEY_A)
		vars->pl.mvLeft = false;
	if (keycode == KEY_D)
		vars->pl.mvRight = false;
	return (SUCCESS);
}
