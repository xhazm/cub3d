#include "../defines/cub3d.h"

static void	ft_draw_y_line(t_vars *vars, int x, int texX)
{
	int				y;
	int				texY;
	double			step;
	double			texPos;
	unsigned int	*color;

	y = vars->draw.start;
	step = 1.0 * TEX_H / vars->draw.lineH;
	texPos = (vars->draw.start - IMG_H / 2 + vars->draw.lineH / 2) * step;
	while (y < vars->draw.end)
	{
		texY = (int)texPos & (TEX_H - 1);
		texPos += step;
		color = (unsigned int*)vars->texture[0].data + ((texY *
			vars->texture[0].line_length + texX * (vars->texture[0].bpp / 8)) / 4);
		my_mlx_pixel_put(vars, x, y, *color);
		y++;
	}
}

static void	ft_scale_drawing_line(t_vars *vars)
{
	vars->draw.lineH = (int)(IMG_H / vars->perpWallDist);
	vars->draw.start = -vars->draw.lineH / 2 + IMG_H / 2;
	if (vars->draw.start < 0)
		vars->draw.start = 0;
	vars->draw.end = vars->draw.lineH / 2 + IMG_H / 2;
	if (vars->draw.end >= IMG_H )
		vars->draw.end = IMG_H -1;
}

void	ft_draw_textures(t_vars *vars, int x)
{
	int		texX;
	double	wallX;

	ft_scale_drawing_line(vars);
	if (vars->ray.side == 0)
		wallX = vars->pl.y + vars->perpWallDist * vars->ray.dirY;
	else
		wallX = vars->pl.x  + vars->perpWallDist * vars->ray.dirX;
	wallX -= floor(wallX);
	texX = (int)(wallX * (double)TEX_W);
	if (vars->ray.side == 0 && vars->ray.dirX > 0)
		texX = TEX_W - texX - 1;
	if (vars->ray.side == 1 && vars->ray.dirY < 0)
		texX = TEX_W - texX - 1;
	ft_draw_y_line(vars, x, texX);
}