/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:21 by czhu              #+#    #+#             */
/*   Updated: 2024/11/28 11:31:12 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space(const char *s)
{
	while (*s)
	{
		if ((*s >= 7 && *s <= 13) || *s == 32)
			return (1);
		s++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	negative;
	int	result;

	negative = 0;
	result = 0;
	while (check_space(nptr) == 1)
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			negative ++;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - 48;
		nptr++;
	}
	if (negative == 1)
		return (-1 * result);
	else if (negative > 1)
		return (0);
	return (result);
}

#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char	str1[] = "123";
	char	str2[] = "   --456";
	char	str3[] = "   +456";
	char	str4[] = "abd123";
	char	str5[] = "2147483647";
	char	str6[] = "-2147483648";

	printf("%d: %d\n", atoi(str1), ft_atoi(str1));
	printf("%d: %d\n", atoi(str2), ft_atoi(str2));
	printf("%d: %d\n", atoi(str3), ft_atoi(str3));
	printf("%d: %d\n", atoi(str4), ft_atoi(str4));
	printf("%d: %d\n", atoi(str5), ft_atoi(str5));
	printf("%d: %d\n", atoi(str6), ft_atoi(str6));
}
