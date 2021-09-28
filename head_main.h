#ifndef HEAD_MAIN_H
# define HEAD_MAIN_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

# define XSIZE 600
# define YSIZE 600

typedef struct s_rcast
{
	float	y;
	double	s;
	double	c;
	float	d_y;
	float	d_x;
	char	*flag;
	char	xpm;
	int		ugol;
	int		x_img;
	int		h;
	int		i;
	int		i2;
}		t_rcast;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img_ptr;
	void	*pers_ptr;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	void	*pers_mini_ptr;
	char	*my_im_d;
	char	*map;
	int		floor;
	int		ceilling;
	int		xchars;
	int		ylines;
	float	angle;
	int		x_pos;
	int		y_pos;
	float	x_f;
	float	y_f;
	int		fname;
	int		bpp;
	int		size_line;
	int		endian;
	int		xmaus;
	int		ymaus;
	int		notcolor;
}	t_vars;

/* map_read */
void	make_map(t_vars *vars, char *file);

/* color_sides */
void	find_sides(t_vars *vars, t_list **lines);
void	find_color(t_vars *vars, t_list **lines);

/* utils for lists */
void	del_one_lst(t_list **lines);

/* utils */
void	ft_errexit(char *str);
void	ft_prejoin(char **line, char *let);
int		gnl(int fd, char **line);
void	*open_xpm(char *path, t_vars *vars);

/* utils2 */
void	freestr(char **str);
int		color_atoi(const char *str);
int		make_color(int r, int g, int b);

void	window_init(t_vars *vars);
void	start_pos(t_vars *vars);

/* hook utils */
int		closex(t_vars *vars);
int		ft_close(int keycode, t_vars *vars);
void	all_hooks_mlx(t_vars *vars);
int		step_and_direct(int keycode, t_vars *vars);

/* check_map */
void	check_data(t_vars *vars, char *map);
void	valid_map(t_vars *vars, char *map);

/* line_place */
void	ft_line(t_vars *vars, t_rcast *rcast);

/* rcast */
void	ft_raycast(t_vars *vars);
float	cos_p_sin_m(t_vars *vars, t_rcast *rcast, double sinu, double cosi);
float	cos_p_sin_p(t_vars *vars, t_rcast *rcast, double sinu, double cosi);
float	cos_m_sin_m(t_vars *vars, t_rcast *rcast, double sinu, double cosi);
float	cos_m_sin_p(t_vars *vars, t_rcast *rcast, double sinu, double cosi);
void	minimap_add(t_vars *vars, int a, int b, int matr);

#endif
