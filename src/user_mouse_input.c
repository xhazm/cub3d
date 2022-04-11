#include "../defines/cub3d.h"

int	mouse_press(int keycode, int x, int y, t_vars *vars)
{
	vars->mouse.xStart = x;
	if (keycode == 1)
		vars->mouse.drag = 1;
	return (0);
}

int	mouse_release(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 1)
		vars->mouse.drag = 0;
	vars->pl.moveLeft = false;
	vars->pl.moveRight = false;
	vars->pl.rotSpeed = vars->pl.origRotSpeed;
	return (0);
}

int	mousexy_hook(int x, int y, t_vars *vars)
{
	if (vars->mouse.drag == 1)
	{
		if (vars->mouse.xStart < x)
			vars->pl.moveRight = true;
		if (vars->mouse.xStart > x)
			vars->pl.moveLeft = true;
		vars->pl.rotSpeed = fabs(ldexp(vars->mouse.xStart - x, -11));
	}
	return (0);
}