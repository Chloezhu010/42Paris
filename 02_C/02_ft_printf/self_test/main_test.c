#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	// test %c
	printf("\n Test on char\n");
	printf("Testing individual chars:\n");
    ft_printf("First char: %c\n", 'A');
    ft_printf("Second char: %c\n", '1');
    ft_printf("Third char: %c\n", '*');
	printf("original: %c: %c: %c\n", 'A', '1', '*');
	ft_printf("my: %c: %c: %c", 'A', '1', '*');
	printf("%c\n",'\0');
	ft_printf("%c\n",'\0');

	// test %s
	printf("\n Test on string\n");
	printf("hello %s, today is %s\n", "chloe", "your birthday");
	ft_printf("hello %s, today is %s\n", "chloe", "your birthday");
	printf("null case: %s\n", (char *)NULL);
	ft_printf("null case: %s\n", (char *)NULL);

	// test %d, %i
	printf("\n Test on digits\n");
	printf("hello %d, today is Dec %d th \n", 42, 8);
	ft_printf("hello %d, today is Dec %d th\n", 42, 8);
	printf("hello %i, today is Dec %i th\n", INT32_MAX, INT32_MIN);
	ft_printf("hello %i, today is Dec %i th\n", INT32_MAX, INT32_MIN);
	
	// test %u
	printf("\n Test on unsigned int\n");
	printf("hello %u, today is Dec %u th \n", 0, UINT_MAX);
	ft_printf("hello %u, today is Dec %u th\n", 0, UINT_MAX);

	// test %x or X
	printf("\n Test on hex\n");
	printf("hello %x, it's %X \n", 0, UINT_MAX);
	ft_printf("hello %x, it's %X \n", 0, UINT_MAX);
	printf("hello %x, it's %X \n", -1, 42);
	ft_printf("hello %x, it's %X \n", -1, 42);

	// test %p
	printf("\n Test on pointer\n");
	int	num = 42;
	char str[] = "hello world";
	void *ptr1 = &num;
	void *ptr2 = str;
	void *ptr3 = NULL;
	printf("hello %p\n", ptr1);
	ft_printf("hello %p\n", ptr1);
	printf("hello %p\n", ptr2);
	ft_printf("hello %p\n", ptr2);
	printf("hello %p\n", ptr3);
	ft_printf("hello %p\n", ptr3);

	// test combination
	printf("\n Test on combination\n");
	printf("hello %s, today is Dec %d th, tmr is Dec %i th, only %u days left. The address is %x and %X\n", 
		"chloe", 8, 9, 23, 42, 42);
	ft_printf("hello %s, today is Dec %d th, tmr is Dec %i th, only %u days left. The address is %x and %X\n", 
		"chloe", 8, 9, 23, 42, 42);
}
