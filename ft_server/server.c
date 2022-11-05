/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:16 by dwuthric          #+#    #+#             */
/*   Updated: 2022/11/04 11:51:52 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	reset(int *rcv_bytes, int *data_len, char **data)
{
	*rcv_bytes = 0;
	*data_len = 0;
	free(*data);
	*data = NULL;
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
	static int	rcv_bytes;
	static int	data_len;
	static char	*data;

	(void)ucontext;
	if (rcv_bytes < 4)
		read_byte(signum, ((char *)&data_len) + rcv_bytes, &rcv_bytes);
	else
	{
		if (!data)
		{
			data = malloc(sizeof(*data) * (data_len + 1));
			if (!data)
				return ;
		}
		read_byte(signum, data + rcv_bytes - 4, &rcv_bytes);
		if (rcv_bytes - 4 == data_len)
		{
			write(STDOUT_FILENO, data, ft_strlen(data));
			kill(info->si_pid, SIGUSR1);
			reset(&rcv_bytes, &data_len, &data);
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
