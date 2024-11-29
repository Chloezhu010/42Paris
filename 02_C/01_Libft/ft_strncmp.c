/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:21 by czhu              #+#    #+#             */
/*   Updated: 2024/11/26 17:31:07 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	main()
{
	int	result;
	int	result2;
	char	s1[] = "abz";
	char	s2[] = "def";
	size_t	n = 3;

	result = strncmp(s1, s2, n);
	result2 = ft_strncmp(s1, s2, n);
	printf("origin: %d\n", result);
	printf("new: %d\n", result2);
}*/
