#include "../incl/minitalk.h"

void    ft_error(int n)
{
    if (n == 1)
    {
        ft_printf("Error sigaction\n");
        exit(1);
    }
    if (n == 0)
    {
        ft_printf("Error kill\n");
        exit(1);
    }
}