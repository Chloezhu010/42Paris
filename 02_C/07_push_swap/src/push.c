/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:08:17 by czhu              #+#    #+#             */
/*   Updated: 2025/01/24 12:10:39 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	node_to_push->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = node_to_push;
	*dest = node_to_push;
}

/* push from B to A */
void	pa(t_stack_node **a, t_stack_node **b, int print)
{
	push(b, a);
	if (!print)
		ft_printf("pa\n");
}

/* push from A to B */
void	pb(t_stack_node **b, t_stack_node **a, int print)
{
	push(a, b);
	if (!print)
		ft_printf("pb\n");
}
