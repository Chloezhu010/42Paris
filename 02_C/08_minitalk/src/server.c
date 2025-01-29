#include "../incl/minitalk.h"

void    ft_send_ok(pid_t pid)
{
    if (kill(pid, SIGUSR1) < 0)
        ft_error(0);
}

void    ft_sig_handler(int sig, siginfo_t *info, void *context)
{
    static int  bit = 1;
    static pid_t  client_id = 0;
    static char c = 0;

    (void)context;
    // only update the client id when there is a valide si_pid
    if (info->si_pid != 0)
        client_id = info->si_pid;
    // convert bits to char
    // SIGUSR1 -> 0, SIGUSR2 -> 1
    if (sig == SIGUSR1)
        c += 0;
    if (sig == SIGUSR2)
        c += bit;
    bit <<= 1;
    if (bit == 256)
    {
        // reset bit to 1
        bit = 1;
        // if c = 0, send sigusr2 to the client
        if (c == 0)
            if (kill(client_id, SIGUSR2) < 0)
                ft_error(0);
        if (c != 0)
            ft_printf("%c", c);
        //reset c to 0
        c = 0;
    }
    // send sigusr1 to the client for message acknowledgement
    if (kill(client_id, SIGUSR1) < 0)
        ft_error(0);
}

int main()
{
    pid_t   pid;
    struct sigaction    sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = ft_sig_handler;
    pid = getpid();
    if (sigaction(SIGUSR1, &sa, NULL) < 0 || sigaction(SIGUSR2, &sa, NULL) < 0)
        ft_error(1);
    ft_printf("PID: %d\n", pid);
    while (1)
        pause();
    return (0);
}