#include "cub3d.h"
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

static void	ft_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	vars->img.img = mlx_new_image(vars->mlx, IMG_W, IMG_H);
	vars->img.data.addr = mlx_get_data_addr(vars->img.img,
			&vars->img.data.bits_per_pixel, &vars->img.data.line_length,
			&vars->img.data.endian);
	vars->pl.x = 12;
	vars->pl.y = 12;
	vars->pl.planeX = 0;
	vars->pl.planeY = 0.66;
	vars->pl.dirX = 1;
	vars->pl.dirY = 0;
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
}

static void exit_game(t_vars *vars)
{
	// ft_free2darr((void **)vars->mv.cords);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_draw_rays_3d(t_vars *vars)
{
	int	x;
	t_ray ray;

	x = 0;
	while(x < IMG_W)
	{
		vars->ray.hit = 0;
		vars->ray.side = 0;
		vars->cameraX = 2 * x / (double)IMG_W - 1; //IMG_W right?
		vars->ray.dirX = vars->pl.dirX + vars->pl.planeX * vars->cameraX;
		vars->ray.dirY = vars->pl.dirY + vars->pl.planeY * vars->cameraX;
		vars->mapX = (int)vars->pl.x;
		vars->mapY = (int)vars->pl.y;
		if (vars->ray.dirX == 0) //righty right?
			vars->ray.deltaDistX = 1e30;
		else
			vars->ray.deltaDistX =  fabs(1 / vars->ray.dirX);//
		if (vars->ray.dirY == 0) //righty right?
			vars->ray.deltaDistY = 1e30;
		else
			vars->ray.deltaDistY = fabs(1 / vars->ray.dirY);//
		if (vars->ray.dirX < 0)
		{
			vars->ray.stepX = -1;
			vars->ray.sideDistX = (vars->pl.x - vars->mapX) * vars->ray.deltaDistX;
		}
		else
		{
			vars->ray.stepX = 1;
			vars->ray.sideDistX = (vars->mapX + 0.1 - vars->pl.x) * vars->ray.deltaDistX;
		}
		if (vars->ray.dirY < 0)
		{
			vars->ray.stepY = -1;
			vars->ray.sideDistY = (vars->pl.y - vars->mapY) * vars->ray.deltaDistY;
		}
		else
		{
			vars->ray.stepY = 1;
			vars->ray.sideDistY = (vars->mapY + 0.1 - vars->pl.y) * vars->ray.deltaDistY;
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
			if (map[vars->mapX][vars->mapY] > 0)
				vars->ray.hit = 1;
		}
		// printf("lineh %f %f\n", vars->ray.deltaDistX, vars->ray.sideDistX);
		if (vars->ray.side == 0)
			vars->perpWallDist = (vars->ray.sideDistX - vars->ray.deltaDistX);
		else
			vars->perpWallDist = (vars->ray.sideDistY - vars->ray.deltaDistY);
		vars->draw.lineH = (int)(IMG_H / vars->perpWallDist);
		// printf("lineh %d %d\n", vars->draw.lineH,(int) vars->perpWallDist);
		vars->draw.start = -vars->draw.lineH / 2 + IMG_H / 2;
		if (vars->draw.start < 0)
			vars->draw.start = 0;
		vars->draw.end = vars->draw.lineH / 2 + IMG_H / 2;
		if (vars->draw.end >= IMG_H)
			vars->draw.end = IMG_H -1;
		int color;
		switch(map[vars->mapX][vars->mapY])
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
			// printf("NS\tX:%d\tstart:%d\tend:%d\n", x, vars->draw.start, vars->draw.end);
		}
		else
		{
			// printf("EW\tX:%d\tstart:%d\tend:%d\n", x, vars->draw.start, vars->draw.end);
			// my_mlx_pixel_put(vars, x ,vars->draw.start , 0x00FF0000);
			bresenham(vars, x, vars->draw.start, x, vars->draw.end, color /2);
		}
		// my_mlx_pixel_put(vars, x ,100 , 0x00FF0000);
		x++;
	}
}

void	ft_move(t_vars *vars)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = vars->pl.dirX;
	oldPlaneX = vars->pl.planeX;
	vars->pl.moveSpeed = FRAMETIME *  5.0;
	vars->pl.rotSpeed = FRAMETIME *  3.0;
	if (vars->pl.moveForward == true)
	{
		if (map[(int)(vars->pl.x + vars->pl.dirX * vars->pl.moveSpeed)][(int)(vars->pl.y)] == 0)
			vars->pl.x += vars->pl.dirX * vars->pl.moveSpeed;
		if (map[(int)(vars->pl.x)][(int)(vars->pl.y + vars->pl.dirY * vars->pl.moveSpeed)] == 0)
			vars->pl.y += vars->pl.dirY * vars->pl.moveSpeed;
	}
	if (vars->pl.moveBackward == true)
	{
		if (map[(int)(vars->pl.x - vars->pl.dirX * vars->pl.moveSpeed)][(int)(vars->pl.y)] == 0)
			vars->pl.x -= vars->pl.dirX * vars->pl.moveSpeed;
		if (map[(int)(vars->pl.x)][(int)(vars->pl.y - vars->pl.dirY * vars->pl.moveSpeed)] == 0)
			vars->pl.y -= vars->pl.dirY * vars->pl.moveSpeed;
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
	vars->img.img = mlx_new_image(vars->mlx, IMG_W, IMG_H);
	vars->img.data.addr = mlx_get_data_addr(vars->img.img,
		&vars->img.data.bits_per_pixel, &vars->img.data.line_length,
		&vars->img.data.endian);
	ft_draw_rays_3d(vars);
	ft_move(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

int	main(void)
{
	t_vars vars;

	ft_init(&vars);

	mlx_hook(vars.win, X_EVENT_KEY_PRESS, 0, &key_press, &vars);
	mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 0, &key_release, &vars);
	mlx_hook(vars.win, X_EVENT_EXIT, 0, &exit_game, &vars);
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, draw_player, &vars);
	mlx_loop(vars.mlx);
}