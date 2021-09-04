/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:18:25 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/08/02 23:18:27 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_message_sending(int pid, char *message, int len)
{
	int	i;
	int	m;

	i = 0;
	while (i < (len + 1))
	{
		m = 0;
		while (m < 7)
		{
			if ((message[i] >> m) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			m++;
			usleep(10);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_putstr("U have to enter: client    server_pid    message\n");
	else
	{
		pid = atoi(argv[1]);
		ft_message_sending(pid, argv[2], ft_strlen(argv[2]));
	}
	return (0);
}
