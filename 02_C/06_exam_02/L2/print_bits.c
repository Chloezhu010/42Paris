#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		// right move i position, if LBS is 1 then print 1, else print 0 
		if (((octet >> i) & 1) == 1)
			ft_putchar('1');
		else
			ft_putchar('0');
		i--;
	}
}
/*
#include <stdio.h>
int	main()
{
	unsigned char 	c1 = 2;
	unsigned char 	c2 = 0;
	unsigned char 	c3 = 255;
	unsigned char 	c4 = 42;

	print_bits(c1);
	ft_putchar('\n');
	print_bits(c2);
	ft_putchar('\n');
	print_bits(c3);
	ft_putchar('\n');
	print_bits(c4);
	ft_putchar('\n');
}*/
