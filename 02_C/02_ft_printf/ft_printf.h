#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
// main function
int ft_printf(const char *format, ...)
// helper functions
int ft_print_char(int c);
int ft_print_string(char *str);
int ft_print_ptr(unsigned long ptr);
int ft_print_decimal(int n);
int ft_print_unsigned(unsigned int n);
int ft_print_hex(unsigned int n, int uppercase);
int ft_putnbr_base(unsigned long n, char *base);

#endif