#include "../defines/cub3d.h"

static int exit_game(t_vars *vars)
{
	// ft_free2darr((void **)vars->mv.cords);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_draw_rays_3d(t_vars *vars, t_map *map_info)
{
	int	x;
	t_ray ray;

	x = 0;

	while(x < IMG_W)
	{
		vars->ray.hit = 0;
		vars->ray.side = 0;
		vars->cameraX = 2 * x / (double)IMG_W - 1;
		vars->ray.dirX = vars->pl.dirX + vars->pl.planeX * vars->cameraX;
		vars->ray.dirY = vars->pl.dirY + vars->pl.planeY * vars->cameraX;
		vars->mapX = (int)vars->pl.x;
		vars->mapY = (int)vars->pl.y;
		if (vars->ray.dirX == 0)
			vars->ray.deltaDistX = 1e30;
		else
			vars->ray.deltaDistX =  fabs(1 / vars->ray.dirX);
		if (vars->ray.dirY == 0)
			vars->ray.deltaDistY = 1e30;
		else
			vars->ray.deltaDistY = fabs(1 / vars->ray.dirY);
		if (vars->ray.dirX < 0)
		{
			vars->ray.stepX = -1;
			vars->ray.sideDistX = (vars->pl.x - vars->mapX) * vars->ray.deltaDistX;
		}
		else
		{
			vars->ray.stepX = 1;
			vars->ray.sideDistX = (vars->mapX + 1.0 - vars->pl.x) * vars->ray.deltaDistX;
		}
		if (vars->ray.dirY < 0)
		{
			vars->ray.stepY = -1;
			vars->ray.sideDistY = (vars->pl.y - vars->mapY) * vars->ray.deltaDistY;
		}
		else
		{
			vars->ray.stepY = 1;
			vars->ray.sideDistY = (vars->mapY + 1.0 - vars->pl.y) * vars->ray.deltaDistY;
		}
		while (vars->ray.hit == 0)
		{
			if (vars->ray.sideDistX < vars->ray.sideDistY)
			{
				vars->ray.sideDistX += vars->ray.deltaDistX;
				vars->mapX += vars->ray.stepX;
				vars->ray.side = 0;
			}
			else
			{
				vars->ray.sideDistY += vars->ray.deltaDistY;
				vars->mapY += vars->ray.stepY;
				vars->ray.side = 1;
			}
			if (map_info->map[vars->mapY][vars->mapX] > 0)
				vars->ray.hit = 1;
		}
		if (vars->ray.side == 0)
			vars->perpWallDist = (vars->ray.sideDistX - vars->ray.deltaDistX);
		else
			vars->perpWallDist = (vars->ray.sideDistY - vars->ray.deltaDistY);
		if (vars->perpWallDist == 0)
			vars->perpWallDist = 0;
		ft_draw_textures(vars, x);
		x++;
	}
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
	vars.map_info = &map_info;
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, &vars);
	mlx_hook(vars.win, X_EVENT_EXIT, 1L << 17, &exit_game, &vars);
	mlx_loop_hook(vars.mlx, draw_player, &vars);
	mlx_loop(vars.mlx);
}
