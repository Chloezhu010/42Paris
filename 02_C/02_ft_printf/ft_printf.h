/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:52:41 by czhu              #+#    #+#             */
/*   Updated: 2024/12/06 16:46:59 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
/* prototype */
void	ft_putchar_len(char c, int *len);
void	ft_string(char *args, int *len);
void	ft_number(int n, int *len);
void	ft_unsigned(unsigned int n, int *len);
void	ft_hex(unsigned int n, int *len, char x_or_x);
void	ft_ptr(size_t ptr, int *len);

int	ft_printf(const char *string, ...)
#endif
