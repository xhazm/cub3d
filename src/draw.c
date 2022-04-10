#include "../defines/cub3d.h"

int	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || y > WIN_HEIGHT || y < 0 || x < 0 || x > IMG_W || y > IMG_H)
		return (1);
	dst = vars->img.data.addr + (y * vars->img.data.line_length + x
			* (vars->img.data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (1);
}