#include "../incl/minitalk.h"

/* convert char to bits, send to the server;
    kill: send a signal to the process specified by PID;
    SIGUSR1 -> 1; SIGUSR2 -> 0 
    unsleep: suspend execution for 300 microsend to avoid singal mixing */
void    ft_atob(int pid, char c)
{
    int     bit;

    bit = 0;
    while (bit < 8)
    {
        if ((c & (1 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(300);
        bit++;
    }
}


/* handle input, need to incl. PID and message, so ac == 3;
    encode the message and send to the server */
int main(int ac, char **av)
{
    int pid;
    int i;
    
    i = 0;
    if (ac == 3)
    {
        pid = ft_atoi(av[1]);
        while (av[2][i])
        {
            ft_atob(pid, av[2][i]);
            i++;
        }
    }
    else
    {
        ft_printf("Error\n");
        return (1);
    }
    return (0);
}