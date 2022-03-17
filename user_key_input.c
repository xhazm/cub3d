/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_key_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:58:29 by lpfleide          #+#    #+#             */
/*   Updated: 2022/03/17 22:10:33 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	vars->mv.yoff = 0;
	vars->img.yoff = 0;
	vars->mv.xoff = 0;
	vars->img.xoff = 0;
	vars->img.scale = vars->input.scale;
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

int	key_hook(int keycode, t_vars *vars)
{

	if (keycode >= 34 && keycode != 53)
		scale_move_keyhook(keycode, vars);
	if (keycode == KEY_F)
		ft_imgreset(vars);
	if (keycode == KEY_W)
	{
		px += pdx;
		py += pdy;
	}
	if (keycode == KEY_S)
	{
		px -= pdx;
		py -= pdy;
	}
	if (keycode == KEY_A)
	{
		pa -= 0.1;
		if (pa < 0)
			pa += 2 * M_PI;
		pdx = cos(pa);
		pdy = sin(pa);
		
	}
	if (keycode == KEY_D)
	{
		pa += 0.1;
		if (pa > 2*M_PI)
			pa -= 2 * M_PI;
		pdx = cos(pa);
		pdy = sin(pa);
		
	}
	if (keycode == KEY_ESC)
	{
		// ft_free2darr((void **)vars->mv.cords);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
