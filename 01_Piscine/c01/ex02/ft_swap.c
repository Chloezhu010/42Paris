void	ft_swap(int *a, int *b)
{
	int c;

	c = *a; //c now holds the value of a
	*a = *b; //a now holds the value of b
	*b = c; //b now holds the value of c, aka a
}
/*
#include <stdio.h>

int main(void){
	int a, b;
	int *ptra, *ptrb;
	
	a = 4;
	b = 2;

	ptra = &a;
	ptrb = &b;
	
	printf("before ab:%d%d\n", a, b);
	ft_swap(ptra, ptrb);
	printf("after ab:%d%d\n", a, b);
}*/
