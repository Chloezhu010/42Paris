/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:46:13 by czhu              #+#    #+#             */
/*   Updated: 2024/12/02 15:41:51 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	while (n - 1 > 0 && (*ptr1 == *ptr2))
	{
		ptr1++;
		ptr2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ptr1 - *ptr2);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	int data1[] = {1,2,3,4,5};
	int data2[] = {1,2,3,4,10};
	
	printf("old: %d\n", memcmp(data1, data2, 5 * sizeof(int)));
	printf("old: %d\n", memcmp(data1, data2, 4 * sizeof(int)));
	printf("new: %d\n", ft_memcmp(data1, data2, 5 * sizeof(int)));
	printf("new: %d\n", ft_memcmp(data1, data2, 4 * sizeof(int)));

	char	*s1 = "zyxbc";
	char	*s2 = "abced";

	printf("old: %d\n", memcmp(s1, s2, 0));
	printf("new: %d\n", ft_memcmp(s1, s2, 0));
}*/
