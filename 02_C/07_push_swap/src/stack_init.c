/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:27:55 by czhu              #+#    #+#             */
/*   Updated: 2025/01/24 12:35:45 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/* convert string to long */
static long	ft_atol(char *str)
{
	long	res;
	int		i;
	int		sign;

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
void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*curr;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->nbr = n;
	new_node->cheapest = 0;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
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
void	init_stack_a(t_stack_node **a, char **nbr, int is_split)
{
	long	n;
	int		i;

	i = 0;
	while (nbr[i])
	{
		if (error_syntax(nbr[i]))
			free_error(a, nbr, is_split);
		n = ft_atol(nbr[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_error(a, nbr, is_split);
		if (error_duplicate(*a, (int)n))
			free_error(a, nbr, is_split);
		append_node(a, (int)n);
		i++;
	}
}

/* search for the cheapest node in the stack */
t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// prep the stack, so that the node is at the top to be pushed
void	prep_for_push(t_stack_node **stack, t_stack_node *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (stack_name == 'b')
		{
			if (node->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}
