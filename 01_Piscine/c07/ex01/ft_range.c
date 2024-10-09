/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:51:09 by czhu              #+#    #+#             */
/*   Updated: 2024/10/02 17:52:13 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*ptr;

	size = max - min;
	if (size <= 0)
		return (0);
	ptr = (int *)malloc(sizeof(ptr) * size);
	if (ptr == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (min < max)
		{
			ptr[i] = min;
			min++;
			i++;
		}
		return (ptr);
	}
}
/*
#include <stdio.h>
int	main()
{
	int	*tab;
	int	min;
	int	max;
	int	size;
	int	i;

	i = 0;
	min = -8;
	max = 7;
	size = max - min;
	tab = ft_range(min, max);

	if (size < 0)
		return (0);
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
}*/
