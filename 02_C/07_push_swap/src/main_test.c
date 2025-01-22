#include "../incl/push_swap.h"
#include <stdio.h>

void    print_stack(t_stack_node *stack)
{
    t_stack_node    *curr = stack;
    while (curr != NULL)
    {
        printf("%d ->", curr->nbr);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    t_stack_node    *stack_a = NULL;
    t_stack_node    *stack_b = NULL;

    append_node(&stack_a, 1);
    append_node(&stack_a, 4);
    append_node(&stack_a, 2);

    printf("stack before:\n");
    print_stack(stack_a);
    print_stack(stack_b);

    // swap(&stack_a);
    // rev_rotate(&stack_a);
    // rotate(&stack_a);
    push(&stack_a, &stack_b);
    printf("stack after:\n");
    print_stack(stack_a);
    print_stack(stack_b);
}