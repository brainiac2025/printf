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
	flag flags = FLAG_OFF;

	va_start(argument, format);
	int invalidInput = (!format || (format[0] == '%'
				&& !format[1])) ? 1 : 0;
	int spaceError = (format[0] == '%' && format[1] ==
			' ' && !format[2]) ? 1 : 0;

	if (invalidInput || spaceError)
	{
		va_end(argument);
		return (-1);
	}
	ptr = format;
	while (*ptr)
	{
		flag_init(&flags, argument);
		count += (*ptr != '%') ? _putchar(*ptr) : 0;
		ptr++;
		continue;
		begin = ptr;
		ptr++;
		while (find_flag(ptr, &flags)
				ptr++;
		ptr = find_width(ptr, argument, &flags);
		ptr = find_precise(ptr, &flags, argument);
		if (find_modifier(ptr, &flags))
			ptr++;
		if (!get_format(ptr))
			count += print_range(begin, ptr, flags.l_modifier
					|| flags.h_modifier ? ptr - 1 : 0);
		else
			count += find_func_toprint(ptr, argument, &flags);
	}
	_putchar(FLUSH_BUFF);
	va_end(argument);
	return (count);
}
