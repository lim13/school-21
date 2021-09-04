/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:19:09 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/08/02 23:19:12 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_message
{
	char	s;
	int		size;
}				t_message;

static t_message	g_message;

static void	ft_message_sending(int i)
{
	g_message.s += ((i & 1) << g_message.size);
	g_message.size++;
	if (g_message.size == 7)
	{
		write(1, &g_message.s, 1);
		if (!g_message.s)
			write(1, "\n", 1);
		g_message.s = 0;
		g_message.size = 0;
	}
}

int	main(void)
{
	int	pid;

	g_message.s = 0;
	g_message.size = 0;
	pid = getpid();
	ft_putstr("server pid is ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR2, ft_message_sending);
		signal(SIGUSR1, ft_message_sending);
		pause();
	}
}
