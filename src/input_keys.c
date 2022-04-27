/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:58:29 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/27 14:53:50 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static void	ft_doorkey(t_vars *vars, t_player pl, t_map *map)
{
	int	plX;
	int	plY;

	plX = (int)pl.x + (int)round(pl.dirX);
	plY = (int)pl.y + (int)round(pl.dirY);
	if (map->map[vars->mapY][vars->mapX] == 'T')
		map->map[vars->mapY][vars->mapX] = - 'T';
	else if (map->map[plY][plX] == - 'T')
		map->map[plY][plX] = 'T';
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
}
