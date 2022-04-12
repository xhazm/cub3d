#include "../defines/cub3d.h"

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
			if (map_info->map[y / MINIMAP_S][x / MINIMAP_S] != 0
				&& map_info->map[y / MINIMAP_S][x / MINIMAP_S] != ' ')
				my_mlx_pixel_put(vars, x, y, 0x00ffffff);
			if (x / MINIMAP_S == (int)vars->pl.x && y / MINIMAP_S == (int)vars->pl.y)
				my_mlx_pixel_put(vars, x, y, 0x00ff0000);
			x++;
		}
		y++;
	}
}