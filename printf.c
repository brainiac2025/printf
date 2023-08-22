#include "main.h"

/**
 * _printf - function to simulate printf functionality
 * @format: formatted string
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list argument;
	char *begin, *ptr;
	flag flag = FLAG_OFF;

	va_start(argument, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (ptr = (char *)format; *ptr;  ptr++)
	{
		flag_init(&flag, argument);
		if (*ptr != '%')
		{
			count = count + _putchar(*ptr);
			continue;
		}
		begin = ptr;
		ptr++;
		while (find_flag(ptr, &flag))
		{
			ptr++;
		}
		ptr = find_width(ptr, argument, &flag);
		ptr = find_precise(ptr, &flag, argument);

		if (find_modifier(ptr, &flag))
			ptr++;
		if (!get_format(ptr))
			count += print_range(begin, ptr, flag.l_modifier
					|| flag.h_modifier ? ptr - 1 : 0);
		else
			count += find_func_toprint(ptr, argument, &flag);
	}
	_putchar(FLUSH_BUFF);
	va_end(argument);
	return (count);
}
