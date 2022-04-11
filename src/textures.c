#include "../defines/cub3d.h"

static int	ft_pick_texture(t_vars *vars)
{
	int	texNum;
	if (vars->isSprite == 0)
	{
		if (vars->ray.side == 1 && vars->ray.dirY < 0)
			texNum = E_WALL_N;
		else if (vars->ray.side == 1 && vars->ray.dirY > 0)
			texNum = E_WALL_S;
		else if (vars->ray.side == 0 && vars->ray.dirX < 0)
			texNum = E_WALL_W; 
		else if (vars->ray.side == 0 && vars->ray.dirX > 0)
			texNum = E_WALL_E;
	// if (vars->map_info->map[vars->mapY][vars->mapX] == 'T')
	// 	texNum = E_DOOR;
	}
	else if (vars->isSprite == 1)
	{
		if (vars->spriteC < 100)
			texNum = 0;
		else if (vars->spriteC < 200)
			texNum = 1;
		else if (vars->spriteC < 300)
			texNum = 2;
		else if (vars->spriteC > 300)
		{
			texNum = 0;
			vars->spriteC = 0;
		}
	}

	return (texNum);
}

static unsigned int	ft_pick_tex_color(t_texture tex, int x, int y)
{
	unsigned int	*color;

	color = (unsigned int*)tex.data + ((y
				* tex.line_length + x * (tex.bpp / 8)) / 4);
	return (*color);
}

static void	ft_draw_y_line(t_vars *vars, int x, int texX, t_texture *tex)
{
	int				y;
	int				texY;
	int				texNum;
	double			step;
	double			texPos;
	unsigned int	color;

	y = 1;
	step = 1.0 * TEX_H / vars->draw.lineH;
	texPos = (vars->draw.start - IMG_H / 2 + vars->draw.lineH / 2) * step;
	texNum = ft_pick_texture(vars);
	while (y < IMG_H - 1)
	{
		if (y > vars->draw.start && y < vars->draw.end)
		{
			texY = (int)texPos & (TEX_H - 1);
			texPos += step;
			color = ft_pick_tex_color(tex[texNum], texX, texY);
			if (vars->isSprite == 0 || vars->isSprite == 1 && color != 0xff000000)
				my_mlx_pixel_put(vars, x, y, color);
		}
		else if (vars->isSprite == 0)
		{
			if (y > vars->draw.start)
			my_mlx_pixel_put(vars, x, y, vars->map_info->floor_color);
			else if (y < vars->draw.end)
			my_mlx_pixel_put(vars, x, y, vars->map_info->ceiling_color);
		}
		y++;
	}
	// if (vars->map_info->map[vars->mapY][vars->mapX] == 'T')
		// ft_draw_sprite(vars, x, texX);
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

void	ft_draw_textures(t_vars *vars, int x, t_texture *texture)
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
	ft_draw_y_line(vars, x, texX, texture);
}