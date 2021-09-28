#include "head_main.h"

void	define_vars(t_vars *vars)
{
	vars->xmaus = 0;
	vars->ymaus = 0;
	vars->xchars = 0;
	vars->ylines = 0;
	vars->north = NULL;
	vars->south = NULL;
	vars->west = NULL;
	vars->east = NULL;
	vars->floor = -1;
	vars->x_pos = -1;
	vars->ceilling = -1;
	vars->angle = -1.0f;
	vars->map = (char *)malloc(sizeof(char));
	if (vars->map == NULL)
		ft_errexit("Error: malloc!\n");
	*vars->map = '\0';
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		x;
	int		y;

	define_vars(&vars);
	if (argc != 2)
		ft_errexit("Error: arguments\n");
	make_map(&vars, argv[1]);
	window_init(&vars);
	x = 10;
	y = 10;
	vars.pers_mini_ptr = \
		mlx_xpm_file_to_image(vars.mlx, "./textures/pers.xpm", &x, &y);
	start_pos(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img_ptr, 0, 0);
	all_hooks_mlx(&vars);
	mlx_loop(vars.mlx);
}
