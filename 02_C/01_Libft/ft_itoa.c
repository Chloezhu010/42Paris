/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:21 by czhu              #+#    #+#             */
/*   Updated: 2024/11/29 16:11:02 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	check_negative(long n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

static int	count_digit(long n)
{
	int	count;

	count = 0;
	if (check_negative(n) == 1)
		n = -n;
	while (n / 10 >= 1)
	{
		count++;
		n = n / 10;
	}
	return (count + 1);
}

static long	ft_abs(long n)
{
	if (check_negative(n) == 1)
		n = -n;
	return (n);
}

static char	*ft_zero(long n)
{
	char	*res;

	res = malloc(2);
	if (!res)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	else
		return (NULL);
	return (res);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*res;
	int		i;
	int		negative;

	num = (long)n;
	negative = check_negative(num);
	res = malloc (count_digit(num) + negative + 1);
	if (!res)
		return (NULL);
	if (num == 0)
		res = ft_zero(num);
	num = ft_abs(num);
	i = count_digit(num) + negative - 1;
	res[count_digit(num) + negative] = '\0';
	while (num > 0)
	{
		res[i--] = num % 10 + '0';
		num /= 10;
	}
	if (negative)
		res[0] = '-';
	return (res);
}

#include <stdio.h>
int	main()
{
	int	n1 = -42;
	int	n2 = 0;
	int	n3 = 2147483647;
	int	n4 = -2147483648;
	int	n5 = -10;
	
	printf("count: %d\n", count_digit(n1));
	printf("count: %d\n", count_digit(n2));
	printf("count: %d\n", count_digit(n3));
	printf("count: %d\n", count_digit(n4));
	printf("count: %d\n", count_digit(n5));

	printf("%s\n", ft_itoa(n1));
	printf("%s\n", ft_itoa(n2));
	printf("%s\n", ft_itoa(n3));
	printf("%s\n", ft_itoa(n4));
	printf("%s\n", ft_itoa(n5));
}
