/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_key_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:58:29 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/07 13:51:59 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"


	// if (keycode == KEY_W)
	// 	vars->mv.yoff -= 5;
	// if (keycode == KEY_S)
	// 	vars->mv.yoff += 5;
	// if (keycode == KEY_A)
	// 	vars->mv.xoff -= 5;
	// if (keycode == KEY_D)
	// 	vars->mv.xoff += 5;

static void	ft_imgreset(t_vars *vars)
{
	// vars->mv.yoff = 0;
	// vars->img.yoff = 0;
	// vars->mv.xoff = 0;
	// vars->img.xoff = 0;
	// vars->img.scale = vars->input.scale;
}

static void	scale_move_keyhook(int keycode, t_vars *vars)
{
	// if (keycode == KEY_PLUS)
	// 	vars->input.zscale -= 1;
	// if (keycode == KEY_MINUS)
	// 	vars->input.zscale += 1;
	// if (keycode == KEY_MULT)
	// 	vars->input.zscale -= 10;
	// if (keycode == KEY_DIV)
	// 	vars->input.zscale += 10;
	// if (keycode == KEY_L)
	// 	vars->img.xoff += 75;
	// if (keycode == KEY_J)
	// 	vars->img.xoff -= 75;
	// if (keycode == KEY_I)
	// 	vars->img.yoff += 75;
	// if (keycode == KEY_K)
	// 	vars->img.yoff -= 75;
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->pl.moveForward = true;
	if (keycode == KEY_S)
		vars->pl.moveBackward = true;
	if (keycode == KEY_A)
		vars->pl.moveLeft = true;
	if (keycode == KEY_D)
		vars->pl.moveRight = true;
	if (keycode == KEY_ESC)
	{
		// ft_free2darr((void **)vars->mv.cords);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->pl.moveForward = false;
	if (keycode == KEY_S)
		vars->pl.moveBackward = false;
	if (keycode == KEY_A)
		vars->pl.moveLeft = false;
	if (keycode == KEY_D)
		vars->pl.moveRight = false;
}
