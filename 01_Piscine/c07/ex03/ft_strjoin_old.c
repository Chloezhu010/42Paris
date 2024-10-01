/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:54:29 by czhu              #+#    #+#             */
/*   Updated: 2024/10/01 17:42:37 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	sep_len;
	int	total_len;

	i = 0;
	total_len = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

char	*ft_fill(int size, char **strs, char *sep, char *ptr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcpy(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(ptr, sep);
			ptr += ft_strlen(sep);
		}
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	total_len;
	char	*result;
	char	*ptr;
	
	if (size == 0)
	{
		result = (char*)malloc(1);
		return (result);
	}
	total_len = ft_total_len(size, strs, sep);
	result = (char*)malloc(sizeof(char)*(total_len + 1));
	if (!result)
		return (0);
	ptr = result;
	result = ft_fill(size, strs, sep, ptr);
	return (result);
}

/*
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;
	char	*result;
	char	*ptr;

	if (size == 0)
	{
		result = (char*) malloc(1);
		return (result);
	}
	total_len = ft_total_len(size, strs, sep);
	result = (char*) malloc(sizeof(char)*(total_len + 1));
	if (!result)
		return (0);
	ptr = result;
	i = 0;
	while (i < size)
	{
		ft_strcpy(ptr, strs[i]);
		ptr += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(ptr, sep);
			ptr += ft_strlen(sep);
		}
		i++;
	}
	ptr[i] = '\0';
	return (result);
}*/

#include <stdio.h>

int	main(void)
{
	char *strs[5];
	strs[0] = "bonjour";
	strs[1] = "ici";
	strs[2] = "c'est";
	strs[3] = "42";
	strs[4] = "!";

	printf("%s\n", ft_strjoin(5, strs, "**"));
}
