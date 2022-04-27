/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:49 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/27 14:53:39 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

int	mouse_press(int keycode, int x, int y, t_vars *vars)
{
	vars->mouse.xStart = x;
	if (keycode == 1)
		vars->mouse.drag = 1;
	return (0);
}

int	mouse_release(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 1)
		vars->mouse.drag = 0;
	vars->pl.mvLeft = false;
	vars->pl.mvRight = false;
	vars->pl.rotSp = vars->pl.origrotSp;
	return (0);
}

int	mousexy_hook(int x, int y, t_vars *vars)
{
	if (vars->mouse.drag == 1)
	{
		if (vars->mouse.xStart < x)
			vars->pl.mvRight = true;
		if (vars->mouse.xStart > x)
			vars->pl.mvLeft = true;
		vars->pl.rotSp = fabs(ldexp(vars->mouse.xStart - x, -12));
	}
	return (0);
}
