/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:49 by lpfleide          #+#    #+#             */
/*   Updated: 2022/05/02 20:41:05 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

int	mouse_press(int keycode, int __attribute__((__unused__))x,
	int __attribute__((__unused__))y, t_vars *vars)
{
	vars->mouse.x_start = x;
	if (keycode == 1)
		vars->mouse.drag = 1;
	return (0);
}

int	mouse_release(int keycode, int __attribute__((__unused__))x,
	int __attribute__((__unused__))y,
		t_vars *vars)
{
	if (keycode == 1)
		vars->mouse.drag = 0;
	vars->pl.mv_left = false;
	vars->pl.mv_right = false;
	vars->pl.rot_sp = vars->pl.origrotsp;
	return (0);
}

/* 
** activates rotation relative to how far the mouse was moved. 
** Bigger movement -> faster rotation
 */
int	mousexy_hook(int x, int __attribute__((__unused__))y, t_vars *vars)
{
	if (vars->mouse.drag == 1)
	{
		if (vars->mouse.x_start < x)
			vars->pl.mv_right = true;
		if (vars->mouse.x_start > x)
			vars->pl.mv_left = true;
		vars->pl.rot_sp = fabs(ldexp(vars->mouse.x_start - x, -12));
	}
	return (0);
}
