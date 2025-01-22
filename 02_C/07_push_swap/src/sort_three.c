#include "../incl/push_swap.h"

void    sort_three(t_stack_node **a)
{
    t_stack_node    *biggest;

    biggest = find_max(*a);
    if (biggest == *a)
        ra(a, false); // if the 1st node is the biggest, rotate the top node to the bottom
    else if (biggest == (*a)->next)
        rra(a, false); // if the 2nd node is the biggest, rev rotate the bottom to the top
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false); // if the 1st > 2nd, then swap them
}