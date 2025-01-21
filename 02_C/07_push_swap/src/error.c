#include "../incl/push_swap.h"

// handle syntax error: return 1 when error
int error_syntax(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        // if the char is not sign or digit
        if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
            return (1);
        // if the char is sign, but the next char is not digit
        if ((str[i] == '+' || str[i] == '-') && !(str[1] >= '0' && str[1] <= '9'))
            return (1);
        while (str[++i])
        {
            if (!(str[i] >= '0' && str[i] <= '9'))
                return (1);
            // i++;
        }
    }
    return (0);
}

// handle duplicate error: return 1 when error
int error_duplicate(t_stack_node *a, int n)
{
    // check if empty stack
    if (!a)
        return (0);
    // loop through the stack to check nbr
    while (a)
    {
        if (a->nbr == n)
            return (1);
        a = a->next;
    }
    return (0);
}

// free a stack if error occurs
void    free_stack(t_stack_node **stack)
{
    t_stack_node    *temp;
    t_stack_node    *curr;

    if (!stack)
        return ;
    curr = *stack;
    while (curr != NULL)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    *stack = NULL;
}

// free stack and return error message
void    free_error(t_stack_node **a)
{
    free_stack(a);
    ft_printf("Error\n");
    exit(1);
}


// ==== below testing ====
#include <stdio.h>

// testing syntax
// int main()
// {
//     char    *s1 = "+42";
//     char    *s2 = "-98";
//     char    *s3 = "  -42";
//     char    *s4 = "+-42abc";

//     printf("%d\n", error_syntax(s1));
//     printf("%d\n", error_syntax(s2));
//     printf("%d\n", error_syntax(s3));
//     printf("%d\n", error_syntax(s4));
// }