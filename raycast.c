#include "head_main.h"

void	ft_ray_floor_sky(int high, int ugol, t_vars *vars)
{
	int		nebo;
	float	matrix;

	nebo = 0;
	while (nebo + high / 2 < 300 && nebo < 300)
	{
		matrix = 300 + ugol + (300 - high / 2 - nebo) * XSIZE;
		vars->my_im_d[(int) matrix * 4] = vars->ceilling;
		vars->my_im_d[((int) matrix) *4 + 1] = vars->ceilling >> 8;
		vars->my_im_d[((int) matrix) *4 + 2] = vars->ceilling >> 16;
		matrix = 300 + ugol + (300 + high / 2 + nebo) * XSIZE;
		vars->my_im_d[((int) matrix) *4] = vars->floor;
		vars->my_im_d[((int) matrix) *4 + 1] = vars->floor >> 8;
		vars->my_im_d[((int) matrix) *4 + 2] = vars->floor >> 16;
		nebo++;
	}
}

void	rcast_init(t_rcast *rcast, t_vars *vars)
{
	rcast->d_x = vars->x_f - (int)vars->x_f;
	rcast->y = vars->y_f;
	rcast->d_y = - (int)(rcast->y) + rcast->y;
}

void	rcast_cos_sin_reload(t_rcast *rcast, t_vars *vars)
{
	rcast->c = cos(vars->angle + rcast->ugol * M_PI / 2400.0);
	rcast->s = sin(vars->angle + rcast->ugol * M_PI / 2400.0);
	rcast->i = 0;
	rcast->i2 = 0;
}

void	ft_put_sky_walls(t_rcast *rcast, t_vars *vars)
{
	if (rcast->h < 0)
		rcast->h = 0;
	ft_ray_floor_sky(rcast->h, rcast->ugol, vars);
	ft_line(vars, rcast);
}

void	ft_raycast(t_vars *vars)
{
	t_rcast	rcast;

	rcast.ugol = -300;
	rcast_init(&rcast, vars);
	while (++rcast.ugol < 299)
	{
		rcast_cos_sin_reload(&rcast, vars);
		if (rcast.c > 0.0)
		{
			if (rcast.s < 0.0)
				rcast.h = cos_p_sin_m(vars, &rcast, 0.0 - rcast.s, rcast.c);
			else
				rcast.h = cos_p_sin_p(vars, &rcast, rcast.s, rcast.c);
		}
		else
		{
			if (rcast.s < 0)
				rcast.h = cos_m_sin_m(vars, \
					&rcast, 0.0 - rcast.s, 0.0 - rcast.c);
			else
				rcast.h = cos_m_sin_p(vars, &rcast, rcast.s, 0.0 - rcast.c);
		}
		ft_put_sky_walls(&rcast, vars);
	}
	minimap_add(vars, -1, 0, 0);
}
