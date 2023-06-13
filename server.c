/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:31 by heolivei          #+#    #+#             */
/*   Updated: 2023/03/23 20:09:01 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_render(int sig)
{
	static int	count_bit;
	static char	c;

	if (sig = SIGUSR1)
		c = c | (1 << count_bit);
	count_bit++;
	if (count_bit = 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	(void)argv;

	if (argc = 1)
	{
		pid = getpid();
		printf("PID: %i", pid);
		while(1)
		{
			signal(SIGUSR1, ft_render);
			signal(SIGUSR2, ft_render);
			pause();
		}
	}
	else
	{
		printf("formato errado\n");
		printf("execute dessa forma -> ./server");
	}
	return (0);
}
