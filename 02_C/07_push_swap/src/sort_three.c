/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:26:31 by czhu              #+#    #+#             */
/*   Updated: 2025/01/24 12:27:40 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ra(a, 0);
	else if (biggest == (*a)->next)
		rra(a, 0);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 0);
}
