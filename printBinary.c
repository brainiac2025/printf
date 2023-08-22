#include "main.h"

/**
 * print_binary - function to printbinary
 * @argument: decimal number pass
 * @flags: flag specifier
 * Return: void
 */
int print_binary(va_list argument, flag *flags)
{

	unsigned int num = va_arg(argument, unsigned int);
	int count = 0;
	char *str = to_base(num, 2, CHANGE_UNSIGNED, flags);

	if (flags->hash && num)
	{
		*--str = '0';
	}

	flags->unsign = 1;
	return (count += display_number(str, flags));
}

