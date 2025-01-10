#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	if (end > start)
		size = end - start + 1;
	else
		size = start - end + 1;
	res = malloc(sizeof(int) * size);
	if (!res)
		return (0);
	i = 0;
	while (i < size)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	int	i;
	int	*range;

	i = 0;
	range = ft_range(-1, 3);
	while (i < 5)
	{
		printf("%d ", range[i]);
		i++;
	}
}*/
