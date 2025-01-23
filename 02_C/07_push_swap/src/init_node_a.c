#include "../incl/push_swap.h"

/* assign an index to each node & determine its position <> median */
void    current_index(t_stack_node *stack)
{
    int i;
    int mid;

    i = 0;
    if (!stack)
        return;
    mid = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= mid)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}

/* find the target node in B for each node in A,
    target node: the closest smaller number in B,
    key steps: for each node in A
    - initialize best_match_index to LONG_MIN
    - loop through each node in B to update the best_match_index
    - if no smaller nbr found in B, set the target ndoe the max nbr in B */
void    set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *curr_b;
    t_stack_node    *target_node;
    long            best_match_index;

    while (a)
    {
        best_match_index = LONG_MIN;
        curr_b = b;
        // loop through B to find the best_match_index
        while (curr_b)
        {
            if (curr_b->nbr < a->nbr && curr_b->nbr > best_match_index)
            {
                best_match_index = curr_b->nbr;
                target_node = curr_b;
            }
            curr_b = curr_b->next;
        }
        // if no smaller nbr, set the target node as the max nbr in B
        if (best_match_index == LONG_MIN)
            a->target_node = find_max(b);
        else
            a->target_node = target_node;
        // move forward A
        a = a->next;
    }

}

/* push cost = # of operations required to move the node
    & target node to the top 
    purpose: determine the cheapest node to move, min the sorting opers */
void    cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while (a)
    {
        a->push_cost = a->index;
        // if a is below median, push cost = len_a - a's index (through rra)
        if (a->above_median == false)
            a->push_cost = len_a - (a->index);
        // if a' target node is above median
        if (a->target_node->above_median == true)
            a->push_cost += a->target_node->index;
        else // a is above median, target node is below median
            a->push_cost += len_b - (a->target_node->index);
        a = a->next;
    }
}

/* identify the cheapest node in the stack,
    mark it by setting the cheapest flag as true 
    purpose: the cheapest node is the one with least # of opers */
void    set_cheapest(t_stack_node *stack)
{
    long            cost;
    t_stack_node    *cheapest_node;

    if (!stack)
        return;
    cost = LONG_MAX;
    while (stack)
    {
        // find the node with the lowest push cost
        if (stack->push_cost < cost)
        {
            cost = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    cheapest_node->cheapest = true;
}

/* prepare nodes in A to be pushed to B */
void    init_node_a(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis_a(a, b);
    set_cheapest(a);
}