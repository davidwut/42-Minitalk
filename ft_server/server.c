/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:16 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/06 16:55:21 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	kill_error(void)
{
	ft_printf("server: kill error\n");
	exit(1);
}

void	reset(t_packet *packet, int new_pid)
{
	packet->c = 0;
	packet->nbit = 0;
	packet->pid = new_pid;
}

static void	server_handler(int signum, siginfo_t *info, void *ucontext)
{
	static t_packet	packet;

	(void)ucontext;
	if (!packet.pid)
		packet.pid = info->si_pid;
	if (packet.pid != info->si_pid)
		reset(&packet, info->si_pid);
	packet.c |= (signum == SIGUSR1);
	packet.nbit++;
	if (packet.nbit == 8)
	{
		write(STDOUT_FILENO, &packet.c, 1);
		if (packet.c == '\0')
		{
			if (kill(packet.pid, SIGUSR1) == -1)
				kill_error();
			return ;
		}
		reset(&packet, packet.pid);
	}
	packet.c <<= 1;
	usleep(100);
	if (kill(packet.pid, SIGUSR2) == -1)
		kill_error();
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = server_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
