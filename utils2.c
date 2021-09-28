#include "head_main.h"

void	freestr(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	color_atoi(const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (*str < 48 || *str > 57)
		ft_errexit("Error: Color value !\n");
	while (str && str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') || (i && res == 0))
			ft_errexit("Error: Color value!\n");
		res = (res * 10) + (str[i] - 48);
		if (res > 255)
			ft_errexit("Error: Color value!\n");
		i++;
	}
	return (res);
}

int	make_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
