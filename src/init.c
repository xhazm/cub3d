#include "../defines/cub3d.h"

static void	get_dir_e_w(t_vars *vars, t_map *map_info)
{
	if (map_info->pl_dir == 'E')
	{
		vars->pl.dirX = 1;
		vars->pl.dirY = 0;
		vars->pl.planeX = 0;	
		vars->pl.planeY = 0.66;
	}
	else if (map_info->pl_dir == 'W')
	{
		vars->pl.dirX = -1;
		vars->pl.dirY = 0;
		vars->pl.planeX = 0;	
		vars->pl.planeY = -0.66;
	}
}

static void	get_dir(t_vars *vars, t_map *map_info)
{
	if (map_info->pl_dir == 'S')
	{
		vars->pl.dirX = 0;
		vars->pl.dirY = 1;
		vars->pl.planeX = -0.66;	
		vars->pl.planeY = 0;
	}
	else if (map_info->pl_dir == 'N')
	{
		vars->pl.dirX = 0;
		vars->pl.dirY = -1;
		vars->pl.planeX = 0.66;	
		vars->pl.planeY = 0;
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
	vars->pl.mvForward = false;
	vars->pl.mvBackward = false;
	vars->pl.mvLeft = false;
	vars->pl.mvRight = false;
	vars->pl.origrotSp = FRAMETIME * 3.0;
	vars->pl.rotSp = vars->pl.origrotSp;
	vars->pl.mvSp = FRAMETIME * 5.0;
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