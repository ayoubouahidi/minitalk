/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:38:37 by ayouahid          #+#    #+#             */
/*   Updated: 2025/03/07 10:38:39 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include "./ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	handle_signal(int sig, siginfo_t *i, void *c)
{
	static char	charact;
	static int	bit;
	static int	curr_client_pid;

	(void)c;
	if (curr_client_pid != (*i).si_pid)
	{
		bit = 0;
		charact = 0;
	}
	if (sig == SIGUSR1)
		charact |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &charact, 1);
		bit = 0;
		charact = 0;
	}
	curr_client_pid = (*i).si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	ft_printf("the pid is : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
