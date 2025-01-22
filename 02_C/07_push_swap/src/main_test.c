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
    t_stack_node    *stack = NULL;

    append_node(&stack, 1);
    append_node(&stack, 4);
    append_node(&stack, 2);

    printf("stack before:\n");
    print_stack(stack);

    swap(&stack);
    printf("stack after:\n");
    print_stack(stack);
}