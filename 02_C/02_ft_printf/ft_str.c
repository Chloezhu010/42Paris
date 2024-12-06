/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:18:15 by czhu              #+#    #+#             */
/*   Updated: 2024/12/06 17:24:51 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_string(char *args, int *len)
{
	int	i;

	if (args == NULL)
	{
		write(1, "(null)", 6);
		(*len) += 6;
	}
	i = 0;
	while (args[i])
	{
		ft_putchar_len(args[i], *len);
		i++;
	}
}
