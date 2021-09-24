#include "head_main.h"
#include "new_h.h"

void	window_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, XSIZE, YSIZE, "cub3D");
	vars->img_ptr = mlx_new_image(vars->mlx, XSIZE, YSIZE);
	vars->my_im_d = mlx_get_data_addr(vars->img_ptr, &(vars->bpp),
			&(vars->size_line), &(vars->endian));

	another_vars.mlx = mlx_init();
//	another_vars.win = mlx_new_window(another_vars.mlx, XSIZE, YSIZE, "another_cub3D");
	another_vars.img_ptr = mlx_new_image(another_vars.mlx, XSIZE, YSIZE);
	another_vars.my_im_d = mlx_get_data_addr(another_vars.img_ptr, &(another_vars.bpp),
			&(another_vars.size_line), &(another_vars.endian));
}

void	test(t_vars *vars)
{
	int a = 0;
	another_vars.x_f = vars->x_pos + 0.5;
	another_vars.y_f = vars->y_pos + 0.5;
	int b = 0;
	int ax = (XSIZE / 6 )/ vars->xchars;
	int by = (YSIZE / 6 )/ vars->ylines;
	int matrix = 0;
	while (a < 99)
	{
		b = 0;
		while (b < 99)
		{
			matrix = (a / ax) + (b / by) * vars->xchars; //какая позиция в чар мап // МОЖНО ХРАНИТЬ ЧТОБЫ НЕ СЧИТАТЬ
			if (vars->map[matrix] == '1')
			{
				vars->my_im_d[(b * YSIZE + a) * 4] = 88;
				vars->my_im_d[(b * YSIZE + a) * 4 + 1] = 88;
				vars->my_im_d[(b * YSIZE + a) * 4 + 2] = 88;
			}
			else if (vars->map[matrix] == '0')
			{
				vars->my_im_d[(b * YSIZE + a) * 4] = 127;
				vars->my_im_d[(b * YSIZE + a) * 4 + 1] = 88;
				vars->my_im_d[(b * YSIZE + a) * 4 + 2] = 88;
			}
			b++;
		}
		a++;
	}
}