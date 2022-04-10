#include "../defines/cub3d.h"

static void	get_dir(t_map *map_info, t_vars *vars)
{
	if (map_info->pl_dir == 'S')
	{
		vars->pl.dirX = -1;
		vars->pl.dirY = 0;
	}
	if (map_info->pl_dir == 'N')
	{
		vars->pl.dirX = 1;
		vars->pl.dirY = 0;
	}
	if (map_info->pl_dir == 'E')
	{
		vars->pl.dirX = 0;
		vars->pl.dirY = 1;
	}
	if (map_info->pl_dir == 'W')
	{
		vars->pl.dirX = 0;
		vars->pl.dirY = -1;
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

static int	ft_init_textures(t_vars *vars)
{
	int	i;

	i = 0;
	vars->texture[0].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bricks.xpm", &vars->texture[0].width, &vars->texture[0].width);
	vars->texture[1].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/magma.xpm", &vars->texture[1].width, &vars->texture[1].width);
	vars->texture[2].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/mossy_cobblestone.xpm", &vars->texture[2].width, &vars->texture[2].width);
	vars->texture[3].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/obsidian.xpm", &vars->texture[3].width, &vars->texture[3].width);
	vars->texture[4].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/stone_bricks.xpm", &vars->texture[4].width, &vars->texture[4].width);
	vars->texture[5].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bookshelf.xpm", &vars->texture[5].width, &vars->texture[5].width);
	while (i < 6)
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
	get_dir(map_info, vars);
	vars->pl.planeX = 0;	
	vars->pl.planeY = 0.66;
	vars->pl.x = map_info->pl_x;
	vars->pl.y = map_info->pl_y;
	vars->pl.moveForward = false;
	vars->pl.moveBackward = false;
	vars->pl.moveLeft = false;
	vars->pl.moveRight = false;
	vars->pl.rotSpeed = FRAMETIME * 3.0;
	vars->pl.moveSpeed = FRAMETIME * 5.0;
}
int	ft_init(t_vars *vars, t_map *map_info)
{
	ft_init_mlx_win_img(vars);
	if (ft_init_textures(vars) == FAIL)
		return (FAIL);
	ft_init_player(vars, map_info);
	return (SUCCESS);
}