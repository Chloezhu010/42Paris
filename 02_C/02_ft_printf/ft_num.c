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
	return (print_char(n + '0'));
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
/*
#include <limits.h>
#include <stdio.h>
int	main()
{
	// test on %d & %i
	print_digit(0);
	print_char('\n');
	print_digit(42);
	print_char('\n');
	print_digit(-42);
	print_char('\n');
	print_digit(INT32_MIN);
	print_char('\n');
	print_digit(INT32_MAX);
	print_char('\n');
	printf("%d\n %d\n %d\n %d\n %d\n ", 0, 42, -42, INT32_MIN, INT32_MAX);

	// test on %u
	print_unsigned(0);
	print_char('\n');
	print_unsigned(UINT_MAX);
	print_char('\n');
	printf("%u\n %u\n ", 0, UINT_MAX);

	// test on %x and %X
	print_hex(-10, 'x');
	print_char('\n');
	print_hex(0, 'x');
	print_char('\n');
	print_hex(UINT_MAX, 'X');
	print_char('\n');
	printf("%x\n %x\n %X\n ", -10, 0, UINT_MAX);

	// test on %p
	int	num = 42;
	char str[] = "hello world";
	void *ptr1 = &num;
	void *ptr2 = str;
	void *ptr3 = NULL;
	
	int len1_real = printf("%p", ptr1);
	int len1_my = print_ptr((size_t)ptr1);
	printf("\nreal vs my: %d : %d \n", len1_real, len1_my);

	int len2_real = printf("%p", ptr2);
	int len2_my = print_ptr((size_t)ptr2);
	printf("\nreal vs my: %d : %d \n", len2_real, len2_my);

	int len3_real = printf("%p", ptr3);
	int len3_my = print_ptr((size_t)ptr3);
	printf("\nreal vs my: %d : %d \n", len3_real, len3_my);
}*/