/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:54:15 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/04 11:38:28 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	client_handler(int signum)
{
	(void)signum;
	ft_printf("Server pinged back!\n");
	exit(0);
}

static void	send_byte(int pid, char data)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		if ((data) & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		data <<= 1;
		usleep(100);
	}
}

static void	send_text(char **av)
{
	int		target;
	char	*data;
	int		data_len;

	target = ft_atoi(av[1]);
	data = av[2];
	data_len = ft_strlen(data);
	send_byte(target, *(((char *)&data_len) + 0));
	send_byte(target, *(((char *)&data_len) + 1));
	send_byte(target, *(((char *)&data_len) + 2));
	send_byte(target, *(((char *)&data_len) + 3));
	while (*data)
		send_byte(target, *data++);
}

int	main(int ac, char **av)
{
	signal(SIGUSR1, client_handler);
	if (ac < 3)
		ft_printf("2 arguments are required: [1] target_pid and [2] message\n");
	else
	{
		send_text(av);
		pause();
	}
	return (0);
}
