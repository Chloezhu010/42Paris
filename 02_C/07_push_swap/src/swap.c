#include "../incl/push_swap.h"

// swap function
void swap(t_stack_node **stack)
{
    t_stack_node    *first;
    t_stack_node    *second;

    // check if the ptr to the stack, the stack itself are null, and stack has >2 nodes
    if (!stack || !*stack || (*stack)->next == NULL)
        return ;
    first = *stack;
    second = first->next;

    first->next = second->next; // eg. 1 next now points to 3
    if (second->next)
        second->next->prev = first; // eg. 3 prev now points to 1
    second->prev = first->prev; // eg. 2 prev now points to null
    first->prev = second; // 1 prev now points to 2
    second->next = first; // 2 next now points to 1
    // update the stack header
    *stack = second;
}

// swap the first 2 nodes of a
void    sa(t_stack_node **a, bool print)
{
    swap(a);
    if (!print)
        ft_printf("sa\n");
}

// swap the first 2 nodes of b
void    sb(t_stack_node **b, bool print)
{
    swap(b);
    if (!print)
        ft_printf("sb\n");
}

// swap the first 2 nodes of a & b
void    ss(t_stack_node **a, t_stack_node **b, bool print)
{
    swap(a);
    swap(b);
    if (!print)
        ft_printf("ss\n");
}