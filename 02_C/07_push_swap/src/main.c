/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:58:34 by czhu              #+#    #+#             */
/*   Updated: 2025/01/25 12:05:06 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static void	sort_stack_a(t_stack_node **a, t_stack_node **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, 0);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**nbr;
	int				is_split;

	a = NULL;
	b = NULL;
	is_split = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit (1);
	if (ac == 2)
	{
		nbr = ft_split(av[1], ' ');
		is_split = 1;
	}
	else
		nbr = av + 1;
	init_stack_a(&a, nbr, is_split);
	sort_stack_a(&a, &b);
	free_stack(&a);
	if (is_split == 1)
		ft_freeup(nbr);
}
