int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	if (!str)
		return (0) ;
	while (i < (len - 1)/2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_strrev(av[1]));
	else
		printf("need input\n");
}*/
