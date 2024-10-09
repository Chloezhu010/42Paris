/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:12:47 by czhu              #+#    #+#             */
/*   Updated: 2024/09/23 13:37:50 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char x)
{
	if (x >= 'a' && x <= 'z')
		return (1);
	else if (x >= 'A' && x <= 'Z')
		return (1);
	return (0);
}

int	ft_str_no_alphanum(char x)
{
	if (x >= 0 && x <= 47)
		return (1);
	else if (x >= 58 && x <= 64)
		return (1);
	else if (x >= 91 && x <= 96)
		return (1);
	else if (x >= 123 && x < 127)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((ft_str_is_alpha(str[i]) && ft_str_no_alphanum(str[i - 1])))
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*
1. put every upcase alphabet in lowcase
2. find str[i-1] which is non-alpha or non-numeric, and str[i] is alpha
3. put str[i] in upcase

#include <stdio.h>
int	main(void)
{
	char test[] = "salut, commeNt tu vAS? 42mots quARante-deux; cinquante+et+un";
	char test1[] = "&@#%^&helo";
	char test2[] = "  111, born to code";
	printf("%s\n", ft_strcapitalize(test));
	printf("%s\n", ft_strcapitalize(test1));
	printf("%s\n", ft_strcapitalize(test2));
}*/
