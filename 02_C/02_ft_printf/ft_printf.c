#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int printed_chars;
    int i;

    va_start(args, format);
    printed_chars = 0;
    i = 0;

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if(format[i] == 'c')
                printed_chars += ft_print_char(va_arg(args, int));
            else if (format[i] == 's')
                printed_chars += ft_print_string(va_arg(args, char *))
            else if (format[i] == 'p')
                printed_chars += ft_print_ptr(va_arg(args, unsigned long));
            else if (format[i] == 'd' || format[i] = 'i')
                printed_chars += ft_print_decimal(va_arg(args, int));
            else if (format[i] == 'u')
                printed_chars += ft_print_unsigned(va_arg(args, unsigned int));
            else if (format[i] == 'x')
                printed_chars += ft_print_hex(va_arg(args, unsigned int), 0)
            else if (format[i] == 'X')
                printed_chars += ft_print_hex(va_arg(args, unsigned int), 1)
            else if (format[i] == '%')
                printed_chars += ft_print_char('%');
            else
            {
                printed_chars += ft_print_char('%');
                printed_chars += ft_print_char(format[i]);
            }
        }
        else
        {
            printed_chars += ft_print_char(format[i]);
        }
    }
    va_end(args);
    return (printed_chars);
}