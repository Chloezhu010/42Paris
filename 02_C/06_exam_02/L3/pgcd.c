#include <stdio.h>
#include <stdlib.h>

unsigned int	pgcd(unsigned int a, unsigned int b)
{
	unsigned int	min;
	unsigned int	max;
	unsigned int	temp;

	if (a < b)
	{
		min = a;
		max = b;
	}
	else
	{
		min = b;
		max = a;
	}
	while (min != 0)
	{
		temp = min;
		min = max % min;
		max = temp;
	}
	return (max);
}

int	main(int ac, char **av)
{
	unsigned int	n1;
	unsigned int	n2;
	unsigned int	res;
	
	if (ac == 3)
	{
		n1 = atoi(av[1]);
		n2 = atoi(av[2]);
		if (n1 > 0 && n2 > 0)
		{
			res = pgcd(n1, n2);
			printf("%u", res);
		}
		else
			printf("\n");
	}
	printf("\n");
}
