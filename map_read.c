#include "head_main.h"

void	add_space(t_list *temp, t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->xchars < 3 || vars->ylines < 3)
		ft_errexit("Error: Map!\n");
	while (temp)
	{
		i = (int)(ft_strlen(temp->content));
		while (i != vars->xchars && i != 0)
		{
			ft_prejoin((char **)&temp->content, " ");
			i++;
		}
		ft_prejoin(&vars->map, temp->content);
		del_one_lst(&temp);
	}
}

void	line_max(t_list **lines, t_vars *vars)
{
	t_list	*temp;
	int		i;
	int		check;

	check = 0;
	temp = *lines;
	while (temp)
	{
		i = ft_strlen(temp->content);
		if (i == 0)
			check = 1;
		else if (i && check)
			ft_errexit("Error: Map can't be separate!\n");
		if (i > vars->xchars)
			vars->xchars = i;
		if (i)
			vars->ylines++;
		if (vars->xchars * vars->ylines >= INT_MAX - vars->xchars)
			ft_errexit("Error: Map chars value to long\n");
		temp = temp->next;
	}
	add_space(*lines, vars);
}

void	parse_map(t_vars *vars, t_list **lines)
{
	char	c;

	while (*lines)
	{
		c = ((char *)(*lines)->content)[0];
		if (c == 0)
			del_one_lst(lines);
		else if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
			find_sides(vars, lines);
		else if (c == 'C' || c == 'F')
			find_color(vars, lines);
		else
			break ;
	}
	if (vars->north == NULL || vars->south == NULL || vars->east == NULL \
		|| vars->west == NULL || vars->ceilling == -1 || vars->floor == -1)
		ft_errexit("Error: Textures or color data!\n");
	line_max(lines, vars);
	check_data(vars, vars->map);
	valid_map(vars, vars->map);
}

void	read_fd(int fd, t_list **lines)
{
	t_list	*temp;
	char	*oneline;
	int		i;

	i = 1;
	temp = NULL;
	while (i)
	{
		i = gnl(fd, &oneline);
		if (i == -1)
			ft_errexit("Error: GNL!\n");
		temp = ft_lstnew(oneline);
		if (temp == NULL)
			ft_errexit("Error: Malloc!\n");
		ft_lstadd_back(lines, temp);
		if (i == 0)
			break ;
	}
	close(fd);
}

void	make_map(t_vars *vars, char *file)
{
	int		fd;
	t_list	*lines;

	lines = NULL;
	if (ft_strncmp(file + strlen(file) - 4, ".cub", 4))
		ft_errexit("Error: Map should be *.cub!\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_errexit("Error: Can't open map!\n");
	read_fd(fd, &lines);
	parse_map(vars, &lines);
}
