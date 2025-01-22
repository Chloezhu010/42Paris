#include "../incl/push_swap.h"

// rotate the top node to the bottom
void    rotate(t_stack_node **stack)
{
    t_stack_node    *first;
    t_stack_node    *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    first = *stack;
    last = *stack;
    // find the last node
    while (last->next != NULL)
        last = last->next;
    // move the first node to the end
    *stack = first->next;
    (*stack)->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
}

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (!print)
        ft_printf("ra\n");
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (!print)
        ft_printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (!print)
        ft_printf("rr\n");
}