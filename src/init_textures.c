/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elenz <elenz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:44:41 by lpfleide          #+#    #+#             */
/*   Updated: 2022/04/28 17:54:13 by elenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../defines/cub3d.h"

static int	ft_get_texture_data(t_texture *texture, int texnumber)
{
	int	i;

	i = 0;
	while (i < texnumber)
	{
		if (texture[i].img_ptr == NULL)
			return (FAIL);
		texture[i].data = mlx_get_data_addr(texture[i].img_ptr,
				&texture[i].bpp, &texture[i].line_length,
				&texture[i].endian);
		i++;
	}
	return (SUCCESS);
}

static void	ft_xpm_to_img(t_vars *vars, t_texture *tex, char *str)
{
	tex->img_ptr = mlx_xpm_file_to_image(vars->mlx, str,
			&tex->width, &tex->height);
}

int	ft_init_textures(t_vars *vars, t_map *map_info)
{
	ft_xpm_to_img(vars, &vars->sprite[0], "./textures/bunny0.xpm");
	ft_xpm_to_img(vars, &vars->sprite[1], "./textures/bunny1.xpm");
	ft_xpm_to_img(vars, &vars->sprite[2], "./textures/bunny2.xpm");
	ft_xpm_to_img(vars, &vars->sprite[3], "./textures/bunny3.xpm");
	ft_xpm_to_img(vars, &vars->texture[E_WALL_N], map_info->no_path);
	ft_xpm_to_img(vars, &vars->texture[E_WALL_S], map_info->so_path);
	ft_xpm_to_img(vars, &vars->texture[E_WALL_W], map_info->we_path);
	ft_xpm_to_img(vars, &vars->texture[E_WALL_E], map_info->ea_path);
	ft_xpm_to_img(vars, &vars->texture[E_DOOR], "./textures/bookshelf.xpm");
	if (ft_get_texture_data(vars->sprite, 4) == FAIL)
		return (FAIL);
	if (ft_get_texture_data(vars->texture, 5) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
