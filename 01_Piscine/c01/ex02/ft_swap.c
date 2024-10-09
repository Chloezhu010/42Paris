/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:23:17 by czhu              #+#    #+#             */
/*   Updated: 2024/09/21 17:23:55 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
#include <stdio.h>

int main(void){
	int a, b;
	int *ptra, *ptrb;
	
	a = 4;
	b = 2;

	ptra = &a;
	ptrb = &b;
	
	printf("before ab:%d%d\n", a, b);
	ft_swap(ptra, ptrb);
	printf("after ab:%d%d\n", a, b);
}*/
