/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:52 by lpfleide          #+#    #+#             */
/*   Updated: 2022/05/01 19:17:36 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static int	exit_game(t_vars *vars)
{
	ft_free_map_info(vars->map_info);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

static int	draw_player(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, IMG_W, IMG_W);
	vars->img.data.addr = mlx_get_data_addr(vars->img.img,
			&vars->img.data.bits_per_pixel, &vars->img.data.line_length,
			&vars->img.data.endian);
	vars->sprite_c++;
	ft_draw_rays_3d(vars, vars->map_info);
	ft_move(vars->map_info, &vars->pl);
	ft_minimap(vars, vars->map_info);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map_info;

	if (parser(argc, argv, &map_info) == FAIL)
	{
		ft_free_map_info(&map_info);
		return (FAIL);
	}
	if (ft_init(&vars, &map_info) == FAIL)
	{
		ft_free_map_info(&map_info);
		return (FAIL);
	}
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, &vars);
	mlx_hook(vars.win, X_EVENT_EXIT, 1L << 17, &exit_game, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mousexy_hook, &vars);
	mlx_hook(vars.win, 4, 1L << 2, &mouse_press, &vars);
	mlx_hook(vars.win, 5, 1L << 3, &mouse_release, &vars);
	mlx_loop_hook(vars.mlx, draw_player, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
