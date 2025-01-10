int	is_space(char c)
{
	if ((c >= 9 && c <= 13 ) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1; // initialize with 1, assuming the nbr is positive by default
	// skip through space
	while (str[i] && is_space(str[i]) == 1)
		i++;
	// only handle 1 sign, if '-' then sign = -1
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// process the digits
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	char	*str1 = "\n 42abc";
	char	*str2 = "++--42";
	char	*str3 = "2147483647";
	char	*str4 = "-2147483648";
	char	*str5 = "0";
	char	*str6 = "1000";

	printf("%d: %d\n", ft_atoi(str1), atoi(str1));
	printf("%d: %d\n", ft_atoi(str2), atoi(str2));
	printf("%d: %d\n", ft_atoi(str3), atoi(str3));
	printf("%d: %d\n", ft_atoi(str4), atoi(str4));
	printf("%d: %d\n", ft_atoi(str5), atoi(str5));
	printf("%d: %d\n", ft_atoi(str6), atoi(str6));

	printf("%d\n", atoi(str1));
}*/
