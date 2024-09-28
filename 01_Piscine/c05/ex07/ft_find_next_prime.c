int	ft_find_prime(int nb)
{
	int i;
	
	i = 2;
	if (nb <= 1)
		return (1);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (ft_find_prime(nb) == 0)
		nb++;
	return (nb);	
}

#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_find_next_prime(5));
        printf("%d\n", ft_find_next_prime(24));
}
