#include "../incl/push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
    char    **res;
    int     i;

    if (ac != 2)
        printf("error\n");
    res = av_split(av[1], ' ');
    if (!res)
        printf("error: av_split returns null\n");
    i = 0;
    while (res[i])
    {
        printf("result[%d]= %s\n", i, res[i]);
        i++;
    }
    free_split(res);
}