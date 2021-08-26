SRCS			= main.c ft_printf.c ft_flag_dot.c ft_flag_minus.c ft_flag_width.c ft_init_flags.c ft_is_digit.c \
					ft_is_type.c ft_parse_flag.c ft_parse_input.c ft_flag_digit.c ft_processor.c process_char.c \
					ft_add_width.c process_percent.c process_string.c ft_strlen.c ft_proc_str_with_precision.c \
					ft_proc_minus.c	process_integer.c ft_itoa.c ft_itoa_unsigned_int.c \
					process_unsigned_int.c process_pointer.c process_hex.c

OBJS 			= $(patsubst %.c, %.o, $(SRCS))
HEADER			= ft_printf.h

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

NAME			= libftprintf.a

%.o: %.c
				gcc $(CFLAGS) -c $< -I $(HEADER) -o $@

all:			$(NAME)

$(NAME): 		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				gcc $(CFLAGS) $(OBJS) -o ft_printf

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) ft_printf

re:				fclean all



.PHONY:			all clean fclean re