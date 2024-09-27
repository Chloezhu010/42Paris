int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;
	
	result = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	i = 1;
	while (i < power)
	{
		result = result * nb;
		i++;
	}
	return (result);
	
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_power(2,4));
	printf("0:%d\n", ft_iterative_power(1, -10));
	printf("0:%d\n", ft_iterative_power(1, -1));
	printf("1:%d\n", ft_iterative_power(10, 0));
	printf("10:%d\n", ft_iterative_power(10, 1));
	printf("100:%d\n", ft_iterative_power(10, 2));
	printf("216:%d\n", ft_iterative_power(6, 3));	
}
