/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:31 by heolivei          #+#    #+#             */
/*   Updated: 2023/06/15 17:53:03 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_render(int sig)
{
	static int	count_bit;
	static char	c;

	if (sig == SIGUSR1)
		c |= (0x01 << count_bit);
	count_bit++;
	if (count_bit == 8)
	{
		write(1, &c, 1);
		count_bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("formato errado\n");
		ft_printf("execute dessa forma -> ./server");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", (int)pid);
	ft_printf("Esperando mensagem...\n");
	while (1)
	{
		signal(SIGUSR1, ft_render);
		signal(SIGUSR2, ft_render);
		pause();
	}
	return (0);
}
