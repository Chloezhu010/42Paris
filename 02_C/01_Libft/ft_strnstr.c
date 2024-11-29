/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:21 by czhu              #+#    #+#             */
/*   Updated: 2024/11/28 10:27:53 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big && little_len <= len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	const char *big = "hello, world";
	const char *little = "world";
	char *ptr = ft_strnstr(big, little, 7);

	if (ptr != NULL)
		printf("first occurrence: %s\n", ptr);
	else
		printf("not found");
}*/
