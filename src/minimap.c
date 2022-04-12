#include "../defines/cub3d.h"

static void	ft_minimap_player(t_vars *vars,t_map *map_info)
{
	int	x;
	int	y;

	x = -(MINIMAP_S / 2);
	y = -(MINIMAP_S / 2);
	while (y < MINIMAP_S / 2)
	{
		x = -(MINIMAP_S / 2);
		while (x < MINIMAP_S / 2)
		{
			my_mlx_pixel_put(vars, (int)(vars->pl.x * MINIMAP_S) + x,
				(int)(vars->pl.y * MINIMAP_S) + y, 0x00ff0000);
			x++;
		}
		y++;
	}
}

void	ft_minimap(t_vars *vars, t_map *map_info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < (map_info->height * MINIMAP_S))
	{
		x = 0;
		while (x < (map_info->width * MINIMAP_S))
		{
			if (map_info->map[y / MINIMAP_S][x / MINIMAP_S] == 1)
				my_mlx_pixel_put(vars, x, y, 0x00fff7cc);
			else if(map_info->map[y / MINIMAP_S][x / MINIMAP_S] == 'T')
				my_mlx_pixel_put(vars, x, y, 0x00ff9933);
			else if(map_info->map[y / MINIMAP_S][x / MINIMAP_S] == -'R')
				my_mlx_pixel_put(vars, x, y, 0x00ffffff);
			x++;
		}
		y++;
	}
	ft_minimap_player(vars, map_info);
}