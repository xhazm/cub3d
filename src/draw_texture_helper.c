/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpfleide <lpfleide@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:33 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/27 14:52:05 by lpfleide         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

int	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->img.data.addr + (y * vars->img.data.line_length + x
			* (vars->img.data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (1);
}

static int	ft_pick_sprite_tex(t_vars *vars)
{
	int	texNum;

	texNum = 0;
	if (vars->spriteDead == 1)
		texNum = 3;
	else if (vars->spriteC < 100)
		texNum = 0;
	else if (vars->spriteC < 200)
		texNum = 1;
	else if (vars->spriteC < 300)
		texNum = 2;
	else if (vars->spriteC > 300)
	{
		texNum = 0;
		vars->spriteC = 0;
	}
	return (texNum);
}

int	ft_pick_texture(t_vars *vars)
{
	int	texNum;

	texNum = 0;
	if (vars->isSprite == 0)
	{
		if (vars->ray.side == 1 && vars->ray.dirY < 0)
			texNum = E_WALL_N;
		else if (vars->ray.side == 1 && vars->ray.dirY > 0)
			texNum = E_WALL_S;
		else if (vars->ray.side == 0 && vars->ray.dirX < 0)
			texNum = E_WALL_W;
		else if (vars->ray.side == 0 && vars->ray.dirX > 0)
			texNum = E_WALL_E;
		if (vars->map_info->map[vars->mapY][vars->mapX] == 'T')
			texNum = E_DOOR;
	}
	else if (vars->isSprite == 1)
		texNum = ft_pick_sprite_tex(vars);
	return (texNum);
}

unsigned int	ft_pick_tex_color(t_texture tex, int x, int y)
{
	unsigned int	*color;

	color = (unsigned int *)tex.data + ((y
				* tex.line_length + x * (tex.bpp / 8)) / 4);
	return (*color);
}
