/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:51:59 by czhu              #+#    #+#             */
/*   Updated: 2025/01/24 11:58:14 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

/* handle syntax error: return 1 when error */
int	error_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '+' || str[i] == '-'
				|| (str[i] >= '0' && str[i] <= '9')))
			return (1);
		if ((str[i] == '+' || str[i] == '-')
			&& !(str[1] >= '0' && str[1] <= '9'))
			return (1);
		while (str[++i])
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
		}
	}
	return (0);
}

/* handle duplicate error: return 1 when error */
int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/* free a stack if error occurs */
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*curr;

	if (!stack)
		return ;
	curr = *stack;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*stack = NULL;
}

/* free stack and return error message */
void	free_error(t_stack_node **a, char **nbr, int is_split)
{
	free_stack(a);
	if (is_split && nbr)
		ft_freeup(nbr);
	ft_printf("Error\n");
	exit(1);
}
