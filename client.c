/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:06:18 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/02/27 10:58:09 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, char octet)
{
	int	n;

	n = 7;
	while (n >= 0)
	{
		if ((octet >> n & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		n--;
	}
}

void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_bit(pid, str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc <= 3)
	{
		pid = ft_atoi(argv[1]);
		send_str(pid, argv[2]);
	}
}
