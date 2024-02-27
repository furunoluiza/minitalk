/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:06:07 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/02/27 11:00:27 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_char(int sig)
{
	static char	c;
	static int	bit;

	c = 0;
	bit = 0;
	if (sig == SIGUSR2)
		c = c << 1;
	else
		c = c << 1 | 1;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, bit_char);
		signal(SIGUSR2, bit_char);
	}
}
