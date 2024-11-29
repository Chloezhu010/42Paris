/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:21 by czhu              #+#    #+#             */
/*   Updated: 2024/11/29 17:15:07 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_neg(long n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

int	count_digi(int n)
{
	long	num;
	int		count;
	int		negative;

	num = (long)n;
	count = 0;
	negative = check_neg(num);
	if (negative)
		num = -num;
	while (num / 10 > 1)
	{
		count++;
		num = num / 10;
	}
	return (count + negative + 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	write(fd, ft_itoa(n), count_digi(n));
}
/*
#include <stdio.h>
int	main()
{
	int	n1 = -42;
	int	n2 = 456;
	int	n3 = 0;
	int	n4 = 2147483647;
	int	n5 = -2147483648;

	ft_putnbr_fd(n1, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(n2, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(n3, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(n4, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(n5, 1);
}*/
