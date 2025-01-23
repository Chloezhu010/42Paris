#include "../incl/push_swap.h"

/* rotate both stacks, until the cheapest node in A and
    its target node in B are at the top */
void    rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while (*b != cheapest_node->target_node && *a != cheapest_node)
        rr(a, b, false);
    current_index(*a);
    current_index(*b);
}

/* rev rotate both stacks, until the cheapest node in A and
    its target node in B are at the top */
void    rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while (*b != cheapest_node->target_node && *a != cheapest_node)
        rrr(a, b, false);
    current_index(*a);
    current_index(*b);
}

void    move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *cheapest_node;

    cheapest_node = get_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target_node->above_median)
        rotate_both(a, b, cheapest_node);
    else if (cheapest_node->above_median == false && cheapest_node->target_node->above_median == false)
        rev_rotate_both(a, b, cheapest_node);
    prep_for_push(a, cheapest_node, 'a');
    prep_for_push(b, cheapest_node->target_node, 'b');
    pb(b, a, false);
}

void    move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    prep_for_push(a, (*b)->target_node, 'a');
    pa(a, b, false);
}

// bring the min node to the top
void    min_to_top(t_stack_node **a)
{
    while ((*a)->nbr != find_min(*a)->nbr)
    {
        if (find_min(*a)->above_median == true)
            ra(a, false);
        else
            rra(a, false);
    }
}

// sort stack A, if it has over 3 nodes
void    sort_stack(t_stack_node **a, t_stack_node **b)
{
    int len_a;

    len_a = stack_len(*a);
    // if stack A has >3 nodes and not sorted, push the first 2 nodes to B
    if (len_a-- > 3 && stack_sorted(*a) == false)
        pb(b, a, false);
    if (len_a-- > 3 && stack_sorted(*a) == false)
        pb(b, a, false);
    // if still > 3 nodes and not sorted, continue to push nodes from A to B
    while (len_a > 3 && stack_sorted(*a) == false)
    {
        init_node_a(*a, *b); // initialize nodes for sorting
        move_a_to_b(a, b); // move the cheapeast node from A to B
        len_a--;
    }
    // until A only has 3 nodes, then use sort_three algo
    sort_three(a);
    // then move nodes from B back to A
    while (*b)
    {
        init_node_b(*a, *b);
        move_b_to_a(a, b);
    }
    // finali adjustment to A
    current_index(*a); // refresh the current position of nodes in A
    min_to_top(a); // move the min nodes to the top
}