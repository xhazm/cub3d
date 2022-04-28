/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:33 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 20:16:20 by elenz            ###   ########.fr       */
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
	int	texnum;

	texnum = 0;
	if (vars->sprite_dead == 1)
		texnum = 3;
	else if (vars->sprite_c < 100)
		texnum = 0;
	else if (vars->sprite_c < 200)
		texnum = 1;
	else if (vars->sprite_c < 300)
		texnum = 2;
	else if (vars->sprite_c > 300)
	{
		texnum = 0;
		vars->sprite_c = 0;
	}
	return (texnum);
}

int	ft_pick_texture(t_vars *vars)
{
	int	texnum;

	texnum = 0;
	if (vars->is_sprite == 0)
	{
		if (vars->ray.side == 1 && vars->ray.dir_y < 0)
			texnum = E_WALL_N;
		else if (vars->ray.side == 1 && vars->ray.dir_y > 0)
			texnum = E_WALL_S;
		else if (vars->ray.side == 0 && vars->ray.dir_x < 0)
			texnum = E_WALL_W;
		else if (vars->ray.side == 0 && vars->ray.dir_x > 0)
			texnum = E_WALL_E;
		if (vars->map_info->map[vars->map_y][vars->map_x] == 'T')
			texnum = E_DOOR;
	}
	else if (vars->is_sprite == 1)
		texnum = ft_pick_sprite_tex(vars);
	return (texnum);
}

unsigned int	ft_pick_tex_color(t_texture tex, int x, int y)
{
	unsigned int	*color;

	color = (unsigned int *)tex.data + ((y
				* tex.line_length + x * (tex.bpp / 8)) / 4);
	return (*color);
}
