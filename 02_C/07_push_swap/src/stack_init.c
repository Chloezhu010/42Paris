#include "../incl/push_swap.h"
// convert string to long
static long    ft_atol(char *str)
{
    
}

// append node to the stack
static void append_node(t_stack_node **stack, int n)
{

}


// initialize stack a, append node & handle errors
void    init_stack_a(t_stack_node **a, char **av)
{
    long    n;
    int     i;

    i = 0;
    while (av[i])
    {
        if (error_syntax(av[i])) // check syntax
            free_error(a);
        n = ft_atol(av[i]); // convert the string to long
        if (n > INT_MAX || n < INT_MIN) // check int limits
            free_error(a);
        if (error_duplicate(*a, (int)n))
            free_error(a);
        append_node(a, (int)n);
        i++;
    }
}