#include "main.h"

/**
 * _printf - function to simulate printf functionality
 * @format: formatted string
 * Return: number of character printed
 */
int _printf(const char *format, ...)
{
	int i, j;
	va_list argument;
	char specifier;

	format_mapping *format_map = get_format_map();
	va_start(argument, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				display('%');
				i++;
			}
			else
			{
				specifier = format[i + 1];
				j = 0;

				while (format_map[j].format != 0)
				{
					if (format_map[j].format == specifier)
					{
						format_map[j].print_format(argument);
						break;
					}
					j++;
				}
				i++;
			}
		}
		else
		{
			display(format[i]);
		}
	}
	va_end(argument);
	return (i);
}
