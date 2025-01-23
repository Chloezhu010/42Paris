#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "../src/libft/libft.h"

typedef struct  s_stack_node
{
    int                 nbr; // value of the node
    int                 index; // index position of the node
    int                 push_cost;
    bool                above_median;
    bool                cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next; // move forward
    struct s_stack_node *prev; // move backward
} t_stack_node;

// handle input
char    **av_split(char *str, char c);
int     error_syntax(char *str);
int     error_duplicate(t_stack_node *a, int n);
void    free_stack(t_stack_node **stack);
void    free_error(t_stack_node **a);

// stack initiation
void    append_node(t_stack_node **stack, int n);
void    init_stack_a(t_stack_node **a, char **av);
t_stack_node    *get_cheapest(t_stack_node *stack);
void    prep_for_push(t_stack_node **stack, t_stack_node *node, char stack_name);

// stack utils
bool    stack_sorted(t_stack_node *stack);
int     stack_len(t_stack_node *stack);
t_stack_node    *find_max(t_stack_node *stack);
t_stack_node    *find_min(t_stack_node *stack);

// commands
void    swap(t_stack_node **stack);
void    sa(t_stack_node **a, bool print);
void    sb(t_stack_node **b, bool print);
void    ss(t_stack_node **a, t_stack_node **b, bool print);
void    rotate(t_stack_node **stack);
void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);
void    rev_rotate(t_stack_node **stack);
void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);
void    push(t_stack_node **src, t_stack_node **dest);
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);

// nodes initiation
void    current_index(t_stack_node *stack);
void    set_target_a(t_stack_node *a, t_stack_node *b);
void    set_target_b(t_stack_node *a, t_stack_node *b);
void    cost_analysis_a(t_stack_node *a, t_stack_node *b);
void    set_cheapest(t_stack_node *stack);
void    init_node_a(t_stack_node *a, t_stack_node *b);
void    init_node_b(t_stack_node *a, t_stack_node *b);

// algo
void    sort_three(t_stack_node **a);
void    sort_stack(t_stack_node **a, t_stack_node **b);
void    move_a_to_b(t_stack_node **a, t_stack_node **b);
void    move_b_to_a(t_stack_node **a, t_stack_node **b);
void    min_to_top(t_stack_node **a);

#endif