#include "../incl/minitalk.h"

/* convert bits to char:
    - bit: track the current bit position, starting from LSB
    - c: acc. the bits to construct the char
    - client_id: store the client PID to send sig back
        - only update the client id when there is a validate si_pid
    - bitwise operation
        - SIGUSR1 -> 0, SIGUSR2 -> 1
    - char reconstruction
        - bit == 256 indicate 8 bits have been processed
        - reset bit to 1
        - if c = 0, reach end of the message, send SIGUSR2 to indicate the end
        - if c != 0, printout
        - reset c to 0 for the next char
    - acknowledgement
        - send SIGUSR1 to the client after processing each bit
*/
void    ft_sig_handler(int sig, siginfo_t *info, void *context)
{
    static int  bit = 1;
    static pid_t  client_id = 0;
    static char c = 0;

    (void)context;
    if (info->si_pid != 0)
        client_id = info->si_pid;
    if (sig == SIGUSR1)
        c += 0;
    if (sig == SIGUSR2)
        c += bit;
    bit <<= 1;
    if (bit == 256)
    {
        bit = 1;
        if (c == 0)
            if (kill(client_id, SIGUSR2) < 0)
                ft_error(0);
        if (c != 0)
            ft_printf("%c", c);
        c = 0;
    }
    if (kill(client_id, SIGUSR1) < 0)
        ft_error(0);
}

/*
    - printout PID
    - keep running & listening to the client
    - use sigaction to handle SIGUSR1 and SIGUSR2
        - sa_flags: enable the use of siginfo_t struct
*/
int main()
{
    pid_t   pid;
    struct sigaction    sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = ft_sig_handler;
    pid = getpid();
    if (sigaction(SIGUSR1, &sa, NULL) < 0 ||
        sigaction(SIGUSR2, &sa, NULL) < 0)
        ft_error(1);
    ft_printf("PID: %d\n", pid);
    while (1)
        pause();
    return (0);
}