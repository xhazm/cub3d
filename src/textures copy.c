#include "../defines/cub3d.h"

static void	ft_draw_y_line(t_vars *vars, int x)
{
	int y;
	int texY;
	unsigned int *color;

	y = vars->tex_draw.start;
	while (y < vars->tex_draw.end)
	{
		texY = (int)vars->tex_draw.texPos & (TEX_H - 1);
		vars->tex_draw.texPos += vars->tex_draw.step;
		color = (unsigned int*)vars->tex_data[0].data + ((texY * vars->tex_data[0].line_length + vars->tex_draw.texX
				* (vars->tex_data[0].bpp / 8)) / 4);
		my_mlx_pixel_put(vars, x, y, *color);
		y++;
	}
}

static void	ft_scale_drawing_line(t_vars *vars)
{
	vars->tex_draw.lineH = (int)(IMG_H / vars->perpWallDist);
	vars->tex_draw.start = -vars->tex_draw.lineH / 2 + IMG_H / 2;
	if (vars->tex_draw.start < 0)
		vars->tex_draw.start = 0;
	vars->tex_draw.end = vars->tex_draw.lineH / 2 + IMG_H / 2;
	if (vars->tex_draw.end >= IMG_H )
		vars->tex_draw.end = IMG_H -1;
}

int	ft_init_textures(t_vars *vars)
{
	vars->tex_data[0].img_ptr = mlx_xpm_file_to_image(vars->mlx, "./textures/bricks.xpm", &vars->tex_data[0].width, &vars->tex_data[0].width);
	if (vars->tex_data[0].img_ptr == NULL)
		return (FAIL);
	vars->tex_data[0].data = mlx_get_data_addr(vars->tex_data[0].img_ptr,
		&vars->tex_data[0].bpp, &vars->tex_data[0].line_length,
		&vars->tex_data[0].endian);
	return (SUCCESS);
}

int	ft_draw_textures(t_vars *vars, int x)
{
	ft_scale_drawing_line(vars);
	if (vars->ray.side == 0)
		vars->tex_draw.drawX = vars->pl.y + vars->perpWallDist * vars->ray.dirY;
	else
		vars->tex_draw.drawX = vars->pl.x  + vars->perpWallDist * vars->ray.dirX;
	vars->tex_draw.drawX -= floor(vars->tex_draw.drawX);
	vars->tex_draw.texX = (int)(vars->tex_draw.drawX * (double)TEX_W);
	if (vars->ray.side == 0 && vars->ray.dirX > 0)
		vars->tex_draw.texX = TEX_W - vars->tex_draw.texX - 1;
	if (vars->ray.side == 1 && vars->ray.dirY < 0)
		vars->tex_draw.texX = TEX_W - vars->tex_draw.texX - 1;
	vars->tex_draw.step = 1.0 * TEX_H / vars->tex_draw.lineH;
	vars->tex_draw.texPos = (vars->tex_draw.start - IMG_H / 2 + vars->tex_draw.lineH / 2) * vars->tex_draw.step;
	ft_draw_y_line(vars, x);
}