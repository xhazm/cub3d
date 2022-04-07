#include "../defines/cub3d.h"

int	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || y > WIN_HEIGHT || y < 0 || x < 0 || x > IMG_W || y > IMG_H)
		return (1);
	// if (vars->input.color)
	// 	color = vars->input.color;
	// else
	// 	color = 0x00AAAAAA + (color * 5000);
	dst = vars->img.data.addr + (y * vars->img.data.line_length + x
			* (vars->img.data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (1);
}

void bresenham(t_vars *vars, int x0, int y0, int x1, int y1, int color)
{
  int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int err = dx+dy, e2; /* error value e_xy */

  while (1) {
	if (color == -1)
		my_mlx_pixel_put(vars, x0 ,y0 , 0x00FF0000);
	else
		my_mlx_pixel_put(vars, x0 ,y0 , color);
    if (x0==x1 && y0==y1) break;
    e2 = 2*err;
    if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

// void drawRays3D(t_vars *vars)
// {
// 	t_rays	rays;
// 	float aTan;
// 	int my;

// 	ft_init_rays(&rays);
// 	rays.ra = pa;
// 	//Horizontal lines
// 	// for(rays.r = 0; rays.r < 1; rays.r++)
// 	// {
// 		rays.dof = 0;
// 		if (rays.ra == 0)
// 			rays.ra += 0.1;
// 			aTan = -1/tan(rays.ra);
// 		if (rays.ra > M_PI)
// 		{
// 			rays.ry = (((int)py/MAP_S)*MAP_S) - 0.0001;
// 			rays.rx = (py - rays.ry) * aTan + px;
// 			rays.yo = -MAP_S;
// 			rays.xo = - rays.yo * aTan;
// 		}
// 		if (rays.ra < M_PI)
// 		{
// 			rays.ry = (((int)py/MAP_S)*MAP_S) + MAP_S;
// 			rays.rx = (py - rays.ry) * aTan + px;
// 			rays.yo = MAP_S;
// 			rays.xo = - rays.yo * aTan;
// 		}
// 		if (rays.ra == M_PI || rays.ra == 0) //looking straight left/right
// 		{
// 			printf("mpi\n");
// 			rays.ra += 0.1;
// 			rays.rx = px;
// 			rays.ry = py;
// 			rays.dof = 21;
// 		}
// 		while (rays.dof < 21)
// 		{
// 			rays.mx = (int) (rays.rx) / MAP_S;
// 			rays.my = (int)(rays.ry) / MAP_S;
// 			rays.mp = rays.my * MAP_W + rays.mx;
// 			if (rays.mp < MAP_W * MAP_H && (rays.mx / MAP_S) < MAP_W - 1 && (rays.my / MAP_S) < MAP_H - 1 && map[rays.my][rays.mx] == 1)
// 			{
// 				printf("mpi2 %f\n", rays.ra);
// 				rays.dof = 21;
// 				return ;
// 			}
// 			else
// 			{
// 				rays.rx += rays.xo;
// 				rays.ry += rays.yo;
// 				rays.dof += 1;
// 			}
// 			my_mlx_pixel_put(vars, rays.rx ,rays.ry , 0x00FF0000);
// 			// if (rays.old_rx != 0 && rays.old_ry != 0)
// 			// {
// 			// 	bresenham(vars, rays.old_rx, rays.old_ry, rays.rx, rays.ry);
// 			// }
// 			// else
// 			// 	bresenham(vars, px, py, rays.rx, rays.ry);
// 			rays.old_rx = rays.rx;
// 			rays.old_ry = rays.ry;
// 		}
// 	// }
// }

//draw minimap player
	// for(int i = -5; i < 5; i++)
	// {
	// 	for(int j = -5; j < 5; j++)
	// 	{
	// 		my_mlx_pixel_put(vars, px +  i, py + j, 0x00FF0000);
	// 		for (int h = 0; h < 80; h++)
	// 		{
	// 			//my_mlx_pixel_put(vars, px+pdx*h ,py+pdy*h, 0x00FF0000);
	// 		}
	// 	}
	// }


// int draw_minimap(t_vars *vars)
// {
// 	int xo = 0;
// 	int yo = 0;

// 	for(int y = 0; y < MAP_H; y++)
// 	{
// 		for(int x = 0; x < MAP_W; x++)
// 		{
// 			xo = x * MAP_S;
// 			yo = y * MAP_S;
// 			if (map[y][x] >= 1)
// 			{
// 				if (x < MAP_W - 1 && map[y][x+ 1] >= 1)
// 				{
// 					for(int h = 0; h < MAP_S; h++)
// 						my_mlx_pixel_put(vars, xo + h, yo, 0x000FFAAA);
// 					// if (xo >= 1200 || yo >= 1200)
// 					// 	printf("%d %d\n",xo, yo);
// 				}
// 				if (y < MAP_H - 1 && map[y + 1][x] >= 1)
// 				{
// 					for(int h = 0; h < MAP_S; h++)
// 						my_mlx_pixel_put(vars, xo, yo + h, 0x000FFAAA);
// 					// if (xo >= 1200 || yo >= 1200)
// 					// 	printf("%d %d\n",xo, yo);
// 				}
// 			}
// 			my_mlx_pixel_put(vars, xo, yo, 0x0088ffe1);
// 		}
// 	}
// }
