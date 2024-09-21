void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int temp;
	
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;	
			}
		j++;
		}
	i++;
	}	
}

#include <stdio.h>

int	main(void)
{
	int i = 0;
	int test[5] = {5,4,2,3,1};

	ft_sort_int_tab(test, 5);
	
	while (i < 5)
	{
		printf("%d",test[i]);
		i++;
	}
}
