/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:43:20 by czhu              #+#    #+#             */
/*   Updated: 2024/10/02 17:50:40 by czhu             ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(ptr) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	else
	{
		while (src[i])
		{
			ptr[i] = src[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
}
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char source[] = "42borntocode";

	char *test1 = strdup(source);
	char *test2 = ft_strdup(source);
	printf("%s:%s\n", test1, test2);

	printf("%s\n", strcmp(strdup("Test"), ft_strdup("Test")) == 0 ?
			"OK" :
			"Fail");
}*/
