/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:05:50 by czhu              #+#    #+#             */
/*   Updated: 2024/09/22 18:05:55 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 97 || str[i] > 122)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_str_is_lowercase("aasdqwefsasd"));
	printf("%d\n", ft_str_is_lowercase("123561"));
	printf("%d\n", ft_str_is_lowercase("ABD#dxas"));
	printf("%d\n", ft_str_is_lowercase(""));
}*/
