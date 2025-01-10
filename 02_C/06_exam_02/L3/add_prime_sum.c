#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

int	check_prime(int n)
{
	int	i;
	
	if (n < 2)
		return (0);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	// only need to consider the positive int
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	main(int ac, char **av)
{
	int	nb;
	int	i;
	int	sum;
	
	i = 0;
	sum = 0;
	if (ac == 2)
	{
		nb = ft_atoi(av[1]);
		if (nb > 0)
		{
			while (i <= nb) // incl. the nb itself
			{
				if (check_prime(i))
					sum += i;
				i++;
			}
			ft_putnbr(sum);
			ft_putchar('\n');
		}
		else
			write(1, "0\n", 2);
	}
	else
		write(1, "0\n", 2);
}
