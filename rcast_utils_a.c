#include "head_main.h"

float	p_m_1(t_vars *vars, t_rcast *rcast, double sinu, double cosi)
{
	if (vars->map[(int)(vars->xchars * ((int)(rcast->y) - rcast->i - 1) \
		+ (int)(vars->x_f + (rcast->d_y + rcast->i) * cosi / sinu))] != '0')
	{
		rcast->flag = vars->north;
		rcast->xpm = 64 * ((vars->x_f + (rcast->d_y + rcast->i) * cosi / sinu) \
			- (int)(vars->x_f + (rcast->d_y + rcast->i) * cosi / sinu));
		return (600.0 / (((rcast->d_y + rcast->i) / sinu) \
			* cos(abs(rcast->ugol) * M_PI / 2400.0)));
	}
	else
		return (-1000001.0);
}

float	p_m_2(t_vars *vars, t_rcast *rcast, double sinu, double cosi)
{
	if (vars->map[(int)(vars->xchars * ((int)(- (1 - rcast->d_x + rcast->i2) \
		* sinu / cosi + rcast->y)) + 1 + rcast->i2 + (int)vars->x_f)] != '0')
	{
		rcast->flag = vars->west;
		rcast->xpm = 64 * (- (1 - rcast->d_x + rcast->i2) * \
			sinu / cosi + rcast->y - (int)(- (1 - rcast->d_x + rcast->i2) * \
			sinu / cosi + rcast->y));
		return (600.0 / (((1.0 - rcast->d_x + rcast->i2) / cosi) * \
			cos(abs(rcast->ugol) * M_PI / 2400.0)));
	}
	else
		return (-1000001.0);
}

float	cos_p_sin_m(t_vars *vars, t_rcast *rcast, double sinu, double cosi)
{
	int	h;

	while ((rcast->i < vars->ylines) && (rcast->i2 < vars->xchars))
	{
		if ((((rcast->d_y + rcast->i) * cosi / sinu) <= \
			(1 - rcast->d_x + rcast->i2)) && ((rcast->d_y + rcast->i) \
			<= ((1 - rcast->d_x + rcast->i2) * sinu / cosi)))
		{
			h = p_m_1(vars, rcast, sinu, cosi);
			if ((++rcast->i) && h > -1000000.0)
				return (h);
		}
		else
		{
			h = p_m_2(vars, rcast, sinu, cosi);
			if ((++rcast->i2) && h > -1000000.0)
				return (h);
		}
	}
	return (0);
}
