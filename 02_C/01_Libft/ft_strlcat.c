/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:21 by czhu              #+#    #+#             */
/*   Updated: 2024/11/26 16:03:16 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	copy_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len >= siz)
		return (src_len + siz);
	copy_len = siz - dst_len - 1;
	while (i < copy_len)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
/*
#include <stdio.h>
int	main()
{
	char	src[] = "world!";
	char	dst[10] = "hello, ";
	size_t	result = ft_strlcat(dst, src, 7);

	printf("Result: %s, Total length: %zu\n", dst, result);
}*/
