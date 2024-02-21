/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfuruno- <lfuruno-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:06:07 by lfuruno-          #+#    #+#             */
/*   Updated: 2024/01/31 15:18:39 by lfuruno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//função para receber o bits e transformar em um caracter
// enquanto não receber nada tem que ficar em loop infinito

void	bit_char(int sig)
{
	static char	c = 0;
	static int	bit = 0;

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
	while (1)
	{
		signal(SIGUSR1, bit_char);
		signal(SIGUSR2, bit_char);
	}
}