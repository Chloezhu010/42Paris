#include "../incl/minitalk.h"

void    ft_sig_handler(int sig, siginfo_t *info, void *context)
{
    pid_t   id;
    static int  bit = 0;
    static char c = 0;

    (void)context;
    if (info->si_pid != 0)
        id = info->si_pid;
    if (sig == SIGUSR1)
        c += 0;
    if (sig == SIGUSR2)
        c += bit;
    bit <<= 1;
    if (bit == 256)
    {
        bit = 1;
        if (c == 0)
            kill(id, SIGUSR2);
        else if (c != 0)
            ft_printf("%c", c);
        c = 0;
    }
    kill(id, SIGUSR1);
}

int main()
{
    pid_t   pid;
    struct sigaction    sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = ft_sig_handler;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    ft_printf("PID: %d\n", pid);
    while (1)
        pause();
    return (0);
}