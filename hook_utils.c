#include "head_main.h"

void	ft_down(t_vars *vars)
{
	int		matrx;
	float	xnext;
	float	ynext;

	xnext = vars->x_f - cos(vars->angle) * 0.6;
	ynext = vars->y_f - sin(vars->angle) * 0.6;
	matrx = (int)xnext + (int)ynext * vars->xchars;
	while (vars->map[matrx] != '0')
	{
		xnext += cos(vars->angle) * 0.1;
		ynext += sin(vars->angle) * 0.1;
		matrx = (int)xnext + (int)ynext * vars->xchars;
	}
	xnext += cos(vars->angle) * 0.2;
	ynext += sin(vars->angle) * 0.2;
	vars->x_f = xnext;
	vars->y_f = ynext;
	ft_raycast(vars);
}

void	ft_up(t_vars *vars)
{
	int		matrx;
	float	xnext;
	float	ynext;

	xnext = vars->x_f + cos(vars->angle) * 0.6;
	ynext = vars->y_f + sin(vars->angle) * 0.6;
	matrx = (int)xnext + (int)ynext * vars->xchars;
	while (vars->map[matrx] != '0')
	{
		xnext -= cos(vars->angle) * 0.1;
		ynext -= sin(vars->angle) * 0.1;
		matrx = (int)xnext + (int)ynext * vars->xchars;
	}
	xnext -= cos(vars->angle) * 0.2;
	ynext -= sin(vars->angle) * 0.2;
	vars->x_f = xnext;
	vars->y_f = ynext;
	ft_raycast(vars);
}

void	ft_right_or_left(t_vars *vars, int or)
{
	if (or > 0)
		vars->angle += M_PI / 40;
	else
		vars->angle -= M_PI / 40;
	ft_raycast(vars);
}

void	ft_right_or_left_step(t_vars *vars, double mpi2)
{
	int		matrx;
	float	xnext;
	float	ynext;

	xnext = vars->x_f + cos(vars->angle + mpi2) * 0.6;
	ynext = vars->y_f + sin(vars->angle + mpi2) * 0.6;
	matrx = (int)xnext + (int)ynext * vars->xchars;
	while (vars->map[matrx] != '0')
	{
		xnext -= cos(vars->angle + mpi2) * 0.1;
		ynext -= sin(vars->angle + mpi2) * 0.1;
		matrx = (int)xnext + (int)ynext * vars->xchars;
	}
	xnext -= cos(vars->angle + mpi2) * 0.2;
	ynext -= sin(vars->angle + mpi2) * 0.2;
	vars->x_f = xnext;
	vars->y_f = ynext;
	ft_raycast(vars);
}

int	step_and_direct(int keycode, t_vars *vars)
{
	if (keycode == 82)
		ft_raycast(vars);
	if (keycode == 123)
		ft_right_or_left(vars, -1);
	if (keycode == 124)
		ft_right_or_left(vars, 1);
	if (keycode == 1)
		ft_down(vars);
	if (keycode == 13)
		ft_up(vars);
	if (keycode == 2)
		ft_right_or_left_step(vars, M_PI_2);
	if (keycode == 0)
		ft_right_or_left_step(vars, -M_PI_2);
	return (0);
}
