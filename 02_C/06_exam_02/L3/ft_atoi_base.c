int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	res;
	int	value;

	i = 0;
	sign = 1;
	res = 0;
	value = -1;
	// check input
	if (!str[i] || str_base < 2 || str_base > 16)
		return (0);
	// manage + -
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	// change str to int
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			value = 10 + str[i] - 'a';
		else if (str[i] >= 'A' && str[i] <= 'F')
			value = 10 + str[i] - 'A';
		if (value == -1 || value >= str_base)
			break;
		res = res * str_base + value;
		i++;
	}
	return (res * sign);	
}
/*
#include <stdio.h>

int	main()
{
	printf("%d\n", ft_atoi_base("", 16));
	printf("%d\n", ft_atoi_base("42", 10));
	printf("%d\n", ft_atoi_base("1001", 2));
	printf("%d\n", ft_atoi_base("2a", 0));
}*/
