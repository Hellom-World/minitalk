#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(void)
{
    ft_printf("SERVER PID = %d\n\n", getpid());
    while (1)
		config_signals();
	return (EXIT_SUCCESS);
}
