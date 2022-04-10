#include "../defines/cub3d.h"

static int exit_game(t_vars *vars)
{
	// ft_free2darr((void **)vars->mv.cords);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int draw_player(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, IMG_W, IMG_W);
	vars->img.data.addr = mlx_get_data_addr(vars->img.img,
		&vars->img.data.bits_per_pixel, &vars->img.data.line_length,
		&vars->img.data.endian);
	ft_draw_rays_3d(vars, vars->map_info);
	ft_move(vars, vars->map_info);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map_info;

	if (parser(argc, argv, &map_info) == FAIL)
		return (1);
	if (ft_init(&vars, &map_info) == FAIL)
		return (1);
	print_map(map_info.map, map_info.height, &map_info);
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, &vars);
	mlx_hook(vars.win, X_EVENT_EXIT, 1L << 17, &exit_game, &vars);
	mlx_loop_hook(vars.mlx, draw_player, &vars);
	mlx_loop(vars.mlx);
}
