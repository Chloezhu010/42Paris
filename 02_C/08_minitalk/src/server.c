#include "../incl/minitalk.h"

/* convert bits to char;
    SIGUSR1 -> 1 using OR and assign
    SIGUSR2 -> 0 using AND NOT and assign
    when received 8 bits, print the char */
void    ft_btoa(int sig)
{
    static int  bit;
    static int  i;

    if (sig == SIGUSR1)
        i |= (1 << bit);
    else if (sig == SIGUSR2)
        i &= ~(1 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int main()
{
    // display the server PID
    ft_printf("Server PID: %d\n", getpid());
    // keep the server alive, listening to signals
    while (1)
    {
        signal(SIGUSR1, ft_btoa);
        signal(SIGUSR2, ft_btoa);
        pause();
    }
    return (0);
}