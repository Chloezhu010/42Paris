/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:36:35 by czhu              #+#    #+#             */
/*   Updated: 2024/12/06 17:10:12 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(va_list args, char spec, int *len)
{
	if (spec == 'c')
		ft_putchar_len(va_arg(args, int), len);
	else if (spec == 's')
		ft_string(va_arg(args, char *), len);
	else if (spec == 'p')
		ft_ptr(va_arg(args, size_t), len);
	else if (spec == 'd' || string[i] == 'i')
		ft_number(va_arg(args, int), len);
	else if (spec == 'u')
		ft_unsigned(var_arg(args, unsigned int), len);
	else if (spec == 'x')
		ft_hex(va_arg(args, unsigned int), len, 'x');
	else if (spec == 'X')
		ft_hex(va_arg(args, unsigned int), len, 'X');
	else if (string[i] == '%')
		ft_putchar_len('%', len);
	return (*len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		len;

	va_start(args, string);
	len = 0;
	while (*string)
	{
		if (*string == '%')
		{
			str++;
			print_arg(args, *string, &len);
		}
		else
			ft_putchar_len(*string, &len);
		string++;
	}
	va_end(args);
	return (len);
}
