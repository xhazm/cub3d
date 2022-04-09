#include "../defines/cub3d.h"

//  case 1:  color = 0x00fe217f;    break; //red
//         case 2:  color = 0x000cc35c;  break; //green
//         case 3:  color = 0x001c26ee;   break; //blue
//         case 4:  color = 0x00a4d8d8;  break; //white
//         default: color = 0x00c7c2cb; break; //yellow
int map[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	get_dir(t_map *map_info, t_vars *vars)
{
	if (map_info->pl_dir == 'S')
	{
		vars->pl.dirX = -1;
		vars->pl.dirY = 0;
	}
	if (map_info->pl_dir == 'N')
	{
		vars->pl.dirX = 1;
		vars->pl.dirY = 0;
	}
	if (map_info->pl_dir == 'E')
	{
		vars->pl.dirX = 0;
		vars->pl.dirY = 1;
	}
	if (map_info->pl_dir == 'W')
	{
		vars->pl.dirX = 0;
		vars->pl.dirY = -1;
	}
}

static int	ft_init(t_vars *vars, t_map *map_info)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	vars->img.img = mlx_new_image(vars->mlx, IMG_W, IMG_H);
	vars->img.data.addr = mlx_get_data_addr(vars->img.img,
			&vars->img.data.bits_per_pixel, &vars->img.data.line_length,
			&vars->img.data.endian);
	vars->pl.planeX = 0;
	vars->pl.planeY = 0.66;
	get_dir(map_info, vars);
	//printf("dir x:%f, y:%f\n", vars->pl.dirX, vars->pl.dirY);
	vars->pl.x = map_info->pl_x;
	vars->pl.y = map_info->pl_y;
	vars->pl.moveForward = false;
	vars->pl.moveBackward = false;
	vars->pl.moveLeft = false;
	vars->pl.moveRight = false;
	vars->ray.hit = 0;
	vars->img.yoff = 0;
	vars->img.xoff = 0;
	vars->img.scale = vars->input.scale;
	vars->pl.rotSpeed = FRAMETIME * 3.0;
	vars->pl.moveSpeed = FRAMETIME * 5.0;
	return (SUCCESS);
}

