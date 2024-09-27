int	ft_iterative_factorial(int nb)
{
	int	result;

	result = nb;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	while (nb - 1 != 0)
	{
		result = result * (nb - 1);
		nb --;
	}
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("0:%d\n", ft_iterative_factorial(-10));
	printf("0:%d\n", ft_iterative_factorial(-1));
	printf("1:%d\n", ft_iterative_factorial(0));
	printf("1:%d\n", ft_iterative_factorial(1));
	printf("3628800:%d\n", ft_iterative_factorial(10));
	printf("6:%d\n", ft_iterative_factorial(3));
}*/