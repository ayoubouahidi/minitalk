/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:07:03 by ayouahid          #+#    #+#             */
/*   Updated: 2025/03/02 02:07:04 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "minitalk.h"

int	lenght(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
		i++;
	return (i);
}

char	*isvalid(char *av)
{
	int		i;
	long	result;
	int		err;

	i = 0;
	if (av[0] != '-' && av[0] != '+' && !ft_isdigit(av[0]))
		return (NULL);
	if ((av[0] == '-' || av[0] == '+') && lenght(av) == 1)
		return (NULL);
	i++;
	while (av[i] != '\0')
	{
		if (!ft_isdigit(av[i]))
			return (NULL);
		i++;
	}
	err = 0;
	result = ft_atoi_err(av, &err);
	(void)result;
	if (err)
		return (NULL);
	return ("is valid ");
}

int	is_valid_pid(char *str)
{
	if (!isvalid(str) || ft_atoi(str) == -1 || ft_atoi(str) == 1
		|| ft_atoi(str) == 0)
	{
		write(2, "Invalid PID\n", 13);
		exit(1);
	}
	return (ft_atoi(str));
}

void	send_char_bin(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 0;
	while (i < 8)
	{
		tmp = c & 1;
		if (tmp == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				print_err();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				print_err();
		}
		c = c >> 1;
		usleep(700);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = is_valid_pid(av[1]);
		while (i < lenght(av[2]))
		{
			send_char_bin(pid, av[2][i]);
			i++;
		}
		send_char_bin(pid, '\0');
	}
	else
	{
		write(2, "Error\n", 7);
	}
	return (0);
}
