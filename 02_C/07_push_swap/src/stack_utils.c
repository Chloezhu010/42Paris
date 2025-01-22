#include "../incl/push_swap.h"

// check if the stack is sorted
bool    stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (1);
    while (stack->next != NULL)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}

// cal # of elements in the stack
int stack_len(t_stack_node *stack)
{
    int             count;
    t_stack_node    *curr;
    
    count = 0;
    if (!stack)
        return (0);
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return (count);
}