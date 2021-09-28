#include "head_main.h"

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

void	all_hooks_mlx(t_vars *vars)
{
	mlx_key_hook(vars->win, ft_close, vars);
	mlx_hook(vars->win, 02, 1L << 0, step_and_direct, vars);
	mlx_hook(vars->win, 17, 0, closex, vars);
}
