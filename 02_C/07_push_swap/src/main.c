#include "../incl/push_swap.h"

#include <stdio.h>
int main(int ac, char **av)
{
    // declare ptrs to 2 linked list, for stack A & B
    t_stack_node    *a;
    t_stack_node    *b;
    char            **nbr;
    
    // set both to null
    a = NULL;
    b = NULL;
    // handle input count errors. ac must >= 2 and 2nd arg must not be empty
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1); // if input error, return error
    if (ac == 2)  // if in string format
    {
        nbr = av_split(av[1], ' ');
        if (!nbr)
        {
            ft_printf("Error\n");
            return (1);
        }
    }
    else
        nbr = av + 1;

    // initialize stack A by appending each input number as a node to it
    init_stack_a(&a, nbr); 
    // check if stack A is sorted
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2) // if stack has 2 nbr, simply swap
            sa(&a, false);
        else if (stack_len(a) == 3) // if stack has 3 nbr, use sort three algo
            sort_three(&a);
        else
            sort_stack(&a, &b); // if stack has >3 nbr, use Turk algo
    }
    free_stack(&a);
    return (0); 
}