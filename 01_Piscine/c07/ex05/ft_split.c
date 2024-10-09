/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:00:03 by czhu              #+#    #+#             */
/*   Updated: 2024/10/07 17:55:55 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (str[i])
	{
		if (is_separator(str[i], charset) == 1 && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_separator(str[i], charset) == 0)
			in_word = 0;
		i++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (src[i] && is_separator(src[i], charset) == 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putsplit(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	countstr;

	countstr = 0;
	i = 0;
	while (str[i])
	{
		if (is_separator(str[i], charset) == 0)
			i++;
		else
		{
			j = 0;
			while (is_separator(str[i + j], charset) == 1)
				j++;
			split[countstr] = malloc(sizeof(char) * (j + 1));
			ft_strcpy(split[countstr], str + i, charset);
			i = i + j;
			countstr++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int	wordcount;
	char		**res;

	wordcount = count_word(str, charset);
	res = (char **) malloc(sizeof(char *) * (wordcount + 1));
	if (!res)
		return (NULL);
	res[wordcount] = 0;
	ft_putsplit(res, str, charset);
	return (res);
}
/*
#include <stdio.h>
int	main(void)
{
	int i = 0;
	char *str = "this*is*42*coding*school;test";
	char *charset = "*&";
	
	char **split_str = ft_split(str, charset);
	int countword = count_word(str, charset);
	while (i < countword && str[i] != 0)
	{
		printf("%s\n", split_str[i]);
		i++;
	}
}*/
