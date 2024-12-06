/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:28:04 by czhu              #+#    #+#             */
/*   Updated: 2024/12/06 17:56:57 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int n, int *len)
{
	long	num;

	num = n;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
	}
	if (num < 0)
	{
		ft_putchar_len('-', len);
		num = -num;
	}
	if (n > 9)
		ft_number(num / 10, len);
	ft_putchar_len((num % 10 + '0'), len);
}
/*
void	ft_unsigned(unsigned int n, int *len)


void	ft_hex(unsigned int n, int *len, char x_or_x)


void	ft_ptr(size_t ptr, int *len)
*/

int	main()
{
	int	len = 0;
	int	*leng = &len;

	ft_number(0, length);
	write(1, "\n", 1);
	len = 0;

	ft_number(42, length);
	write(1, "\n", 1);
	len = 0;


	ft_number(2147483647, length);
	write(1, "\n", 1);
	len = 0;

	ft_number(-2147483648, length);
	write(1, "\n", 1);
}
