#include "head_main.h"

void	window_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, XSIZE, YSIZE, "cub3D");
	vars->img_ptr = mlx_new_image(vars->mlx, XSIZE, YSIZE);
	vars->my_im_d = mlx_get_data_addr(vars->img_ptr, &(vars->bpp),
			&(vars->size_line), &(vars->endian));
}

void	start_pos(t_vars *vars)
{
	vars->x_f = vars->x_pos + 0.5;
	vars->y_f = vars->y_pos + 0.5;
	ft_raycast(vars);
}
