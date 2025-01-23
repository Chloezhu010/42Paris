#include "../incl/push_swap.h"

/* convert string to long */
static long    ft_atol(char *str)
{
    long    res;
    int     i;
    int     sign;

    res = 0;
    i = 0;
    sign = 1;
    if (!str)
        return (0);
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * sign);
}

/* append node to the stack */
void append_node(t_stack_node **stack, int n)
{
    t_stack_node    *new_node;
    t_stack_node    *curr;
    
    if (!stack)
        return;
    new_node = malloc(sizeof(t_stack_node));
    if (!new_node)
        return ;
    new_node->next = NULL; // intialize with null, as it will be the last node
    new_node->nbr = n; // set the value of the node as n
    new_node->cheapest = 0; // initialize with 0
    if (*stack == NULL) // if the stack is empty, aka no node
    {
        *stack = new_node; // set the header to the new node
        new_node->prev = NULL; // set the prev as null, as it's the first node
    }
    else
    {
        curr = *stack;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new_node;
        new_node->prev = curr;
    }
}

/* initialize stack a, append node & handle errors */
void    init_stack_a(t_stack_node **a, char **av)
{
    long    n;
    int     i;

    i = 0;
    while (av[i])
    {
        if (error_syntax(av[i])) // check syntax problem
            free_error(a);
        n = ft_atol(av[i]); // convert the string to long
        if (n > INT_MAX || n < INT_MIN) // check int limits
            free_error(a);
        if (error_duplicate(*a, (int)n)) // check duplicate problem
            free_error(a);
        append_node(a, (int)n);
        i++;
    }
}

/* search for the cheapest node in the stack */
t_stack_node    *get_cheapest(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest == true)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

// prep the stack, so that the node is at the top to be pushed
void    prep_for_push(t_stack_node **stack, t_stack_node *node, char stack_name)
{
    while (*stack != node)
    {
        if (stack_name == 'a')
        {
            if (node->above_median)
                ra(stack, false);
            else
                rra(stack, false);
        }
        else if (stack_name == 'b')
        {
            if (node->above_median)
                rb(stack, false);
            else
                rrb(stack, false);
        }
    }
}
