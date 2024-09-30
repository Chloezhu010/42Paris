#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	result = malloc(sizeof(int)*(max - min));
	if (result == NULL)
	{
		*range = NULL;
		return (-1);
	}
	else
	{
		i = 0;
		while (min < max)
		{
			result[i] = min;
			min++;
			i++;
		}
		*range = result;
		return (i);
	}
}

#include <stdio.h>
int	main(void)
{
	int *range;
	
	printf("5:%d\n", ft_ultimate_range(&range, 0, 5));
	printf("0, 1, 2, 3, 4 : %d, %d, %d, %d, %d\n", range[0], range[1], range[2], range[3], range[4]);
	
	printf("0:%d\n", ft_ultimate_range(&range, 3, 3));
	
	printf("2:%d\n", ft_ultimate_range(&range, -1, 1));
	printf("-1, 0\n: %d, %d", range[0], range[1]);
}
