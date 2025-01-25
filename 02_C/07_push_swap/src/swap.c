/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:52:25 by czhu              #+#    #+#             */
/*   Updated: 2025/01/24 12:54:58 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

// swap function
void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}

// swap the first 2 nodes of a
void	sa(t_stack_node **a, int print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

// swap the first 2 nodes of b
void	sb(t_stack_node **b, int print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

// swap the first 2 nodes of a & b
void	ss(t_stack_node **a, t_stack_node **b, int print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
