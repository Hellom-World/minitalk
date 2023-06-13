/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heolivei <heolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:31 by heolivei          #+#    #+#             */
/*   Updated: 2023/06/14 00:41:59 by heolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void printBits(char c)
{
    for (int i = 7; i >= 0; i--)
    {
        unsigned char bit = (c >> i) & 1;
        printf("%u", bit);
    }
    printf("\n");
}

void	ft_render(int sig)
{
	static int	count_bit;
	static char	c;

	if (sig == SIGUSR1)
		c |= (0x01 << count_bit);
	count_bit++;
	if (count_bit == 8)
	{
		 printf("Caractere reconstruído: %c\n", c);
		printBits(c);

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
		printf("formato errado\n");
		printf("execute dessa forma -> ./server");
		return (0);
	}
	pid = getpid();
	printf("PID: %d\n", (int)pid);
	printf("Esperando mensagem...\n");
	while(1)
	{
		signal(SIGUSR1, ft_render);
		signal(SIGUSR2, ft_render);
		pause();
	}
	return (0);
}
