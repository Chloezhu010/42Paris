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
    curr = stack;
    if (!stack)
        return (0);
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return (count);
}

t_stack_node    *find_max(t_stack_node *stack)
{
    long            max;
    t_stack_node    *max_node;

    if (!stack)
        return (NULL);
    max = LONG_MIN;
    while (stack)
    {
        if (stack->nbr > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}

t_stack_node    *find_min(t_stack_node *stack)
{
    long            min;
    t_stack_node    *min_node;

    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}