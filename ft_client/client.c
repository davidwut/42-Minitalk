/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:54:15 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/06 16:55:16 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	kill_error(void)
{
	ft_printf("client: kill error\n");
	exit(1);
}

static void	client_handler(int signum)
{
	static int	signals;

	if (signum == SIGUSR1)
	{
		ft_printf("Server got the message!\n");
		ft_printf("%d bytes long and %d signals...\n",
			(signals + 1) / 8, signals + 1);
		exit(0);
	}
	else
		signals += 1;
}

static void	send_byte(int pid, char data)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		if ((data) & 0b10000000)
		{
			if (kill(pid, SIGUSR1) == -1)
				kill_error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				kill_error();
		}
		data <<= 1;
		pause();
		usleep(100);
	}
}

static void	send_text(char **av)
{
	int		target;
	char	*data;

	target = ft_atoi(av[1]);
	data = av[2];
	while (*data)
		send_byte(target, *data++);
	send_byte(target, '\0');
}

int	main(int ac, char **av)
{
	if (ac < 3)
		ft_printf("2 arguments are required: [1] target_pid and [2] message\n");
	else
	{
		signal(SIGUSR1, client_handler);
		signal(SIGUSR2, client_handler);
		send_text(av);
		pause();
	}
	return (0);
}
