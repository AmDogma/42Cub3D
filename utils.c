#include "head_main.h"

void	ft_errexit(char *str)
{
	printf("%s", str);
	exit(0);
}

void	*open_xpm(char *path, t_vars *vars)
{
	void	*img;
	char	*res;
	int		x;
	int		y;
	int		z;

	img = mlx_xpm_file_to_image(vars->mlx, path, &x, &y);
	if (img == NULL || x != 64 || y != 64)
		ft_errexit("Error: XPM!\n");
	res = mlx_get_data_addr(img, &x, &y, &z);
	return (res);
}

void	ft_prejoin(char **line, char *addpost)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(*line, addpost);
	if (*line == NULL)
		ft_errexit("Error: malloc!\n");
	free(temp);
}

int	gnl(int fd, char **line)
{
	int		res;
	char	*let;

	*line = (char *)malloc(sizeof(char));
	let = (char *)malloc(sizeof(char) * 2);
	if (*line == NULL || let == NULL)
		ft_errexit("Error: malloc!\n");
	**line = '\0';
	let[1] = '\0';
	res = read(fd, let, 1);
	while (res > 0 && *let != '\n')
	{
		ft_prejoin(line, let);
		res = read(fd, let, 1);
	}
	if (res == -1)
		ft_errexit("Error: Read map!\n");
	free(let);
	return (res);
}
