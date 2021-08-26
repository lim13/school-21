# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 16:30:18 by cdwyynen          #+#    #+#              #
#    Updated: 2021/07/04 16:30:21 by cdwyynen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c my_mlx_pixel_put.c fractol_julia.c utils.c fractol_mandelbrot.c esc_close_the_win.c mouse_zoom.c

DIR_SRC = srcs

SRC_PATH = $(addprefix $(DIR_SRC)/, $(SRC))

OBJ	= $(patsubst %.c, %.o, $(SRC))

DIR_OBJ = objects

OBJ_PATH = $(addprefix $(DIR_OBJ)/, $(OBJ))

LIBFT = libft.a

DIR_LIBFT = libft

MLX = libmlx.dylib

DIR_MLX = mlx

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

HEADER = fractol.h

DIR_HEADER = includes

HEADER_PATH = includes/fractol.h

MLXFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ_PATH)
	make -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) .
	make -C $(DIR_MLX)
	cp $(DIR_MLX)/$(MLX) .
	$(CC) $(CFLAGS) -I $(DIR_HEADER) $(MLXFLAGS) $(OBJ_PATH) -o $(NAME) $(LIBFT)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADER_PATH)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -I $(DIR_MLX) -I $(DIR_HEADER) -I $(DIR_LIBFT) -c $< -o $@


clean:
				$(RM) $(DIR_OBJS)
				make clean -C $(DIR_LIBFT)
				make clean -C $(DIR_MLX)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)
				$(RM) $(MLX)

re:				fclean all

.PHONY: all clean fclean re
