unsigned int	hcf(unsigned int a, unsigned int b)
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

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	res;
	
	if (a == 0 || b == 0)
		return (0);
	res = a * b / hcf(a, b);
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	printf("lcm: %u\n", lcm(9, 15));
	printf("lcm: %u\n", lcm(0, 15));
	printf("lcm: %u\n", lcm(9, 0));
	printf("lcm: %u\n", lcm(48, 18));
}*/
