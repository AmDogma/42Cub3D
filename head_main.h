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
# include "new_h.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img_ptr;
	void	*pers_ptr;
	char	*north; // картинки сторон
	char	*south;
	char	*west;
	char	*east;
	void	*pers_mini_ptr;
	char	*my_im_d;
	char	*map;
	int 	floor;
	int		ceilling;
	int		xchars;
	int		ylines;
	float	angle;//ugol povorota sever ug
	int		x_pos;
	int		y_pos;
	float	x_f;
	float	y_f;
//	int		zoom;
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
void 	find_sides(t_vars *vars, t_list **lines);
void	find_color(t_vars *vars, t_list **lines);

/* utils for lists */
void del_one_lst(t_list **lines);

/* utils */
void	ft_errexit(char *str);
void	ft_prejoin(char **line, char *let);
int		gnl(int fd, char **line);
void	*open_xpm(char *path, t_vars *vars);

/* utils2 */
void	freestr(char **str);
int		color_atoi(const char *str);
int		make_color(int r, int g, int b);

void    window_init(t_vars *vars);
void    test(t_vars *vars);

/* hook utils */
int     closex(t_vars *vars);
int     ft_close(int keycode, t_vars *vars);
int     mause(int mauscode, int a, int b, t_vars *vars);
void    all_hooks_mlx(t_vars *vars);

/* check_map */
void	check_data(t_vars *vars, char *map);
void	valid_map(t_vars *vars, char *map);

/* line_place */ 
void ft_line(t_vars *vars, int length, int x_xpm, int x_img, char *xpm_img);

t_vars another_vars; //глобальная потом убрать

#endif
