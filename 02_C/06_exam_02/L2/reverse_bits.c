unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res;
	int	i;

	i = 7;
	while (i >= 0)
	{
		// shift the reversed byte << 1 and add the lsb of the origin byte
		res = (res << 1) | (octet & 1);
		// shift the original byte right by 1 to process the next bit
		octet = octet >> 1;
		i--;
	}
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	unsigned char 	c1 = 5;
	unsigned char 	c2 = 127;
	unsigned char 	c3 = 254;

	printf("5: %u\n", reverse_bits(c1));
	printf("0: %u\n", reverse_bits(c2));
	printf("254: %u\n", reverse_bits(c3));
	
}*/
