#include "head_main.h"

float	m_p_1(t_vars *vars, t_rcast *rcast, double sinu, double cosi)
{
	if (vars->map[(int)(vars->xchars * ((int)(rcast->y) + 1 + rcast->i) + \
		(int)(vars->x_f - (1.0 - rcast->d_y + rcast->i) * cosi / sinu))] != '0')
	{
		rcast->flag = vars->south;
		rcast->xpm = 64 * (vars->x_f - (1.0 - rcast->d_y + rcast->i) * \
			cosi / sinu - (int)(vars->x_f - (1.0 - rcast->d_y + rcast->i) * \
			cosi / sinu));
		return (600 / (1.0 + ((1.0 - rcast->d_y + rcast->i) / sinu) * \
			cos(abs(rcast->ugol) * M_PI / 1800.0)));
	}
	else
		return (-1000001.0);
}

float	m_p_2(t_vars *vars, t_rcast *rcast, double sinu, double cosi)
{
	if (vars->map[(int)(vars->xchars * ((int)((rcast->d_x + rcast->i2) * \
		sinu / cosi + rcast->y)) - rcast->i2 + (int)vars->x_f) - 1] != '0')
	{
		rcast->flag = vars->east;
		rcast->xpm = 64 * ((rcast->d_x + rcast->i2) * sinu / cosi + rcast->y \
			- (int)((rcast->d_x + rcast->i2) * sinu / cosi + rcast->y));
		return (600 / (1.0 + (rcast->d_x + rcast->i2) / cosi * \
			cos(abs(rcast->ugol) * M_PI / 1800.0)));
	}
	else
		return (-1000001.0);
}

float	cos_m_sin_p(t_vars *vars, t_rcast *rcast, double sinu, double cosi)
{
	int	h;

	while ((rcast->i < vars->ylines) && (rcast->i2 < vars->xchars))
	{
		if ((((1.0 - rcast->d_y + rcast->i) * cosi / sinu) <= \
			(rcast->d_x + rcast->i2)) && ((1.0 - rcast->d_y + rcast->i) <= \
			((rcast->d_x + rcast->i2) * sinu / cosi)))
		{
			h = m_p_1(vars, rcast, sinu, cosi);
			if ((++rcast->i) && h > -1000000.0)
				return (h);
		}
		else
		{
			h = m_p_2(vars, rcast, sinu, cosi);
			if ((++rcast->i2) && h > -1000000.0)
				return (h);
		}
	}
	return (0);
}

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
				vars->my_im_d[(b * YSIZE + a) *4] = 88;
				vars->my_im_d[(b * YSIZE + a) *4 + 1] = 88;
				vars->my_im_d[(b * YSIZE + a) *4 + 2] = 88;
				vars->my_im_d[(b * YSIZE + a) *4 + 3] = 127;
			}
			else if (vars->map[matr] == '0')
				vars->my_im_d[(b * YSIZE + a) *4] = 127;
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_ptr, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->pers_mini_ptr, vars->x_f * ax, vars->y_f * by);
}
