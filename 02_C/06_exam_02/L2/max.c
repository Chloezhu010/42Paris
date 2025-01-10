int	max(int* tab, unsigned int len)
{
	int	i;
	int	max;

	i = 0;
	max = tab[i];
	// handle edge case
	if (len == 0)
		return (0);
	// loop through the array to find max
	while (i < (int)len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
/*
#include <stdio.h>

int	main()
{
	int	nbr[] = {1,2,2147483647};
	unsigned int	len = 3;
	printf("max: %d\n", max(nbr, len));
}*/
