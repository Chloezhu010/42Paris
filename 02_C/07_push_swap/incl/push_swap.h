#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "../src/libft/libft.h"

typedef struct  s_stack_node
{
    int nbr; // value of the node
    int index; // index position of the node
    int push_cost;
    bool                above_median;
    bool                cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next; // move forward
    struct s_stack_node *prev; // move backward
} t_stack_node;

// handle input
int     error_syntax(char *str);
int     error_duplicate(t_stack_node *a, int n);
void    free_stack(t_stack_node **stack);
void    free_error(t_stack_node **a);

// stack initiation
void    append_node(t_stack_node **stack, int n);
void    init_stack_a(t_stack_node **a, char **av);

// stack utils
bool    stack_sorted(t_stack_node *stack);
int     stack_len(t_stack_node *stack);
t_stack_node    *find_max(t_stack_node *stack);
t_stack_node    *find_min(t_stack_node *stack);

// nodes initiation



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

// algo

#endif