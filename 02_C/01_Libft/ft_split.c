/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:18:21 by czhu              #+#    #+#             */
/*   Updated: 2024/11/30 11:57:14 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_word(const char *s, char c)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] != c) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_freeup(char *s)
{
	while (*s)
	{
		free(s);
		s++;
	}
	free(s);
}

void	ft_putsplit(char **split, const char *s, char c)
{
	int	i;
	int	j;
	int	count_str;

	count_str = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			split[count_str] = malloc(sizeof(char) * (j + 1));
			if (split[count_str] == NULL)
				ft_freeup(split[count_str]);
			ft_strcpy(split[count_str], s + i, c);
			i = i + j;
			count_str++;
		}
	}
	split[count_str] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**res;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	res = (char **) malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	res[count] = 0;
	ft_putsplit(res, s, c);
	res[count] = NULL;
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	char s[] = " hello*world*!";
	char c = '*';
	char **split_str = ft_split(s, c);
	int count = count_word(s, c);
	char dest[] = "";

	printf("test count word: %d\n", count);
	printf("test strcpy: %s\n", ft_strcpy(dest, s, c));
	
	int i = 0;

	while (s[i] && i < count)
	{
		printf("result: %s\n", split_str[i]);
		i++;
	}
}*/
