unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	res_left;
	unsigned char	res_right;

	res_left = octet << 4;
	res_right = octet >> 4;
	return (res_left | res_right);	
}
/*
#include <stdio.h>
int	main()
{
	unsigned char 	c1 = 2;
	unsigned char 	c2 = 5;
	unsigned char 	c3 = 42;
	unsigned char 	c4 = 255;
	unsigned char 	c5 = 0;

	printf("%u\n", swap_bits(c1));
	printf("%u\n", swap_bits(c2));
	printf("%u\n", swap_bits(c3));
	printf("%u\n", swap_bits(c4));
	printf("%u\n", swap_bits(c5));
}*/
