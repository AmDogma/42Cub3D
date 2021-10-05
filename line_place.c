#include "head_main.h"

void	ft_line(t_vars *vars, t_rcast *rcast)
{
	float	coef;
	int		y;
	int		base;
	int		res_im;
	int		res_xpm;

	rcast->x_img = rcast->ugol + 300;
	coef = (float)rcast->h / 64.0;
	base = 300 - rcast->h / 2;
	y = base;
	while (y < base + rcast->h && y < 600 )
	{
		if (y < -299)
		{
			y++;
			continue ;
		}
		res_im = (y * 600 + rcast->x_img) * 4;
		res_xpm = ((int)(((float)(y - base)) / coef) *64 + (int)rcast->xpm) * 4;
		vars->my_im_d[res_im] = rcast->flag[res_xpm];
		vars->my_im_d[res_im + 1] = rcast->flag[res_xpm + 1];
		vars->my_im_d[res_im + 2] = rcast->flag[res_xpm + 2];
		y++;
	}
}
