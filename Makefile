NAME = cub3D

SRC 		= main.c map_read.c utils.c utils_lst.c color_sides.c utils2.c check_map.c \
				hook_utils.c \
				hook_utils2.c \
				window_init_utils.c \
				line_place.c \
				raycast.c \
				rcast_utils.c \
				rcast_utils_a.c \
				rcast_utils_b.c \
				rcast_utils_c.c

NAME_LIBFT = libft.a

MLXDIR = minilibx_opengl_20191021

PATH_LIBFT = ./libft/

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGC = -Wall -Wextra -Werror -I.

RM = rm -f

%.o: %.c head_main.h
	$(CC) $(CFLAGC) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLXDIR)
	make -C $(PATH_LIBFT)
	cp ./$(MLXDIR)/libmlx.a libmlx.a
	$(CC) $(CFLAGS) $(OBJ) $(PATH_LIBFT)$(NAME_LIBFT) libmlx.a -framework OpenGL -framework AppKit -o $@

#  -fsanitize=address доп флаг для проверки правильного очищения не работает с leaks

# bonus:
# 	$(CC) $(CFLAGS) ft_bonus.c libmlx.a -framework OpenGL -framework AppKit -o bon && ./bon 

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C ./minilibx_opengl_20191021
	make clean -C $(PATH_LIBFT)
	$(RM) bon
fclean: clean
	make fclean -C $(PATH_LIBFT)
	$(RM) $(NAME) libmlx.a
	

re: fclean all

.PHONY: all clean fclean re bonus

