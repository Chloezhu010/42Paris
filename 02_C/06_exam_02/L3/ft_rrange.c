#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	size;
	int	*res;
	int	i;

	if (start < end)
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
			res[i] = end;
			end--;
			i++;
		}
		else
		{
			res[i] = end;
			end++;
			i++;
		}
	}
	return (res);
}

#include <stdio.h>
int	main()
{
	int	i;
	int	*rrange;

	rrange = ft_rrange(0, 0);
	i = 0;
	while (i < 4)
	{
		printf("%d ", rrange[i]);
		i++;
	}
}
