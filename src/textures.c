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