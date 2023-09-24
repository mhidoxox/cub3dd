NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror
#-Wunreachable-code -Ofast

L = -L/Users/efarhat/.brew/Cellar/glfw/3.3.8/lib

I = -I/Users/efarhat/.brew/Cellar/glfw/3.3.8/include/GLFW

SUB = -framework Cocoa -framework OpenGL -framework IOKit -lglfw

mlx = /Users/efarhat/Desktop/MLX42/build/libmlx42.a

# SEGS = -Wuninitialized -fsanitize=address,undefined,integer -g

LIBFT = libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_split.c libft/ft_substr.c libft/ft_isalpha.c\
		libft/ft_strdup.c libft/ft_strlen.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_isdigit.c\
		libft/ft_atoi.c libft/ft_strcmp.c libft/ft_strchr.c libft/ft_strnstr.c libft/ft_isempty.c\
		libft/ft_strlcpy.c libft/get_long_line.c

PARS = parsing/check_map.c parsing/get_elements.c parsing/check_elements.c\
		parsing/utils_map.c parsing/utils.c parsing/mr_cleaner.c

UTILS = main_function/draw_map.c main_function/hook_functions.c main_function/utils.c \
		main_function/raycasting.c main_function/utils_raycasting.c main_function/init.c\

SRC = $(LIBFT) $(UTILS) $(PARS) cub3d.c textures.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) cub3d.h libft/libft.h
	$(CC) $(CFLAGS) $(OBJ) $(SUB) $(LIBS) $(SEGS) -o $(NAME) $(L) $(I) $(mlx)

%.o: %.c cub3d.h libft/libft.h
	$(CC) $(CFLAGS) $(SEGS)  -c $< -o $@ $(I)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean all fclean re
