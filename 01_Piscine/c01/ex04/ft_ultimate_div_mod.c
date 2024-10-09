/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:25:48 by czhu              #+#    #+#             */
/*   Updated: 2024/09/21 17:26:18 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a;
	mod = *b;
	*a = div / mod;
	*b = div % mod;
}
/*
#include <stdio.h>

int main(void){
	int a, b;

	a = 10;
	b = 3;

	printf("before a: %d, b: %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("after a: %d, b: %d", a, b);
}*/
