void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>

int main(void){
	int a, b;
	int div, mod;

	a = 10;
	b = 3;
	
	ft_div_mod(a, b, &div, &mod);
	printf("a: %d, b: %d, div: %d, mod: %d", a, b, div, mod);
}*/
