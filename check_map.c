#include "head_main.h"

static void check_num(t_vars *vars, char *map)
{
	int i;
	int pers;

	i = 0;
	pers = 0;
	map[vars->x_pos] = '0';
	vars->y_pos = vars->x_pos / vars->xchars;
	vars->x_pos = vars->x_pos % vars->xchars;
	while (map && map[i])
	{
		if (map[i] == '1' || map[i] == ' ' || map[i] == '0')
			i++;
		else
			ft_errexit("Error: Map Symbols can be space || 1 || 0 !\n");
	}
}

void check_data(t_vars *vars, char *map)
{
	int i;

	i = 0;
	while (map && map[i])
	{
		if ((map[i] == 'N' || map[i] == 'W' || map[i] == 'S' || map[i] == 'E') && vars->angle != -1.0f)
			ft_errexit("Error: Only one N || S || W || E !\n");
		if (map[i] == 'S')
			vars->angle = M_PI / 2;
		else if (map[i] == 'E')
			vars->angle = 0.0f;
		else if (map[i] == 'W')
			 vars->angle = M_PI;
		else if (map[i] == 'N')
			vars->angle = M_PI * 1.5;
		if (vars->angle != -1.0f && vars->x_pos == -1)
			vars->x_pos = i;
		i++;
	}
	if (vars->angle == -1.0f)
		ft_errexit("Error: Can't find N || S || W || E !\n");
	check_num(vars, vars->map);
}

static void	compare_around(t_vars *vars, int i, char *map)
{
	if (i % vars->xchars == 0 || i % vars->xchars == vars->xchars - 1 || i < vars->xchars || i / vars->xchars == vars->ylines - 1) // края карты
		ft_errexit("Error: Map data!\n");
	if (map[i + 1] == ' ' || map[i - 1] == ' ' || map[i - vars->xchars] == ' ' || map[i + vars->xchars] == ' ' || map[i - vars->xchars - 1] == ' ' || map[i + vars->xchars + 1] == ' ' || map[i + vars->xchars - 1] == ' ' || map[i - vars->xchars + 1] == ' ')
		ft_errexit("Error: Map data!\n");
}

void	valid_map(t_vars *vars, char *map)
{
	int i;

	i = 0;
	while (map && map[i])
	{
		if (map[i] == '0') //  || i == (vars->x_pos * vars->xchars) + vars->y_pos
			compare_around(vars, i, map);
		i++;
	}
}
