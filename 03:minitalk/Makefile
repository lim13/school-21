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


NAME1 = client
NAME2 = server

SRCS1			= client.c ft_putstr.c ft_atoi.c ft_strlen.c ft_putnbr.c
SRCS2			= server.c ft_putstr.c ft_atoi.c ft_strlen.c ft_putnbr.c

OBJS1 			= $(patsubst %.c, %.o, $(SRCS1))
OBJS2			= $(patsubst %.c, %.o, $(SRCS2))
HEADER			= minitalk.h

RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g

%.o: %.c
				gcc $(CFLAGS) -c $< -o $@
				gcc $(CFLAGS) -c $< -o $@

all:			$(NAME1) $(NAME2)

$(NAME1): 		$(OBJS1)
				gcc $(CFLAGS) $^ -o $@

$(NAME2): 		$(OBJS2)
				gcc $(CFLAGS) $^ -o $@

clean:
				$(RM) $(OBJS1)
				$(RM) $(OBJS2)

fclean:			clean
				$(RM) $(NAME1)
				$(RM) $(NAME2)

re:				fclean all

.PHONY:			all clean fclean re