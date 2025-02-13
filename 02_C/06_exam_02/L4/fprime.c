#include <stdio.h>
#include <stdlib.h>

void	fprime(int nb)
{
	int	i;
	
	if (nb < 1)
		return;
	if (nb == 1)
		printf("1");
	i = 2;
	// loop through to find the prime factor
	while (i * i <= nb)
	{
		// inner loop div by the current prime factor
		while (nb % i == 0)
		{
			printf("%d", i);
			nb = nb / i;
			//if (nb > 1)
				printf("*");
		}
		i++;
	}
	// handle the last prime factor
	if (nb > 1)
		printf("%d", nb);
}

int	main(int ac, char **av)
{
	int	nb;

	if (ac == 2)
	{
		nb = atoi(av[1]);
		fprime(nb);	
	}
	printf("\n");
}
