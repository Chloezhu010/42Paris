/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:54:09 by czhu              #+#    #+#             */
/*   Updated: 2024/10/03 11:09:31 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*result;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	result = (int *) malloc(sizeof(int) * (max - min));
	if (!result)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}
	*range = result;
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	int *range;
	
	printf("5:%d\n", ft_ultimate_range(&range, 0, 5));
	printf("0:%d\n", ft_ultimate_range(&range, 3, 3));
	printf("2:%d\n", ft_ultimate_range(&range, -1, 1));
}*/
