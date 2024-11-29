/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:21 by czhu              #+#    #+#             */
/*   Updated: 2024/11/28 14:29:43 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_s;
	size_t	i;
	size_t	j;

	len_s = ft_strlen(s);
	if (len_s == 0)
		return (NULL);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	return (ptr);
}
/*
#include <stdio.h>
int	main()
{
	char	s[] = "hello, world!";
	unsigned int	start = 5;
	size_t	len = 6;

	printf("%s\n", ft_substr(s, start, len));
}*/
