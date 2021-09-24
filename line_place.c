# include "head_main.h"

void ft_line(t_vars *vars, int length, int x_xpm, int x_img, char *xpm_img)
{
	float coef;
	int y;
	int base;
	int res_im;
	int res_xpm;
(void)vars;
	coef = (float)length / 64.0; // 64 size of texture. Length max = 600 min = 0;
	base = 300 - length/2;
	y = base;
	while (y < base + length)
	{
		res_im = (y * 600 + x_img) * 4;
		res_xpm = ((int)(((float)(y - base))/coef) * 64 + x_xpm) * 4;
		// vars->my_im_d[res_im] = xpm_img[res_xpm];
		// vars->my_im_d[res_im + 1] = xpm_img[res_xpm + 1];
		// vars->my_im_d[res_im + 2] = xpm_img[res_xpm + 2];
		// vars->my_im_d[res_im + 3] = xpm->x_im_d[res_xpm + 3];
		another_vars.my_im_d[res_im] = xpm_img[res_xpm];
		another_vars.my_im_d[res_im + 1] = xpm_img[res_xpm + 1];
		another_vars.my_im_d[res_im + 2] = xpm_img[res_xpm + 2];
		y++;
	}
}