static int exit_game(t_vars *vars)
{
	// ft_free2darr((void **)vars->mv.cords);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_draw_rays_3d(t_vars *vars, t_map *map_info)
{
	int	x;
	t_ray ray;

	x = 0;

	while(x < IMG_W)
	{
		//printf("here22\n");
		vars->ray.hit = 0;
		vars->ray.side = 0;
		vars->cameraX = 2 * x / (double)IMG_W - 1; //map_info->width right?
		vars->ray.dirX = vars->pl.dirX + vars->pl.planeX * vars->cameraX;
		vars->ray.dirY = vars->pl.dirY + vars->pl.planeY * vars->cameraX;
		vars->mapX = (int)vars->pl.x;
		vars->mapY = (int)vars->pl.y;
		//printf("pl x:%d y:%d\n", vars->mapX, vars->mapY);
		if (vars->ray.dirX == 0)
			vars->ray.deltaDistX = 1e30;
		else
			vars->ray.deltaDistX =  fabs(1 / vars->ray.dirX);
		if (vars->ray.dirY == 0)
			vars->ray.deltaDistY = 1e30;
		else
			vars->ray.deltaDistY = fabs(1 / vars->ray.dirY);
		if (vars->ray.dirX < 0)
		{
			vars->ray.stepX = -1;
			vars->ray.sideDistX = (vars->pl.x - vars->mapX) * vars->ray.deltaDistX;
		}
		else
		{
			vars->ray.stepX = 1;
			vars->ray.sideDistX = (vars->mapX + 1.0 - vars->pl.x) * vars->ray.deltaDistX;
		}
		if (vars->ray.dirY < 0)
		{
			vars->ray.stepY = -1;
			vars->ray.sideDistY = (vars->pl.y - vars->mapY) * vars->ray.deltaDistY;
		}
		else
		{
			vars->ray.stepY = 1;
			vars->ray.sideDistY = (vars->mapY + 1.0 - vars->pl.y) * vars->ray.deltaDistY;
		}
		while (vars->ray.hit == 0)
		{
			if (vars->ray.sideDistX < vars->ray.sideDistY)
			{
				vars->ray.sideDistX += vars->ray.deltaDistX;
				vars->mapX += vars->ray.stepX;
				vars->ray.side = 0;
			}
			else
			{
				vars->ray.sideDistY += vars->ray.deltaDistY;
				vars->mapY += vars->ray.stepY;
				vars->ray.side = 1;
			}
			// //printf("%d %d '%c' %d %d\n", vars->mapX, vars->mapY, map_info->map[vars->mapX][vars->mapY], map_info->height, map_info->width);
			if (map_info->map[vars->mapY][vars->mapX] > 0) // SEG FAULT 
				vars->ray.hit = 1;
		}
		//printf("lineh %f %f\n", vars->ray.deltaDistX, vars->ray.sideDistX);
		//printf("lineh %f %f\n", vars->ray.deltaDistY, vars->ray.sideDistY);
		//printf("perpwall %d %f %f %f\n",(int) vars->perpWallDist, vars->ray.sideDistY, vars->ray.deltaDistY, vars->ray.side);
		if (vars->ray.side == 0)
			vars->perpWallDist = (vars->ray.sideDistX - vars->ray.deltaDistX);
		else
			vars->perpWallDist = (vars->ray.sideDistY - vars->ray.deltaDistY);
		if (vars->perpWallDist == 0)
			vars->perpWallDist = 0;
		vars->draw.lineH = (int)(IMG_H / vars->perpWallDist);
		vars->draw.start = -vars->draw.lineH / 2 + IMG_H / 2;
		if (vars->draw.start < 0)
			vars->draw.start = 0;

		//printf("lineh:%d\tX:%d\tstart:%d\tend:%d\n",vars->draw.lineH, x, vars->draw.start, vars->draw.end, vars->draw.lineH );
		vars->draw.end = vars->draw.lineH / 2 + IMG_H / 2;
		if (vars->draw.end >= IMG_H )
			vars->draw.end = IMG_H -1;
		int color;
		switch(map_info->map[vars->mapY][vars->mapX])
     	 {
        case 1:  color = 0x00FF0000;    break; //red
        case 2:  color = 0x003cf33;  break; //green
        case 3:  color = 0x001c26ee;   break; //blue
        case 4:  color = 0x00FFFFFF;  break; //white
        default: color = 0x00e9dc43; break; //yellow
      	}
		if (vars->ray.side == 0)
		{
			bresenham(vars,x, vars->draw.start, x, vars->draw.end, color);
			// my_mlx_pixel_put(vars, x ,vars->draw.start , 0x0088ffe1);
			//printf("NS\tX:%d\tstart:%d\tend:%d\n", x, vars->draw.start, vars->draw.end);
		}
		else
		{
			//printf("EW\tX:%d\tstart:%d\tend:%d\n", x, vars->draw.start, vars->draw.end);
			// my_mlx_pixel_put(vars, x ,vars->draw.start , 0x00FF0000);
			bresenham(vars, x, vars->draw.start, x, vars->draw.end, color /2);
		}
		// my_mlx_pixel_put(vars, x ,100 , 0x00FF0000);
		//printf("here\n");
		x++;
	}
}

void	ft_move(t_vars *vars, t_map *map_info)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = vars->pl.dirX;
	oldPlaneX = vars->pl.planeX;
	vars->pl.moveSpeed = FRAMETIME *  5.0;
	vars->pl.rotSpeed = FRAMETIME *  3.0;
	if (vars->pl.moveForward == true)
	{
		if (map_info->map[(int)(vars->pl.y + vars->pl.dirX * vars->pl.moveSpeed)][(int)(vars->pl.x)] == 0)
			vars->pl.y += vars->pl.dirX * vars->pl.moveSpeed;
		if (map_info->map[(int)(vars->pl.y)][(int)(vars->pl.x + vars->pl.dirY * vars->pl.moveSpeed)] == 0)
			vars->pl.x += vars->pl.dirY * vars->pl.moveSpeed;
	}
	if (vars->pl.moveBackward == true)
	{
		if (map_info->map[(int)(vars->pl.y - vars->pl.dirX * vars->pl.moveSpeed)][(int)(vars->pl.x)] == 0)
			vars->pl.y -= vars->pl.dirX * vars->pl.moveSpeed;
		if (map_info->map[(int)(vars->pl.y)][(int)(vars->pl.x - vars->pl.dirY * vars->pl.moveSpeed)] == 0)
			vars->pl.x -= vars->pl.dirY * vars->pl.moveSpeed;
	}
	if (vars->pl.moveLeft == true)
	{
		oldDirX = vars->pl.dirX;
		vars->pl.dirX = vars->pl.dirX * cos(-vars->pl.rotSpeed) - vars->pl.dirY * sin(-vars->pl.rotSpeed);
		vars->pl.dirY = oldDirX * sin(-vars->pl.rotSpeed) + vars->pl.dirY * cos(-vars->pl.rotSpeed);
		oldPlaneX = vars->pl.planeX;
		vars->pl.planeX = vars->pl.planeX * cos(-vars->pl.rotSpeed) - vars->pl.planeY * sin(-vars->pl.rotSpeed);
		vars->pl.planeY = oldPlaneX * sin(-vars->pl.rotSpeed) + vars->pl.planeY * cos(-vars->pl.rotSpeed);
	}
	if (vars->pl.moveRight == true)
	{
		oldDirX = vars->pl.dirX;
		vars->pl.dirX = vars->pl.dirX * cos(vars->pl.rotSpeed) - vars->pl.dirY * sin(vars->pl.rotSpeed);
		vars->pl.dirY = oldDirX * sin(vars->pl.rotSpeed) + vars->pl.dirY * cos(vars->pl.rotSpeed);
		oldPlaneX = vars->pl.planeX;
		vars->pl.planeX = vars->pl.planeX * cos(vars->pl.rotSpeed) - vars->pl.planeY * sin(vars->pl.rotSpeed);
		vars->pl.planeY = oldPlaneX * sin(vars->pl.rotSpeed) + vars->pl.planeY * cos(vars->pl.rotSpeed);
	}
}

int draw_player(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, IMG_W, IMG_W);
	vars->img.data.addr = mlx_get_data_addr(vars->img.img,
		&vars->img.data.bits_per_pixel, &vars->img.data.line_length,
		&vars->img.data.endian);
	ft_draw_rays_3d(vars, vars->map_info);
	ft_move(vars, vars->map_info);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_map	map_info;

	if (parser(argc, argv, &map_info) == FAIL)
		return (1);
	if (ft_init(&vars, &map_info) == FAIL)
		return (1);
	print_map(map_info.map, map_info.height, &map_info);
	vars.map_info = &map_info;
	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, &vars);
	mlx_hook(vars.win, X_EVENT_EXIT, 1L << 17, &exit_game, &vars);
	mlx_loop_hook(vars.mlx, draw_player, &vars);
	mlx_loop(vars.mlx);
}
