/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:16 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/05 14:48:36 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	reset(t_packet *packet)
{
	packet->rcv_bytes = 0;
	packet->data_len = 0;
	free(packet->data);
	packet->data = NULL;
	packet->s_pid = 0;
}

static void	read_byte(int bit, char *data, int *rcv_bytes)
{
	static int	nbit;

	if (bit == SIGUSR1)
		*data += 1 << (7 - nbit);
	nbit++;
	if (nbit == 8)
	{
		nbit = 0;
		*rcv_bytes += 1;
	}
}

static void	server_handler(int signum, siginfo_t *info, void *ucontext)
{
	static t_packet	packet;

	(void)ucontext;
	if (!packet.s_pid && info->si_pid)
		packet.s_pid = info->si_pid;
	if (!info->si_pid || info->si_pid != packet.s_pid)
		return ;
	if (packet.rcv_bytes < 4)
		read_byte(signum, ((char *)&packet.data_len) + packet.rcv_bytes, &packet.rcv_bytes);
	else
	{
		if (!packet.data)
		{
			packet.data = malloc(sizeof(*packet.data) * (packet.data_len + 1));
			if (!packet.data)
				return ;
		}
		read_byte(signum, packet.data + packet.rcv_bytes - 4, &packet.rcv_bytes);
		if (packet.rcv_bytes - 4 == packet.data_len)
		{
			write(STDOUT_FILENO, packet.data, ft_strlen(packet.data));
			kill(packet.s_pid, SIGUSR1);
			reset(&packet);
		}
	}
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
