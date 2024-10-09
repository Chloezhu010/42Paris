/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:30:05 by czhu              #+#    #+#             */
/*   Updated: 2024/09/21 17:53:47 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i ++;
		j --;
	}
}
/*
#include <stdio.h>

int main(void){
	int i = 0;
	int test[] = {1, 2, 3, 4, 5};

	ft_rev_int_tab(test, 5);
	
	while (i < 5)
	{
		printf("%d", test[i]);
		i++;
	}
}*/
