#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int i;

	i = 'z';
	while (i >= 'a')
	{
		write(1, &i, 1);
		i --;
	}
}
/*
#include <stdio.h>
int main(void){
	ft_print_reverse_alphabet();
}*/
