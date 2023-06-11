#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main (int argc, char **argv)
{
    ft_printf("CLIENT PID = %d\n\n", getpid());
    //Checar Se argumentos foram passados corretamente = ./minitalk <PID> <mensagem>
    //setar os sinais
    //enviar a mensagem
    return (EXIT_SUCCESS);
}

