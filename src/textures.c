#include "../defines/cub3d.h"

int	ft_init_textures(t_vars *vars)
{

	vars->texture[0].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bricks.xpm", &vars->texture[0].width, &vars->texture[0].width);
	if (vars->texture[0].img_ptr == NULL)
		return (FAIL);
	vars->texture[0].data = mlx_get_data_addr(vars->texture[0].img_ptr,
		&vars->texture[0].bpp, &vars->texture[0].line_length,
		&vars->texture[0].endian);
	return (SUCCESS);
}

void	ft_draw_textures(t_vars *vars, int x)
{
	double wallX;
	if (vars->ray.side == 0)
		wallX = vars->pl.y + vars->perpWallDist * vars->ray.dirY;
	else
		wallX = vars->pl.x  + vars->perpWallDist * vars->ray.dirX;
	wallX -= floor(wallX);
	int texX = (int)(wallX * (double)TEX_W);
	if (vars->ray.side == 0 && vars->ray.dirX > 0)
		texX = TEX_W - texX - 1;
	if (vars->ray.side == 1 && vars->ray.dirY < 0)
		texX = TEX_W - texX - 1;
	double	step = 1.0 * TEX_H / vars->draw.lineH;
	double	texPos = (vars->draw.start - IMG_H / 2 + vars->draw.lineH / 2) * step;
	int y = vars->draw.start;
	unsigned int *color;
	while (y < vars->draw.end)
	{
		int texY = (int)texPos & (TEX_H - 1);
		texPos += step;
		color = (unsigned int*)vars->texture[0].data + ((texY * vars->texture[0].line_length + texX
				* (vars->texture[0].bpp / 8)) / 4);
		my_mlx_pixel_put(vars, x, y, *color);
		y++;
	}
}