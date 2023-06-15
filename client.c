/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:43:23 by heolivei          #+#    #+#             */
/*   Updated: 2023/06/15 17:53:22 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	count_bit;

	count_bit = 0;
	while (count_bit < 8)
	{
		if ((c & (0x01 << count_bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		count_bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		printf("Escreva direito!!\n");
		printf("Assim e' direito: ./client <PID> <Message>\n");
	}
}
