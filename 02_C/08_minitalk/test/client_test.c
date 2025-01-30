#include "../incl/minitalk.h"


void    ft_send_signal(int pid, char *str)
{
    static int  bit = 0;
    static char *str_bit = 0;

    if (str);
        str_bit = str;
    if (*str_bit)
    {
        if ((((unsigned char)*str_bit >> bit) % 2) == 0)
            kill(pid, SIGUSR1);
        else if ((((unsigned char)*str_bit >> bit) % 2) == 1)
            kill(pid, SIGUSR2);
        bit++;
        if (bit == 8)
        {
            str_bit++;
            bit = 0;
        }
    }
    if (*str_bit == '\0')
        kill(pid, SIGUSR1);
}

void    ft_receipt(int sig, siginfo_t *info, void *context)
{
    static int  id;

    (void)context;
    if (info->si_pid != 0)
        id = info->si_pid;
    if (sig == SIGUSR1)
    {
        ft_printf("ok\n");
        ft_send_signal(id, NULL);
    }
    else if (sig == SIGUSR2)
        exit(0);
}

int main(int ac, char **av)
{
    struct sigaction    sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = ft_receipt;
    if (ac != 3)
    {
        ft_printf("Error input\n");
        exit (1);
    }
    ft_send_signal(ft_atoi(av[1]), av[2]);
    while (1)
        pause();
    return (0);
}