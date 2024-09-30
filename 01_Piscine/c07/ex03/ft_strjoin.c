int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	sep_len;
	int	i;
	
	total_len = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		total_len = total_len + strs[i];
		if (i < size - 1)
			total_len = total_len + sep_len;
		i++;
	}
	return (total_len);
}

char	*ft_malloc(int size)
{
	char	*str;

	if (size == 0)
	{
		str = malloc(1);
		str[0] = '\0'		
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int	total_len;
	int	i;
	int	j;
	int	k;

	if (size == 0)
	
}

#include <stdio.h>
int	main(int argc, **argv)
{
	printf("%s\n", ft_strjoin(argc, argv, "*")
}
