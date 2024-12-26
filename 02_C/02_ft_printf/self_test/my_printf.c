#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_string(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		print_char((int) *str);
		++count;
		++str;
	}
	return (count);
}

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

int	print_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(ap, int));
	else if (spec == 's')
		count += print_string(va_arg(ap, char *));
	else if (spec == 'd' || spec == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (spec == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	else
		count += write(1, &spec, 1);
	return (count);
}

int	my_printf(const char *format, ...)
{
	va_list	ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

int	main()
{
	int	count, count2, count3;

	count = my_printf("hello %d\n", INT32_MIN);
	my_printf("the chars written are %d\n", count);
	printf("the chars written are %d\n", count);
	count2 = my_printf("%x\n", INT32_MIN);
	my_printf("the chars written are %d\n", count2);
	printf("the chars written are %d\n", count2);

	count3 = my_printf("hello %s, today is %d, in hex %x, char -> %c\n", 
			"Chloe", 27, 27, 'a');
	my_printf("the chars written are %d\n", count3);
	printf("the chars written are %d\n", count3);
}
