#include "../incl/push_swap.h"

// rotate the bottom to the top
void    rev_rotate(t_stack_node **stack)
{
    t_stack_node    *last;
    t_stack_node    *second_last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    last = *stack;
    // find the last node
    while (last->next)
        last = last->next;
    // find the second last and update
    second_last = last->prev;
    second_last->next = NULL;
    // move the last to the first
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

void    rra(t_stack_node **a, bool print)
{
    rev_rotate(a);
    if (!print)
        ft_printf("rra\n");
}

void    rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
    if (!print)
        ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!print)
        ft_printf("rrr\n");
}