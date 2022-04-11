#include "../defines/cub3d.h"

static void	get_dir(t_map *map_info, t_vars *vars)
{
	double oldDirX;
	double oldPlaneX;
	vars->pl.dirX = 1;
	vars->pl.dirY = 0;
	if (map_info->pl_dir == 'S')
	{
		vars->pl.planeX = -0.66;	
		vars->pl.planeY = 0;
		vars->pl.dirX = 0;
		vars->pl.dirY = 1;
	}
	if (map_info->pl_dir == 'N')
	{
		vars->pl.planeX = 0.66;	
		vars->pl.planeY = 0;
		vars->pl.dirX = 0;
		vars->pl.dirY = -1;
	}
	if (map_info->pl_dir == 'E')
	{
		vars->pl.dirX = 1;
		vars->pl.dirY = 0;
	}
	if (map_info->pl_dir == 'W')
	{
		vars->pl.dirX = -1;
		vars->pl.dirY = 0;
		vars->pl.planeX = 0;	
		vars->pl.planeY = -0.66;
	}
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

static int	ft_init_textures(t_vars *vars, t_map *map_info)
{
	int	i;

	i = 0;
	vars->sprite[0].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bunny0.xpm", &vars->sprite[0].width, &vars->sprite[0].width);
	vars->sprite[1].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bunny1.xpm", &vars->sprite[1].width, &vars->sprite[1].width);
	vars->sprite[2].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bunny2.xpm", &vars->sprite[2].width, &vars->sprite[2].width);
	vars->sprite[3].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bunny3.xpm", &vars->sprite[3].width, &vars->sprite[2].width);
	vars->texture[E_WALL_N].img_ptr = mlx_xpm_file_to_image(vars->mlx, map_info->no_path, &vars->texture[0].width, &vars->texture[0].width);
	vars->texture[E_WALL_S].img_ptr = mlx_xpm_file_to_image(vars->mlx, map_info->so_path, &vars->texture[1].width, &vars->texture[1].width);
	vars->texture[E_WALL_W].img_ptr = mlx_xpm_file_to_image(vars->mlx, map_info->we_path, &vars->texture[2].width, &vars->texture[2].width);
	vars->texture[E_WALL_E].img_ptr = mlx_xpm_file_to_image(vars->mlx, map_info->ea_path, &vars->texture[3].width, &vars->texture[3].width);
	vars->texture[E_DOOR].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bookshelf.xpm", &vars->texture[4].width, &vars->texture[4].width);
	while (i < 4)
	{
		if (vars->sprite[i].img_ptr == NULL)
			return (FAIL);
		vars->sprite[i].data = mlx_get_data_addr(vars->sprite[i].img_ptr,
			&vars->sprite[i].bpp, &vars->sprite[i].line_length,
			&vars->sprite[i].endian);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (vars->texture[i].img_ptr == NULL)
			return (FAIL);
		vars->texture[i].data = mlx_get_data_addr(vars->texture[i].img_ptr,
			&vars->texture[i].bpp, &vars->texture[i].line_length,
			&vars->texture[i].endian);
		i++;
	}
	return (SUCCESS);
}

static void	ft_init_player(t_vars *vars, t_map *map_info)
{
	vars->pl.planeX = 0;	
	vars->pl.planeY = 0.66;
	get_dir(map_info, vars);
	vars->pl.x = map_info->pl_x;
	vars->pl.y = map_info->pl_y;
	vars->pl.moveForward = false;
	vars->pl.moveBackward = false;
	vars->pl.moveLeft = false;
	vars->pl.moveRight = false;
	vars->pl.origRotSpeed = FRAMETIME * 3.0;
	vars->pl.rotSpeed = vars->pl.origRotSpeed;
	vars->pl.moveSpeed = FRAMETIME * 5.0;
}
int	ft_init(t_vars *vars, t_map *map_info)
{
	ft_init_mlx_win_img(vars);
	vars->map_info = map_info;
	vars->isSprite = 0;
	vars->spriteC = 0;
	vars->spriteDead = 0;
	vars->mouse.drag = 0;
	if (ft_init_textures(vars, map_info) == FAIL)
		return (FAIL);
	ft_init_player(vars, map_info);
	return (SUCCESS);
}