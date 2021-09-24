#include "head_main.h"

void	minimap_add(t_vars *vars, int a, int b, int matr)
{
	int		ax;
	int		by;

	ax = (XSIZE / 6 ) / vars->xchars;
	by = (YSIZE / 6 ) / vars->ylines;
	while (++a < 99)
	{
		b = -1;
		while (++b < 99)
		{
			matr = (a / ax) + (b / by) * vars->xchars;
			if (vars->map[matr] == '1')
			{
				another_vars.my_im_d[(b * YSIZE + a) * 4] = 88;
				another_vars.my_im_d[(b * YSIZE + a) * 4 + 3] = -1;
			}
			else if (vars->map[matr] == '0')
				another_vars.my_im_d[(b * YSIZE + a) * 4] = 127;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, another_vars.img_ptr, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pers_mini_ptr, another_vars.x_f * ax,  another_vars.y_f * by);
}


void	ft_ray_floor_sky(int high, int ugol, t_vars *vars)
{
	int		nebo;
	float	matrix;

	nebo = 0;
	while (nebo + high / 2 < 300)
	{
		matrix = 300 + ugol + (300 - high / 2 - nebo) * XSIZE;
		another_vars.my_im_d[(int) matrix * 4] = vars->ceilling >> 16;
		another_vars.my_im_d[((int) matrix) * 4 + 1] = vars->ceilling >> 8;
		another_vars.my_im_d[((int) matrix) * 4 + 2] = vars->ceilling;
		matrix = 300 + ugol + (300 + high / 2 + nebo)* XSIZE;
		another_vars.my_im_d[((int) matrix) * 4] = vars->floor >> 16;
		another_vars.my_im_d[((int) matrix) * 4 + 1] = vars->floor >> 8;
		another_vars.my_im_d[((int) matrix) * 4 + 2] = vars->floor;
		nebo++;
	}
}

/*
void	cos_p_sin_min(t_vars *vars, int ugol, double sinu, double cosi)
{
	sinu = 0.0 - sinu;
	while ((i < vars->ylines) && (i2 < vars->xchars))
	{
		if ((((d_y + i) * cosi / sinu) <= (1 - d_x + i2)) && ((d_y + i ) <= ((1 - d_x + i2) * sinu / cosi)))
		{
			if (vars->map[(int)(vars->xchars * ((int)y - i - 1) + (int)(another_vars.x_f + (d_y + i) * cosi / sinu))] != '0')
			{
				high_f = ((d_y + i) / sinu) * cos(abs(ugol) * M_PI / 1800.0);
				flag = vars->north;
				xpm = 64 * ((another_vars.x_f + (d_y + i) * cosi / sinu) - (int)(another_vars.x_f + (d_y + i) * cosi / sinu));
				break ;
			}
			i++;
		}
		else
		{
			if (vars->map[(int)(vars->xchars * ((int)(- (1 - d_x + i2) * sinu / cosi + y)) + 1 + i2 + (int)another_vars.x_f)] != '0')
			{
				high_f = ((1.0 - d_x + i2) / cosi) * cos(abs(ugol) * M_PI / 1800.0);
				flag = vars->west;
				xpm = 64 * (- (1 - d_x + i2) * sinu / cosi + y - (int)(- (1 - d_x + i2) * sinu / cosi + y));
				break ;
			}
			i2++;
		}
	}
}
*/

void	ft_raycast(t_vars *vars)
{
		int high;
		float high_f = 1.0;
		int ugol = -299;
		float xpm;
		float y = another_vars.y_f;
		double cosi;
		double sinu;
		char *flag;
		int i;
		int i2;
		float d_y = - (int)y + y;
		float d_x = - (int)another_vars.x_f + another_vars.x_f;
	while (ugol < 299)
	{
		i = 0;
		i2 = 0;
		flag = 0;
		high = 300;
		xpm = 0.0;
		cosi = cos(vars->angle + ugol * M_PI / 1800.0);
		sinu = sin(vars->angle + ugol * M_PI / 1800.0);
			if (cosi > 0.0)
			{
				if (sinu < 0.0)
				{
					sinu = 0.0 - sinu;
					while ((i < vars->ylines) && (i2 < vars->xchars))
					{
						if ((((d_y + i) * cosi / sinu) <= (1 - d_x + i2)) && ((d_y + i ) <= ((1 - d_x + i2) * sinu / cosi)))
						{
							if (vars->map[(int)(vars->xchars * ((int)y - i - 1) + (int)(another_vars.x_f + (d_y + i) * cosi / sinu))] != '0')
							{
								high_f = ((d_y + i) / sinu) * cos(abs(ugol) * M_PI / 1800.0);
								flag = vars->north;
								xpm = 64 * ((another_vars.x_f + (d_y + i) * cosi / sinu) - (int)(another_vars.x_f + (d_y + i) * cosi / sinu));
								break ;
							}
							i++;
						}
						else
						{
							if (vars->map[(int)(vars->xchars * ((int)(- (1 - d_x + i2) * sinu / cosi + y)) + 1 + i2 + (int)another_vars.x_f)] != '0')
							{
								high_f = ((1.0 - d_x + i2) / cosi) * cos(abs(ugol) * M_PI / 1800.0);
								flag = vars->west;
								xpm = 64 * (- (1 - d_x + i2) * sinu / cosi + y - (int)(- (1 - d_x + i2) * sinu / cosi + y));
								break ;
							}
							i2++;
						}
					}
				}
				else
				{
					while ((i < vars->ylines) && (i2 < vars->xchars))
					{
						if ((((1 - d_y + i) * cosi / sinu) <= (1 - d_x + i2)) && ((1 - d_y + i ) <= ((1 - d_x + i2) * sinu / cosi)))
						{
							if (vars->map[(int)(vars->xchars * ((int)y + 1 + i) + another_vars.x_f + (1 - d_y + i) * cosi / sinu)] != '0')
							{
								high_f = (1.0 - d_y + i) / sinu * cos(abs(ugol) * M_PI / 1800.0);
								flag = vars->south;
								xpm = 64 * (another_vars.x_f + (1 - d_y + i) * cosi / sinu - (int)(another_vars.x_f + (1 - d_y + i) * cosi / sinu));
								break ;
							}
							i++;
						}
						else
						{
							if (vars->map[(int)(vars->xchars * (int)((1 - d_x + i2) * sinu / cosi + y) + 1 + i2 + (int)another_vars.x_f)] != '0')
							{
								high_f = (1.0 - d_x + i2) / cosi * cos(abs(ugol) * M_PI / 1800.0);
								flag = vars->west;
								xpm = 64 * ((1 - d_x + i2) * sinu / cosi + y - (int)((1 - d_x + i2) * sinu / cosi + y));
								break ;
							}
							i2++;
						}
					}
				}
			}
		else
		{
			cosi = 0.0 - cosi;
			if (sinu < 0)
			{
				sinu = 0.0 - sinu;
				while ((i < vars->ylines) && (i2 < vars->xchars))
				{
					if ((((d_y + i) * cosi / sinu) <= (d_x + i2)) && ((d_y + i ) <= ((d_x + i2) * sinu / cosi)))
					{
						if (vars->map[(int)(vars->xchars * ((int)y - i - 1) + (int)((another_vars.x_f - (d_y + i) * cosi / sinu)))] != '0')
						{
							high_f = ((d_y + i) / sinu) * cos(abs(ugol) * M_PI / 1800.0);
							flag = vars->north;
							xpm = 64 * (another_vars.x_f - (d_y + i) * cosi / sinu - (int)(another_vars.x_f - (d_y + i) * cosi / sinu));
							break ;
						}
						i++;
					}
					else
					{
						if (vars->map[(int)(vars->xchars * ((int)(- (d_x + i2) * sinu / cosi + y)) - i2 + (int)another_vars.x_f) - 1] != '0')
						{
							high_f = (d_x + i2) / cosi * cos(abs(ugol) * M_PI / 1800.0);
							flag = vars->east;
							xpm = 64 * ((- (d_x + i2) * sinu / cosi + y) - (int)(- (d_x + i2) * sinu / cosi + y));
							break ;
						}
						i2++;
					}
				}
			}
			else
			{
					while ((i < vars->ylines) && (i2 < vars->xchars))
					{
						if ((((1.0 - d_y + i) * cosi / sinu) <= (d_x + i2)) && ((1.0 - d_y + i ) <= ((d_x + i2) * sinu / cosi)))
						{
							if (vars->map[(int)(vars->xchars * ((int)y + 1 + i) + (int)(another_vars.x_f - (1.0 - d_y + i) * cosi / sinu))] != '0')
							{
								high_f = ((1.0 - d_y + i) / sinu) * cos(abs(ugol) * M_PI / 1800.0);
								flag = vars->south;
								xpm = 64 * (another_vars.x_f - (1.0 - d_y + i) * cosi / sinu - (int)(another_vars.x_f - (1.0 - d_y + i) * cosi / sinu));
								break ;
							}
							i++;
						}
						else
						{
							if (vars->map[(int)(vars->xchars * ((int)((d_x + i2) * sinu / cosi + y)) - i2 + (int)another_vars.x_f) - 1] != '0')
							{
								high_f = (d_x + i2) / cosi* cos(abs(ugol) * M_PI / 1800.0);
								flag = vars->east;
								xpm = 64 * ((d_x + i2) * sinu / cosi + y - (int)((d_x + i2) * sinu / cosi + y));
								break ;
							}
							i2++;
						}
					}
			}
		}
		high = 600 / (1.0 + high_f);
		if (high < 0)
			high = 0;
		else if (high > 599)
			high = 599;
		ft_ray_floor_sky(high, ugol, vars);
		ft_line(vars, high, (int)xpm, ugol + 300, flag);
		ugol++;
	}
	minimap_add(vars, -1, 0, 0);
}

void	ft_right_or_left(t_vars *vars, int or)
{
	if (or > 0)
		vars->angle += M_PI / 20;
	else
		vars->angle -= M_PI / 20;
	ft_raycast(vars);
}

void	ft_down(t_vars *vars)
{
	int		matrx;
	float	xnext;
	float	ynext;

	xnext = another_vars.x_f - cos(vars->angle);
	ynext = another_vars.y_f - sin(vars->angle);
	matrx = (int)xnext + (int)ynext * vars->xchars;
	while (vars->map[matrx] != '0')
	{
		xnext += cos(vars->angle) * 0.1;
		ynext += sin(vars->angle) * 0.1;
		matrx = (int)xnext + (int)ynext * vars->xchars;
	}
	xnext += cos(vars->angle) * 0.5;
	ynext += sin(vars->angle) * 0.5;
	another_vars.x_f = xnext;
	another_vars.y_f = ynext;
	ft_raycast(vars);
}

void	ft_up(t_vars *vars)
{
	int		matrx;
	float xnext;
	float ynext;

	xnext = another_vars.x_f + cos(vars->angle);
	ynext = another_vars.y_f + sin(vars->angle);
	matrx = (int)xnext + (int)ynext * vars->xchars;
	while (vars->map[matrx] != '0')
	{
		xnext -= cos(vars->angle) * 0.1;
		ynext -= sin(vars->angle) * 0.1;
		matrx = (int)xnext + (int)ynext * vars->xchars;
	}
	xnext -= cos(vars->angle) * 0.5;
	ynext -= sin(vars->angle) * 0.5;
	another_vars.x_f = xnext;
	another_vars.y_f = ynext;
	ft_raycast(vars);
}

void	ft_right_or_left_step(t_vars *vars, double mpi2)
{
	int		matrx;
	float	xnext;
	float	ynext;

	xnext = another_vars.x_f + cos(vars->angle + mpi2);
	ynext = another_vars.y_f + sin(vars->angle + mpi2);
	matrx = (int)xnext + (int)ynext * vars->xchars;
	while (vars->map[matrx] != '0')
	{
		xnext -= cos(vars->angle + mpi2) * 0.1;
		ynext -= sin(vars->angle + mpi2) * 0.1;
		matrx = (int)xnext + (int)ynext * vars->xchars;
	}
	xnext -= cos(vars->angle + mpi2) * 0.5;
	ynext -= sin(vars->angle + mpi2) * 0.5;
	another_vars.x_f = xnext;
	another_vars.y_f = ynext;
	ft_raycast(vars);
}

int     step_and_direct(int keycode, t_vars *vars)
{
	if (keycode == 82)
		ft_raycast(vars);
	if (keycode == 83)
		ft_right_or_left(vars, -1);
	if (keycode == 85)
		ft_right_or_left(vars, 1);
	if (keycode == 84)
		ft_down(vars);
	if (keycode == 87)
		ft_up(vars);
	if (keycode == 124)
		ft_right_or_left_step(vars, M_PI_2);
	if (keycode == 123)
		ft_right_or_left_step(vars, -M_PI_2);
    return 0;
}

void    all_hooks_mlx(t_vars *vars)
{
    mlx_key_hook(vars->win, ft_close, vars);
	mlx_mouse_hook(vars->win, mause, vars);
    mlx_hook(vars->win, 02, 1L << 0, step_and_direct, vars);
	//mlx_hook(vars.win, 06, 1L << 6, mause2, &vars);
	mlx_hook(vars->win, 17, 0, closex, vars);
}

int	closex(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	mause(int mauscode, int a, int b, t_vars *vars)
{
	if (mauscode == 4)
		return (0);
	if (mauscode == 5)
		return (0);
//	if (mauscode == 1 || mauscode == 2)
(void)mauscode;
	if (a < 600 && a > 0 && b > 0 & b < 600)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ptr, 0, 0);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->pers_ptr, a, b);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->pers_mini_ptr, a / 6, b / 6);
		vars->x_pos = a;
		vars->y_pos = b;
	}
	return (a + b);
}