NAME = push_swap

SRC = sa.c sb.c ss.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c check_if_sorted.c push_swap.c ft_check_data.c ft_str_to_num_array.c ft_check_if_copies.c ft_quicksort.c

DIR_SRC = srcs

SRC_PATH = $(addprefix $(DIR_SRC)/, $(SRC))

OBJ	= $(patsubst %.c, %.o, $(SRC))

DIR_OBJ = objects

OBJ_PATH = $(addprefix $(DIR_OBJ)/, $(OBJ))

LIBFT = libft.a

DIR_LIBFT = libft

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

HEADER = push_swap.h

DIR_HEADER = includes

HEADER_PATH = includes/push_swap.h

all: $(NAME)

$(NAME): $(OBJ_PATH)
	make -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) .
	$(CC) $(CFLAGS) -I $(DIR_HEADER) $(OBJ_PATH) -o $(NAME) $(LIBFT)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(HEADER_PATH)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -I $(DIR_HEADER) -I $(DIR_LIBFT) -c $< -o $@


clean:
				$(RM) $(DIR_OBJS)
				make clean -C $(DIR_LIBFT)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)

re:				fclean all

.PHONY: all clean fclean re
