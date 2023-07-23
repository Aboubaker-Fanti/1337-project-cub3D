NAME = cub3d

CFLAGS = -Wall -Wextra -Werror 

CC = cc

SRC = raycaster.c fn_colors.c fn_pixel_put.c fn_click_on_cross.c fn_keydown.c\
		libft_function.c check_name_of_map.c check_texture_map.c\
		get_next_line.c read_and_check_mao.c\
		get_next_line_utils.c \
		check_map_valid.c\
		map.c errors.c move.c retate.c draw.c side_wall_len_ray.c\

OBJ = $(SRC:.c=.o) libftt/libft.a

all : lib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# -fsanitize=address -g3

clean:
	rm -rf *.o
	make clean -C libftt

fclean:	clean
	rm -rf ${NAME}
	make fclean -C libftt

re:	fclean all

lib:
	make -C libftt