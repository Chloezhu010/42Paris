/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:52:41 by czhu              #+#    #+#             */
/*   Updated: 2024/12/09 15:01:47 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

int	print_format(char spec, va_list *ap);
int	print_digit(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int n, char base);
int	print_ptr_hex(unsigned long long n);
int	print_ptr(void *ptr);
int	print_char(int c);
int	print_string(char *str);

int	ft_printf(const char *format, ...);
#endif
