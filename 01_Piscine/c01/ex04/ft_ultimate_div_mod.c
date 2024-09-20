void	ft_ultimate_div_mod(int *a, int *b)
{
	int div, mod;
	
	div = *a;
	mod = *b;
	
	*a = div / mod;
	*b = div % mod;
}
/*
#include <stdio.h>

int main(void){
	int a, b;

	a = 10;
	b = 3;

	printf("before a: %d, b: %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("after a: %d, b: %d", a, b);
}*/
