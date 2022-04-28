/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:58:29 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 20:21:52 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static void	ft_doorkey(t_vars *vars, t_player pl, t_map *map)
{
	int	plx;
	int	ply;

	plx = (int)pl.x + (int)round(pl.dir_x);
	ply = (int)pl.y + (int)round(pl.dir_y);
	if (map->map[vars->map_y][vars->map_x] == 'T')
		map->map[vars->map_y][vars->map_x] = - 'T';
	else if (map->map[ply][plx] == - 'T')
		map->map[ply][plx] = 'T';
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->pl.mv_forward = true;
	if (keycode == KEY_S)
		vars->pl.mv_backward = true;
	if (keycode == KEY_A)
		vars->pl.mv_left = true;
	if (keycode == KEY_D)
		vars->pl.mv_right = true;
	if (keycode == KEY_F)
		ft_doorkey(vars, vars->pl, vars->map_info);
	if (keycode == KEY_G)
		vars->sprite_dead ^= 1;
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
		vars->pl.mv_forward = false;
	if (keycode == KEY_S)
		vars->pl.mv_backward = false;
	if (keycode == KEY_A)
		vars->pl.mv_left = false;
	if (keycode == KEY_D)
		vars->pl.mv_right = false;
	return (SUCCESS);
}
