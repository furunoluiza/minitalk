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
	(void)sig;
	write (1, "PALMEIRAS\n", 10);
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
