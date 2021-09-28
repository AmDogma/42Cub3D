#include "head_main.h"

char	*jump_space(char *some)
{
	int	i;

	i = 0;
	while (some && some[i] == ' ')
		i++;
	return (some + i);
}

void	find_sides(t_vars *vars, t_list **lines)
{
	if (ft_strncmp((*lines)->content, "NO ", 3) == 0 && vars->north == NULL)
		vars->north = \
			open_xpm(jump_space((char *)((*lines)->content + 3)), vars);
	else if (!ft_strncmp((*lines)->content, "SO ", 3) && vars->south == NULL)
		vars->south = \
			open_xpm(jump_space((char *)((*lines)->content + 3)), vars);
	else if (ft_strncmp((*lines)->content, "WE ", 3) == 0 && vars->west == NULL)
		vars->west = \
			open_xpm(jump_space((char *)((*lines)->content + 3)), vars);
	else if (ft_strncmp((*lines)->content, "EA ", 3) == 0 && vars->east == NULL)
		vars->east = \
			open_xpm(jump_space((char *)((*lines)->content + 3)), vars);
	else
		ft_errexit("Error: Can't find N S W E textures!\n");
	del_one_lst(lines);
}

static int	parse_color(t_list **lines)
{
	char	**color;
	int		res;
	int		i;

	i = 2;
	while (((char *)(*lines)->content)[i] == ' ')
		i++;
	color = ft_split((*lines)->content + i, ',');
	if (!color)
		ft_errexit("Error: Malloc!\n");
	del_one_lst(lines);
	res = make_color(color_atoi(color[0]), \
		color_atoi(color[1]), color_atoi(color[2]));
	freestr(color);
	return (res);
}

void	check_comma(char *some)
{
	int		i;
	int		comma;

	i = 0;
	comma = 0;
	while (some[i])
	{
		if (some[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		ft_errexit("Error: Colors string!\n");
}

void	find_color(t_vars *vars, t_list **lines)
{
	if (vars->ceilling == -1 && ft_strncmp((*lines)->content, "C ", 2) == 0)
	{
		check_comma(((char *)(*lines)->content) + 2);
		vars->ceilling = parse_color(lines);
	}
	else if (vars->floor == -1 && ft_strncmp((*lines)->content, "F ", 2) == 0)
	{
		check_comma(((char *)(*lines)->content) + 2);
		vars->floor = parse_color(lines);
	}
	else
		ft_errexit("Error: Can't find colors C and F!\n");
}
