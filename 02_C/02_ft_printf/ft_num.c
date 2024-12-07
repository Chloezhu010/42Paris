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

int	print_digit(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		count = write(1, "-", 1);
		return (count + print_digit(-n));
	}
	else if (n > 9)
	{
		count = print_digit(n / 10);
		return (count + print_digit(n % 10));
	}
	return (print_char(n + '0'));
}

int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count = print_unsigned(n / 10);
		return (count + print_unsigned(n % 10)); 
	}
	return (print_unsigned(n + '0'));
}


int	print_hex(unsigned int n, char base)
{
	int	count;
	char	*base_char;	

	count = 0;
	if (base == 'x')
		base_char = "0123456789abcdef";
	else
		base_char = "0123456789ABCDEF";
	if (n >= 16)
	{
		count = print_hex(n / 16, base);
		return (count + print_hex(n % 16, base));
	}
	else
		return (print_char(base_char[n]));
}

int	print_ptr_hex(size_t n)
{
	int	count;
	char	*base_char;

	base_char = "0123456789abcdef";
	if (n >= 16)
	{
		count = print_ptr_hex(n / 16);
		return (count + print_ptr_hex(n % 16));
	}
	return (print_char(base_char[n]));
}

int	print_ptr(size_t ptr)
{
	int	count;

	count = write(1, "0x", 2);
	if (ptr == 0)
		return (count + write(1, "0", 1));
	return (count + print_ptr_hex(ptr));	
}
