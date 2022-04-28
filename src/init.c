/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:44 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 20:31:37 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static void	get_dir_e_w(t_vars *vars, t_map *map_info)
{
	if (map_info->pl_dir == 'E')
	{
		vars->pl.dir_x = 1;
		vars->pl.dir_y = 0;
		vars->pl.plane_x = 0;
		vars->pl.plane_y = 0.66;
	}
	else if (map_info->pl_dir == 'W')
	{
		vars->pl.dir_x = -1;
		vars->pl.dir_y = 0;
		vars->pl.plane_x = 0;
		vars->pl.plane_y = -0.66;
	}
}

static void	get_dir(t_vars *vars, t_map *map_info)
{
	if (map_info->pl_dir == 'S')
	{
		vars->pl.dir_x = 0;
		vars->pl.dir_y = 1;
		vars->pl.plane_x = -0.66;
		vars->pl.plane_y = 0;
	}
	else if (map_info->pl_dir == 'N')
	{
		vars->pl.dir_x = 0;
		vars->pl.dir_y = -1;
		vars->pl.plane_x = 0.66;
		vars->pl.plane_y = 0;
	}
	else
		get_dir_e_w(vars, map_info);
}

static void	ft_init_mlx_win_img(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	vars->ray.hit = 0;
	vars->img.yoff = 0;
	vars->img.xoff = 0;
	vars->img.scale = vars->input.scale;
}

static void	ft_init_player(t_vars *vars, t_map *map_info)
{
	get_dir(vars, map_info);
	vars->pl.x = map_info->pl_x;
	vars->pl.y = map_info->pl_y;
	vars->pl.mv_forward = false;
	vars->pl.mv_backward = false;
	vars->pl.mv_left = false;
	vars->pl.mv_right = false;
	vars->pl.origrotsp = FRAMETIME * 3.0;
	vars->pl.rot_sp = vars->pl.origrotsp;
	vars->pl.mv_sp = FRAMETIME * 5.0;
}

int	ft_init(t_vars *vars, t_map *map_info)
{
	ft_init_mlx_win_img(vars);
	vars->map_info = map_info;
	vars->is_sprite = 0;
	vars->sprite_c = 0;
	vars->sprite_dead = 0;
	vars->mouse.drag = 0;
	if (ft_init_textures(vars, map_info) == FAIL)
		return (FAIL);
	ft_init_player(vars, map_info);
	return (SUCCESS);
}
