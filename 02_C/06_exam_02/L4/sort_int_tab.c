void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int 	i;
	unsigned int	j;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}	
}
/*
#include <stdio.h>

int	main()
{
	int	tab[] = {78, 4, 7, 1, 9, 9, 10};
	unsigned int	size = 7;

	int	i = 0;
	while (i < 7)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n after sort int\n");
	sort_int_tab(tab, size);
	i = 0;
	while (i < 7)
	{
		printf("%d ", tab[i]);
		i++;
	}
}*/
