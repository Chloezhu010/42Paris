/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:11:43 by czhu              #+#    #+#             */
/*   Updated: 2024/09/22 18:12:37 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z')
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
	printf("%d\n", ft_str_is_uppercase("ABCAEFD"));
	printf("%d\n", ft_str_is_uppercase("abdrwdfe"));
	printf("%d\n", ft_str_is_uppercase("xwe';["));	
	printf("%d\n", ft_str_is_uppercase(""));
}*/
