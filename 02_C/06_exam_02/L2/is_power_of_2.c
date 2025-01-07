int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	else if (n == 1) // 2 with the power of 0
		return (1);
	while (n > 1)
	{
		if (n % 2 != 0)
			return (0);
		else
			n = n / 2;
	}
	return (1);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", is_power_of_2(32));
	printf("%d\n", is_power_of_2(1));
	printf("%d\n", is_power_of_2(48));
	printf("%d\n", is_power_of_2(2));
	printf("%d\n", is_power_of_2(0));
}*/
